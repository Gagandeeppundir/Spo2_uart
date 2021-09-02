#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
void setup()
{
                       // put your setup code here, to run once:
  Serial.begin(9600);                     
  spi_int();
}

void loop()
{
                      // put your main code here, to run repeatedly:
  //spi_send(1);
 // Serial.println(49);
  spi_string("HELLO");
 
}

 void spi_int(void)
{
    DDRB = (1<<PB3)|(1<<PB5)|(1<<PB2); // 
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0); //fck/16
  }
 
 void spi_send(char data)
{
    PORTB &= ~(1<<PB2);
    SPDR = data; // send the data on SPDR reg
    while(!(SPSR & (1<<SPIF))); // Wait for until the transmission is complete
    PORTB |= (1<<PB2);
 }

 void spi_string(char str[])
 {
   int i;
   while(str[i]!=0)
  {
    spi_send(str[i]);
      i++;
    } 
  }      
