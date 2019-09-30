#include "../common/bamse.h"
#include <intr.h>
#include "../common/delay.h"
#include "../common/serial.h"

void main()
{
	unsigned char rx, tx,data;
	unsigned char flags;
	
	//Configure UART module
	intcon = 0;
	
	UART_setup();
	
	pbcc_enable_interrupt();

	delay_ms(4);
	while(1) {
		
		if(eusart1RxCount) {
			data = EUSART1_Read();
			PBLAZEPORT[PORTC_OUT] = data;	
		}
	}
	
	
	/*// Test transmit with interrupt
	
	data = 0xaa;
	while(1) {
		EUSART1_Write(data);
		data++;
	}*/
		
	/* // Test blocking functions getchar and putchar
	
	flags = 0;
	rx = 0;
	tx = 0;
	
	PBLAZEPORT[PORTC_OUT] = 0x55;	
	
	while(1) {
		
		data = getchar();
		PBLAZEPORT[PORTC_OUT] = data;
		putchar(data);			
	}
	*/
				
}

void _interrupt_handler(void) __interrupt (1)
{	
	volatile unsigned char flags;
	
	flags = PBLAZEPORT[INT_IN_FLAGS];
	
	if ((flags & UART_TX_INT_FLAG_BIT) && (intcon & UART_TX_INT_FLAG_BIT)) {
		EUSART1_Transmit_ISR();
	} else if ((flags & UART_RX_INT_FLAG_BIT) && (intcon & UART_RX_INT_FLAG_BIT)) {
		EUSART1_Receive_ISR();
	}
	
	
}
