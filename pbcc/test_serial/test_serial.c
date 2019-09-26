#include "../common/bamse.h"
//#include "../common/delay.h"
#include "../common/serial.h"

void main()
{
	unsigned char rx, tx,data;
	unsigned char flags;
	
	//Configure UART module
	UART_setupRx();
	
	
	flags = 0;
	rx = 0;
	tx = 0;
	
	PBLAZEPORT[PORTC_OUT] = 0x55;	
	
	while(1) {
		//wait until a byte is received
		while (!rx) {
			flags = PBLAZEPORT[INT_IN_FLAGS];
			rx = flags & UART_RX_INT_FLAG_BIT;
		}
		rx = 0;
		
		data = PBLAZEPORT[UART_RX];
		PBLAZEPORT[PORTC_OUT] = data;	
		
		
		//Check if the tx module is active
		while(!tx) {
			flags = PBLAZEPORT[INT_IN_FLAGS];
			tx = flags & UART_TX_INT_FLAG_BIT;			
		}
		tx = 0;
		
		PBLAZEPORT[UART_TX] = data;	
	}
			
}
