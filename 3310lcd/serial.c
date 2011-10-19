#include "serial.h"


void serial_putc(unsigned char c) 
{
   // wait until UDR ready
	while(!(UCSR0A & (1 << UDRE0)))
    ;
	UDR0 = c;    // send character
}

void serial_puts (char *s) 
{
  while (*s) {
		serial_putc(*s);
		s++;
	}
}

void serial_puti( const int val )
{
    char buffer[sizeof(int)*8+1];
    
    serial_puts( itoa(val, buffer, 10) );

}
