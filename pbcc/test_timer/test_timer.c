#include "../common/bamse.h"
#include <intr.h>
//#include "../common/delay.h"
//#include "../common/serial.h"
#include "../common/timer.h"

void main()
{
	unsigned char aux, flag;
	
	flag = 0;
	//Configure TIMER
	TIMER_setCounter(0xfff0);
	
	aux = 0b00000110;
	TIMER_setConf(aux);
		
	//pbcc_enable_interrupt();
	
	while(1) {
		aux = 0b00000110;
		TIMER_setConf(aux);
		do {
			aux = TIMER_readConf() & 0x02;			
		} while (aux);	
		
		if (flag) {
			flag = 0;
			PBLAZEPORT[PORTC_OUT] = 0x00;
			
		} else {
			flag = 1;
			PBLAZEPORT[PORTC_OUT] = 0xff;
		}		
	}
			
}

void _interrupt_handler(void) __interrupt (1)
{	
	volatile unsigned char flags;
	
	flags = PBLAZEPORT[INT_IN_FLAGS];
		
}
