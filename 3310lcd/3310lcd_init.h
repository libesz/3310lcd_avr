//{{AVR_IO_DESIGNER_HDR
// D:\[prog]\avr_studio_5\3310lcd\3310lcd\3310lcd.aid

//
// PORTB variable definitions
//
typedef struct
{
	unsigned char	_STATUSLED       : 1;	// 
	unsigned char	_Unused1         : 1;	// 
	unsigned char	_Unused2         : 1;	// 
	unsigned char	_Unused3         : 1;	// 
	unsigned char	_Unused4         : 1;	// 
	unsigned char	_Unused5         : 1;	// 
	unsigned char	_Unused6         : 1;	// 
	unsigned char	_Unused7         : 1;	// 
} PORTB_STRUCT;

// PORTB0 for 1: STATUSLED as Output - 
#define	STATUSLED_PORT          ((volatile PORTB_STRUCT*)&PORTB)        // PORT register
#define	STATUSLED_PIN           ((volatile PORTB_STRUCT*)&PINB)         // PIN register
#define	STATUSLED_DDR           ((volatile PORTB_STRUCT*)&DDRB)         // DDR register
#define	STATUSLED               STATUSLED_PORT->_STATUSLED              // output
#define	STATUSLED_TOGGLE        STATUSLED_PIN->_STATUSLED               // output toggle
#define	STATUSLED_DIR           STATUSLED_DDR->_STATUSLED               // direction control
#define	STATUSLED_MASK          0x01                                    // mask
#define	STATUSLED_SHIFT         0x00                                    // shift count

//
// PORTD variable definitions
//
typedef struct
{
	unsigned char	___RXD           : 1;	// Reserved for pin RXD
	unsigned char	___TXD           : 1;	// Reserved for pin TXD
	unsigned char	_Unused2         : 1;	// 
	unsigned char	_Unused3         : 1;	// 
	unsigned char	_Unused4         : 1;	// 
	unsigned char	_Unused5         : 1;	// 
	unsigned char	_Unused6         : 1;	// 
	unsigned char	_INPUT_SWITCH    : 1;	// 
} PORTD_STRUCT;

// PORTD0 for 1: __RXD as Input - Reserved for pin RXD
#define	__RXD_PORT              ((volatile PORTD_STRUCT*)&PORTD)        // PORT register
#define	__RXD_PIN               ((volatile PORTD_STRUCT*)&PIND)         // PIN register
#define	__RXD_DDR               ((volatile PORTD_STRUCT*)&DDRD)         // DDR register
#define	__RXD                   __RXD_PIN->___RXD                       // input
#define	__RXD_PULLUP            __RXD_PORT->___RXD                      // pullup control
#define	__RXD_DIR               __RXD_DDR->___RXD                       // direction control
#define	__RXD_MASK              0x01                                    // mask
#define	__RXD_SHIFT             0x00                                    // shift count

// PORTD1 for 1: __TXD as Output - Reserved for pin TXD
#define	__TXD_PORT              ((volatile PORTD_STRUCT*)&PORTD)        // PORT register
#define	__TXD_PIN               ((volatile PORTD_STRUCT*)&PIND)         // PIN register
#define	__TXD_DDR               ((volatile PORTD_STRUCT*)&DDRD)         // DDR register
#define	__TXD                   __TXD_PORT->___TXD                      // output
#define	__TXD_TOGGLE            __TXD_PIN->___TXD                       // output toggle
#define	__TXD_DIR               __TXD_DDR->___TXD                       // direction control
#define	__TXD_MASK              0x02                                    // mask
#define	__TXD_SHIFT             0x01                                    // shift count

// PORTD7 for 1: INPUT_SWITCH as Input with pullups - 
#define	INPUT_SWITCH_PORT       ((volatile PORTD_STRUCT*)&PORTD)        // PORT register
#define	INPUT_SWITCH_PIN        ((volatile PORTD_STRUCT*)&PIND)         // PIN register
#define	INPUT_SWITCH_DDR        ((volatile PORTD_STRUCT*)&DDRD)         // DDR register
#define	INPUT_SWITCH            INPUT_SWITCH_PIN->_INPUT_SWITCH         // input
#define	INPUT_SWITCH_PULLUP     INPUT_SWITCH_PORT->_INPUT_SWITCH        // pullup control
#define	INPUT_SWITCH_DIR        INPUT_SWITCH_DDR->_INPUT_SWITCH         // direction control
#define	INPUT_SWITCH_MASK       0x80                                    // mask
#define	INPUT_SWITCH_SHIFT      0x07                                    // shift count

// TIMER_COUNTER_0 -  - 
//}}AVR_IO_DESIGNER_HDR
