// timer.h

#ifndef TIMER_H
#define TIMER_H

// Configuration word (both input and output)
//      B7       B6        B5       B4        B3        B2        B1        B0
//   	-        PS2      PS1       PS0      AUTO_LD    EN        GO      INT_TMR
//
// Note: GO and INT_TMR are R&W bits that are set/cleared by the timer.
// 

void TIMER_setCounter(unsigned short count);
void TIMER_setConf(unsigned char conf);
unsigned char TIMER_readConf();

void TIMER_setCounter(unsigned short count)
{
	unsigned char aux;
	
	aux = (unsigned char)(count);
	PBLAZEPORT[TIMER_LREG] = aux;
	
	aux = (unsigned char)(count >> 8);
	PBLAZEPORT[TIMER_HREG] = aux;
}

void TIMER_setConf(unsigned char conf)
{
	PBLAZEPORT[TIMER] = conf;	
}

unsigned char TIMER_readConf()
{
	unsigned char aux;
	
	aux = PBLAZEPORT[TIMER];
	return aux;
}

#endif 
