//ioc.c

#include <intr.h>
#include "bamse.h"

void _interrupt_handler(void) __interrupt (1); 


volatile unsigned char porta, IOC_state;

//Array for handling input/output ports
extern volatile char PBLAZEPORT[]; 

void IOC_isr();
void IOC_handler(unsigned char porta_state);

enum IOC {
	IOC_IDLE = 0x00,
	IOC_BIT0 = 0x01,
	IOC_BIT1 = 0x02,
	IOC_BIT2 = 0x04,	
};
typedef enum IOC IOC;

void main()
{
			
	//configure IOC 
	PBLAZEPORT[PORTA_IOC_POS_CONF] = 0b00000101;
	PBLAZEPORT[PORTA_IOC_NEG_CONF] = 0b00000011;
	
	porta = PBLAZEPORT[PORTA_IN];
	IOC_state = 0;
	
	pbcc_enable_interrupt();
			
	while(1) {	
		if(IOC_state != IOC_IDLE) {			
			IOC_handler(IOC_state);
			IOC_state = IOC_IDLE;;
		}		
	}	
}

void _interrupt_handler(void) __interrupt (1)
{	
	IOC_isr();
}	

void IOC_isr()
{	
	unsigned char porta_new;
	porta_new = PBLAZEPORT[PORTA_IN];
	IOC_state = porta ^ porta_new; 			
	porta = porta_new;
}

void IOC_handler(unsigned char porta_state)
{
	unsigned char aux;
	PBLAZEPORT[PORTC_OUT] = porta_state;
	
	aux = porta_state & IOC_BIT0;
	if (aux) {
		PBLAZEPORT[PORTC_OUT] = 0x0f;
	}
	aux = porta_state & IOC_BIT1;
	if (aux) {
		PBLAZEPORT[PORTC_OUT] = 0x3c;
	}
	aux = porta_state & IOC_BIT2;
	if (aux) {
		PBLAZEPORT[PORTC_OUT] = 0xf0;
	} 
	
	IOC_state = 0;	
	/*
	switch(IOC_state) {
		case IOC_BIT0: PBLAZEPORT[PORTC_OUT] = 0x0f;
				   break;
		case IOC_BIT1: PBLAZEPORT[PORTC_OUT] = 0x3c;
				   break;
		case IOC_BIT2: PBLAZEPORT[PORTC_OUT] = 0xf0;
				   break;
		default: break;
	}*/
	
	
}