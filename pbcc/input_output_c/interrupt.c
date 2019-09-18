/*
Complete test of picoblaze C compiler
*/

#include <intr.h>

void _interrupt_handler(void) __interrupt (1); 

volatile unsigned char porta; 

//Array for handling input/output ports
extern volatile char PBLAZEPORT[]; 


void main()
{
	pbcc_enable_interrupt();
			
	while(1) {	
	}
	
}

void _interrupt_handler(void) __interrupt (1)
{
	unsigned char a;
	a = PBLAZEPORT[2];
	PBLAZEPORT[1] = a;	
}

