#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
int data[5],i=0;
int rx_index=0;
void setup() 
{
                // put your setup code here, to run once:
 Serial.begin(9600);
 DDRC = 0x01;               
 spi_int();
 sei();
}

void loop() 
{
                // put your main code here, to run repeatedly:
             
   Serial.println(data[0]);
   Serial.println(data[1]);
   Serial.println(data[2]);
   Serial.println(data[3]);
   Serial.println(data[4]);
       
  if(data[0]=='H' && data[1]=='E' && data[2]=='L' && data[3]=='L' && data[4]=='O')
  
  {              
    PORTC |= (1<<0);              
  }
  else
  {
    PORTC &= ~(1<<0);
    }
}

void spi_int(void)
{
   DDRB |= (1<<PB4);
   SPCR |= (1<<SPE)|(1<<SPR0); // SPE enable
   SPCR |= (1<<SPIE); // enable interrupt enable
 }

 ISR(SPI_STC_vect)
{
   
  while((SPCR & (1<<SPIF))==0);
  data[rx_index] = SPDR;
  if(rx_index>4)
  {
    rx_index=0;
    } 
    else
    {
      rx_index++;
      }
   }  
  /* for(i=0;i<6;i++)
  { 
   while(!(SPSR&(1<<SPIF)));
   data[i] = SPDR; 
  } */
  
