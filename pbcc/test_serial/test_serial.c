#include "../common/bamse.h"
//#include "../common/delay.h"
#include "../common/serial.h"

void main()
{
	unsigned char rx, data;
	unsigned char flags;
	
	//Configure UART module
	UART_setupRx();
	
	
	flags = 0;
	rx = 0;
	
	while(1) {
		while (!rx) {
			flags = PBLAZEPORT[INT_IN_FLAGS];
			rx = flags & UART_RX_INT_FLAG_BIT;
		}
		rx = 0;
		
		data = PBLAZEPORT[UART_RX];
		PBLAZEPORT[PORTC_OUT] = data;		
	}
			
}
