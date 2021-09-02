#include<avr/io.h>
#include<util/delay.h>
void I2C_slave_init(void);
void I2C_addr(unsigned char address, bool Dir);
void I2C_address(unsigned char address);
unsigned int case_read;
unsigned char count[2];
void setup() 
{
  Serial.begin(9600);
  I2C_slave_init();
  
}

void loop() 
{
    I2C_addr(0x08,1);
   // I2C_address(0x08);
    case_read = I2C_slave_Ack();   
    //Serial.println(case_read);
   /* if(case_read==0)
    { 
       count = I2C_read();
       Serial.println(count);
      }*/
    switch(case_read)
    {
       case 0:
       {
         Serial.println("Data");
         do
         {
          
           count[0] = I2C_read();
           count[1] = I2C_read();
           count[2] = I2C_read();
           Serial.print("Bit 0: ");
           Serial.println(count[0]);
//           Serial.print("Bit 1: ");
//           Serial.println(count[1]);
//           Serial.print("Bit 2: ");
//           Serial.println(count[2]);
 
          }
          while(count != -1);
          //count = 0;
            break; 
        }
      }   
}

  void I2C_slave_init(void)
  {
    TWBR = 0x72;
    TWSR |= 0x00;
    }
    
  void I2C_addr(unsigned char address, bool Dir)
  {
    TWAR = (address<<1)|(Dir<<0);
    TWCR = (1<<TWEN)|(1<<TWEA)|(1<<TWINT);
    }  
    
  void I2C_address(unsigned char address)
  {
    TWAR = address<<1;
    TWCR = (1<<TWEN)|(1<<TWEA)|(1<<TWINT);
    }      

  uint8_t I2C_slave_Ack()
  {
    while(1)
    {
     uint8_t status;
     while(!(TWCR & (1<<TWINT)));
     status = TWSR & 0xF8;
     if(status == 0x60 || status == 0x68) 
     return 0;
     if(status == 0xA8 || status == 0xB0)
     return 1;
     if(status == 0x70 || status == 0x78)
     return 2;
     else
     continue;
    }
   }
    
  char I2C_read()
   {
      uint8_t status;
      TWCR = (1<<TWEN)|(1<<TWEA)|(1<<TWINT);
      while(!(TWCR & (1<<TWINT)));
      status = TWSR & 0xF8;
      if(status == 0x80 || status == 0x90)
      return TWDR;
      if(status == 0x88 || status == 0x98)
      return TWDR;
      if (status == 0xA0)             // Check weather STOP/REPEATED START received 
  {
    TWCR |= (1<<TWINT);           // If yes then clear interrupt flag & return 0 
    return -1;
  }
  else
  return -2; 
    } 
