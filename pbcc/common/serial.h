#ifndef SERIAL_H
#define SERIAL_H

#ifndef CLK_FREQ
	#define CLK_FREQ 32000000 
#endif

#ifndef UART_BRATE 
	#define UART_BRATE 9600
#endif

#if CLK_FREQ == 32000000 
	#if UART_BRATE == 9600
		#define UART_CLK_BIT 0x0d05 //UART_CLK_BIT = CLK_FREQ/UART_BRATE
		#define UART_CLK_BIT_H 0x0d
		#define UART_CLK_BIT_L 0x05
	#endif
#endif


void UART_setupRx()
{
	PBLAZEPORT[UART_OUT_CONFIG_L] = UART_CLK_BIT_L;
	PBLAZEPORT[UART_OUT_CONFIG_H] = UART_CLK_BIT_H;
}

unsigned char getchar()
{
	unsigned char aux;
	
	aux = 0;
	while (!aux) {
		aux = PBLAZEPORT[INT_IN_FLAGS];
		aux = aux & UART_RX_INT_FLAG_BIT;
	}
	
	aux = PBLAZEPORT[UART_RX];
	return aux;
}

#endif
