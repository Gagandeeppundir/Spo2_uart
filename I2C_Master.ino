#include<avr/io.h>
#include<util/delay.h>
void I2C_Init(void);
void I2C_start(void);
void I2C_address(unsigned char address, char direct);
void I2C_write(unsigned char data);
void I2C_string_write(unsigned char str[]);
void I2C_stop(void);
void setup()
{
  Serial.begin(9600);
  I2C_Init();
}

void loop()
{
   I2C_address(0x08,0);
   I2C_write('C');
   I2C_stop();
   _delay_ms(500);
   I2C_address(0x40,0);
   I2C_string_write("AB");
   I2C_stop();
   _delay_ms(500);
}
 void I2C_Init(void)
 {
   TWBR = 72;
   TWSR = 0x00;
  }
 void I2C_start(void)
 {
   TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
   while(!(TWCR & (1<<TWINT)));
 }
 void I2C_address(unsigned char address, char direct)
 {
   TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
   while(!(TWCR & (1<<TWINT)));
   TWDR = (address<<1)|(direct<<0); 
   TWCR = (1<<TWINT)|(1<<TWEN);
   while(!(TWCR & (1<<TWINT)));
   Serial.println("address sent");
 }
 void I2C_write(unsigned char data)
 {
   TWDR = data;
   TWCR = (1<<TWINT)|(1<<TWEN);
   while(!(TWCR & (1<<TWINT)));
  }

  void I2C_string_write(unsigned char str[])
  {
    int i=0;
    while(str[i]!=0)
    {
      I2C_write(str[i]);
       TWCR = (1<<TWINT)|(1<<TWEN);
       while(!(TWCR & (1<<TWINT)));
      i++;
      }
     
    }
  void I2C_stop(void)
  {
    TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
    while(!(TWCR & (1<<TWSTO)));
    Serial.println("Stop");
    }
