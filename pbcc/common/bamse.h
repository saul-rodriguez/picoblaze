//bamse.h


#ifndef BAMSE_H
#define BAMSE_H

#ifndef CLK_FREQ
#define CLK_FREQ 32000000 
#endif

#define PORTA_IN 0x01
#define PORTA_IN_WIDTH 3
#define PORTA_IOC_POS_CONF 0x02
#define PORTA_IOC_NEG_CONF 0x03

#define PORTB_IN 0x04
#define PORTB_IN_WIDTH 8

#define PORTC_OUT 0x05
#define PORTC_OUT_WIDTH 8

#define UART_RX 0x06
#define UART_RX_INT_FLAG_BIT 0b00001000
#define UART_OUT_CONFIG_L 0x07
#define UART_OUT_CONFIG_H 0x08
#define UART_TX 0x09
#define UART_TX_INT_FLAG_BIT 0b00010000

#define INT_OUT_CONFIG 0x00 
#define INT_IN_FLAGS  0x00 

#define USE_UART_INTERRUPT

//Array used to write and read Pacoblaze's ports
extern volatile char PBLAZEPORT[]; 

volatile unsigned char intcon = 0;

void update_intcon(void) 
{
	PBLAZEPORT[INT_OUT_CONFIG] = intcon;
}

void intcon_enable_bit(unsigned char pos)
{
	intcon |= pos;
	
}

void intcon_disable_bit(unsigned char pos)
{
	intcon &= (~pos);	
}



#endif

