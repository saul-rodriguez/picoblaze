#include "../common/bamse.h"
#include <intr.h>
//#include "../common/delay.h"
//#include "../common/serial.h"
#include "../common/timer.h"

volatile unsigned char tmr_flag;

void main()
{
	unsigned char aux, flip;
	
	tmr_flag = 0;
	//Configure TIMER
	TIMER_setCounter(0x0000);
	
	aux = 0b01111110;
	TIMER_setConf(aux);
		
	//enable the interrupt
	aux = TIMER_INT_FLAG_BIT;
	intcon_enable_bits(aux);
	
	pbcc_enable_interrupt();
	
	flip = 0;
	while(1) {
		/*
		aux = 0b00000110;
		TIMER_setConf(aux);
		do {
			aux = TIMER_readConf() & 0x02;			
		} while (aux);	*/
		
		if (tmr_flag) {			
			tmr_flag = 0;
			
			if (flip) {
				flip = 0;
				PBLAZEPORT[PORTC_OUT] = 0x00;
			} else {
				flip = 1;			
				PBLAZEPORT[PORTC_OUT] = 0xff;
			}
		} 		
	}
			
}

void _interrupt_handler(void) __interrupt (1)
{	
	volatile unsigned char flags, aux;
	
	flags = PBLAZEPORT[INT_IN_FLAGS];
	
	if (flags & TIMER_INT_FLAG_BIT) {
		aux = TIMER_readConf();
		aux &= 0b11111110; // Clear interrupt flag
		//aux |= 0b00000010; // Set GO (only needed if autoload is not enabled)
		TIMER_setConf(aux);		
		tmr_flag = 1;				
	}
		
}
