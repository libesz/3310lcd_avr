//{{AVR_IO_DESIGNER_INIT
	// D:\[prog]\avr_studio_5\3310lcd\3310lcd\3310lcd.aid

	//
	// Project Options - 3310lcd
	//
	// Device Name = ATmega168
	// CPU Frequency (F_CPU) = 16,0 MHz
	// IC Package = PDIP
	// Sort Pins by = Pin Number
	// Output Code File = 3310lcd_init.c
	// Output Header File = 3310lcd_init.h
	// Assume Default State = True
	// Write Unmodified Bits = True
	// Set Unused PORT Pins = Input

	//
	// PORTB variable initializations
	//
	// PORTB0 for 1: STATUSLED as Output - 
	DDRB = 0x01;

	//
	// PORTD variable initializations
	//
	// PORTD0 for 1: __RXD as Input - Reserved for pin RXD
	// PORTD1 for 1: __TXD as Output - Reserved for pin TXD
	// PORTD7 for 1: INPUT_SWITCH as Input with pullups - 
	PORTD = 0x80;
	DDRD = 0x02;

	//
	// TIMER_COUNTER_0 -  - 
	//
	// Counter Period = v?gtelen sec
	// Counts per Second = v?gtelen Hz

	//
	// USART0
	//
	// Receiver Enable = Enabled
	// Transmitter Enable = Enabled
	// Baud Rate Register = 25
	//     (38.4k baud, 0,2 %error)
	UCSR0B = 0x18;	// (0<<RXCIE0)|(1<<RXEN0)|(1<<TXEN0)
	UBRR0 = 0x19;
//}}AVR_IO_DESIGNER_INIT
