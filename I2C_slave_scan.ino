#include<avr/io.h>
#include<util/delay.h>
void I2C_slave_init(void);
void I2C_slave_addr(unsigned char address);
void setup() 
{
  Serial.begin(9600);  
  I2C_slave_init();
}

void loop() 
{
  I2C_slave_addr(0x08);

}

  void I2C_slave_init(void)
  {
     TWBR = 0x0C;
     TWSR |=0x00;
    }

  void I2C_slave_addr(unsigned char address)
  {
     TWAR = address<<1;
     TWCR = (1<<TWEN)|(1<<TWEA)|(1<<TWINT);
     while(!(TWCR & (1<<TWINT)));
    } 
