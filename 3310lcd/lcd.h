/*
** lcd.h
**
** LCD 3310 driver
** Target: ATMEGA :: AVR-GCC
**
** Written by Tony Myatt - 2007
** Quantum Torque - www.quantumtorque.com
*/
#ifndef _NOKIALCD_H_
#define _NOKIALCD_H_

/* Lcd screen size */
#define LCD_X_RES 84
#define LCD_Y_RES 48
#define LCD_CACHE_SIZE ((LCD_X_RES * LCD_Y_RES) / 8)

/* Pinout for LCD */
#define LCD_CLK_PIN 	(1<<PC4)
#define LCD_DATA_PIN 	(1<<PC3)
#define LCD_DC_PIN 		(1<<PC2)
#define LCD_CE_PIN 		(1<<PC1)
#define LCD_RST_PIN 	(1<<PC0)
#define LCD_PORT		PORTC
#define LCD_DDR			DDRC

/* Special Chars */
#define ARROW_RIGHT	ICON(0)
#define ARROW_LEFT 	ICON(1)
#define ARROW_UP 	ICON(2)
#define ARROW_DOWN 	ICON(3)
#define STOP 		ICON(4)
#define PLAY	 	ICON(5)

/* Function for my special characters */
#define	ICON(x)		'z'+1+x

void lcd_set_pixel_in_buffer( unsigned char x, unsigned char y );
void lcd_set_byte_in_buffer( unsigned int index, unsigned char value );
void lcd_clear_pixel_in_buffer( unsigned char x, unsigned char y );
void lcd_update_from_buffer( void );
void lcd_goto_xy_buffer(unsigned char x, unsigned char line);
void lcd_clear_area_buffer(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2);
void lcd_set_area_buffer(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2);
void lcd_chr_buffer(char chr);
void lcd_str_buffer(char *str);

void lcd_init(void);
void lcd_contrast(unsigned char contrast);
void lcd_clear(void);
void lcd_clear_buffer( void );

#endif



