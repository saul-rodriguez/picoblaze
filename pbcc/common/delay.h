#ifndef DELAY_H
#define DELAY_H

#ifndef CLK_FREQ
#define CLK_FREQ 32000000 
#endif



//delay:
// Number of instruction cycles: 
// call 	1 
// load 	1
// add		1 x (255 - S0)
// jump nz  1 x (255 - S0)
// return 	1
//     
// S0 = 255 - T/(4xTC) + 3/2
// 

#if CLK_FREQ==32000000
	#define TS0 0xb2  
	#define TS0_10US 0xb6 
	#define TS0_1MS 0xba 
#endif

//10 us delay
void delay()
{
	__asm
		LOAD S0, TS0
	rpt11:
		ADD S0, 01
		JUMP NZ, rpt11	
	__endasm;
}

void delay_10us_fixed() 
{
	__asm
		LOAD S0, TS0_10US
		rpt22:
		ADD S0, 01
		JUMP NZ, rpt11	
	__endasm;	
}

void delay_10us(unsigned char time)
{
	unsigned char i;
	
	for (i=0; i<time; i++)  {
		delay_10us_fixed();		
	}
}

void delay_ms(unsigned char time) 
{
	unsigned char i;
	
	for (i=0; i<time; i++)  {
			delay_10us(100);		
	}
}

#endif

