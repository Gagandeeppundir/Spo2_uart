#include<avr/io.h>
#include<util/delay.h>
#include<stdio.h>
void I2C_slave_init(void);
uint8_t I2C_slave_Listen();
unsigned char rec;
unsigned int case_read;
unsigned char count=0;
void setup()
{
  
  Serial.begin(9600);  
  I2C_slave_init();
 
}

void loop()
{
   
   I2C_slave_init(); 
   case_read = I2C_slave_Listen();
    //Serial.println(case_read);
   switch(case_read)
   {
    case 0:
        {
         do
         {
           count = I2C_Slave_Receive();
           Serial.print("Data: ");
           Serial.println(count);
          }
          while(count != -1);
          count = 0;
          break;  
          }
    }
   
}

  void I2C_slave_init(void)
  {

  TWAR = (0x08)<<1;            /* Assign address in TWI address register */
  TWCR = (1<<TWEN) | (1<<TWEA) | (1<<TWINT);
     
  }


  uint8_t I2C_slave_Listen()
  {
    while(1)
    {
      uint8_t status;              /* Declare variable */
    while (!(TWCR & (1<<TWINT)));     /* Wait to be addressed */
    status = TWSR & 0xF8;         /* Read TWI status register with masking lower three bits */
 
    if (status == 0x60 || status == 0x68) /* Check weather own SLA+W received & ack returned (TWEA = 1) */
    return 0;               /* If yes then return 0 to indicate ack returned */
    if (status == 0xA8 || status == 0xB0) /* Check weather own SLA+R received & ack returned (TWEA = 1) */
    return 1;               /* If yes then return 1 to indicate ack returned */
    if (status == 0x70 || status == 0x78) /* Check weather general call received & ack returned (TWEA = 1) */
    return 2;               /* If yes then return 2 to indicate ack returned */
    else
    continue;               /* Else continue */
    }
    
  }


char I2C_Slave_Receive()
{
  uint8_t status;               /* Declare variable */
  TWCR=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);    /* Enable TWI, generation of ack and clear interrupt flag */
  while (!(TWCR & (1<<TWINT)));       /* Wait until TWI finish its current job (read operation) */
  status = TWSR & 0xF8;           /* Read TWI status register with masking lower three bits */
  if (status == 0x80 || status == 0x90)   /* Check weather data received & ack returned (TWEA = 1) */
  return TWDR;                /* If yes then return received data */
  if (status == 0x88 || status == 0x98)   /* Check weather data received, nack returned and switched to not addressed slave mode */
  return TWDR;                /* If yes then return received data */
  if (status == 0xA0)             /* Check weather STOP/REPEATED START received */
  {
    TWCR |= (1<<TWINT);           /* If yes then clear interrupt flag & return 0 */
    return -1;
  }
  else
  return -2;                  /* Else return 1 */
}
  
