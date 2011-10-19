/*
 * main.c
 *
 * Created: 2011.09.16. 23:40:39
 *  Author: libesz
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <string.h>
#include "lcd.h"
#include "serial.h"
#include "3310lcd_init.h"
#include "splash.h"
void draw_splash( void );

#define STR_TO_MOVE " hello "

#define X_MAX 84
#define Y_MAX 40

#define INPUT_FROM_USART 0

volatile unsigned int usart_rec_buf_index = 0;
volatile unsigned char rec_ok = 0;
ISR(USART_RX_vect)
{
   unsigned char usart_rec_byte=UDR0;
   STATUSLED_TOGGLE = 1;
   if( !usart_rec_buf_index && !rec_ok )
   {
	   if( usart_rec_byte == 0x55 ) //sync byte, the GUI always starts with this
	   {
		   rec_ok = 1;
	   }
		return;
   }
   lcd_set_byte_in_buffer( usart_rec_buf_index++, usart_rec_byte );
   if( usart_rec_buf_index == LCD_CACHE_SIZE )
   {
	   lcd_update_from_buffer();
	   usart_rec_buf_index = 0;
	   rec_ok = 0;
   }
   serial_putc(usart_rec_byte);
}

int main(void)
{
	unsigned char x_offset = 0, y_offset = 0, x_dir = 1, y_dir = 1;
#include "3310lcd_init.c"
   sei();
	//serial_puts( STR_TO_MOVE );
	// Setup LCD
	lcd_init();
	lcd_contrast(0x2d);
	
	while(1)
	{
		if( INPUT_SWITCH == INPUT_FROM_USART )
		{
			UCSR0B |= 1<<RXCIE0;
		}
		else
		{
			UCSR0B &= ~(1<<RXCIE0);
			
	      /* Example 1 */
         draw_splash();
	   
         /* Example 2 */
         /* lcd_clear_buffer();
         for( unsigned char q = 24; q ; q-- )
         {
            if( q % 2 )
            {
               lcd_clear_area_buffer( 24-q, 24-q, 83-(24-q), 47-(24-q));
            }
            else
	         {
		         lcd_set_area_buffer( 24-q, 24-q, 83-(24-q), 47-(24-q));
			 }	         
         }*/
	      
         /* Example 3 */
         /* lcd_clear_buffer();
	      for( unsigned char q = 0; q < 48; q+=2 )
         {
            lcd_set_area_buffer( 0, q, 83, q);
	      }	 	  
	      for( unsigned char q = 0; q < 84; q+=2 )
         {
            lcd_set_area_buffer( q, 0, q, 47);
	      }
         */

         lcd_goto_xy_buffer( x_offset, y_offset );
	      if( x_dir )
	      {
		      if( x_offset < ( X_MAX - ( strlen( STR_TO_MOVE ) * 6 ) ) )
		      {
			      x_offset++;
			      x_offset++;
		      }
		      else
		      {
			      x_dir = 0;
		      }
	      }
	      else
	      {
		      if( x_offset )
		      {
			      x_offset--;
			      x_offset--;
		      }
		      else
		      {
			      x_dir = 1;
		      }
	      }
	      if( y_dir )
	      {
		      if( y_offset < Y_MAX )
		      {
			      y_offset++;
		      }
		      else
		      {
			      y_dir = 0;
		      }
	      }
	      else
	      {
		      if( y_offset )
		      {
			      y_offset--;
		      }
		      else
		      {
			      y_dir = 1;
		      }
	      }
	   
	      lcd_str_buffer( STR_TO_MOVE );
	   
         lcd_update_from_buffer();
	      _delay_ms(100);
		}
   }   
}

/* draws a fullscreen frame to the buffer, made by the GUI */
void draw_splash( void )
{
	for( unsigned int buffer_index = 0; buffer_index < LCD_CACHE_SIZE; buffer_index++ )
	{
		lcd_set_byte_in_buffer( buffer_index, pgm_read_byte( &splash[ buffer_index ] ) );
	}   	
}
