//#include<SoftwareSerial.h>
// SoftwareSerial mySerial(2,3); // RX,TX
#include<avr/io.h>
#include<avr/interrupt.h>
#define RX_buffer_size 10
#define ubrr 207
int rx_buffer[RX_buffer_size];
int rx_count = 0; int rx_read_pos = 0;
void uart_send(unsigned char c);
void uart_string(char *str);
int uart_read_count(void);
int uart_read(void);
unsigned char rxd_data = 0;
void setup()
{
  // put your setup code here, to run once:
  //Serial.begin(9600);
  // UBRR0 = 103; // 9600
  UBRR0H = ubrr>>8; // 4800 baudrate
  UBRR0L = ubrr;
  UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
  UCSR0C |= (1 << UPM01) | (1 << UPM00); // Use 8 bit data & odd parity
  UCSR0B |= (1 << TXEN0) | (1 << RXEN0); // enable transmitter and receiver
  UCSR0B |= (1 << RXCIE0); // Enable the usart receive interrupt
  sei(); // enable global interrupt

}

void loop()
{
  // put your main code here, to run repeatedly:

   
    rxd_data = uart_read();
  /*  if(rxd_data>=128)
    {
       rxd_data = rxd_data - 128;
      }*/
 //   d = d-0x30;
  //  String a = String(int(rxd_data));
   // uart_string(a.c_str());
   // uart_send('\n');
    if(rxd_data & 0x80)           
    {  
       String bp = String(int(rx_buffer[rx_read_pos+0]));
//       uart_string("BP : ");
       uart_string(bp.c_str());
       uart_send('\n');
       String sp = String(int(rx_buffer[rx_read_pos+3]));
//       uart_string("SPO2 : ");
//       uart_string(sp.c_str());
//       uart_send(',');
       String hr = String(int(rx_buffer[rx_read_pos+2])); 
 //      uart_string("  Heratbeat : ");
//       uart_string(hr.c_str());
//       uart_send('\n');
       
      }
     
    //delay(500);
}

ISR(USART_RX_vect)
{
  rx_buffer[rx_count] = UDR0;
  rx_count++;
  if (rx_count >= RX_buffer_size)
  {
    rx_count = 0;
  }
}

int uart_read_count(void)
{
  return rx_count;
}

int uart_read(void)
{

  int data = 0;
  data = rx_buffer[rx_read_pos];
  rx_read_pos++;
  //rx_count--;
  if (rx_read_pos >= RX_buffer_size)
  {
    rx_read_pos = 0;
  }
  return data;
}

void uart_send(unsigned char c)
{
  while ((UCSR0A & (1 << UDRE0)) == 0);
  UDR0 = c;
}

void uart_string(char *str) // char str[]
{
  int i = 0;
  while (str[i] != '\0')
  {
    uart_send(str[i]);
    i++;
  }
}
