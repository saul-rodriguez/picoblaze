#include "../common/bamse.h"

/*
 * test.c
*/

volatile unsigned char buf[4];

void do_math(unsigned char data);
unsigned short mult8(unsigned char a, unsigned char b);
unsigned short mult16(unsigned short a, unsigned short b);

void main()
{
	volatile unsigned char test,num;
	volatile unsigned short res;
		
	test = 0xff;
	num = 5;
	while(1) {
		res = test*num;
		
		PBLAZEPORT[0] = (unsigned char)res;
		PBLAZEPORT[1] = (unsigned char)(res >> 8);
		test++;
				
		/*
			//test = PBLAZEPORT[0];
			do_math(test);
			PBLAZEPORT[PORTC_OUT] = buf[0];
			PBLAZEPORT[PORTC_OUT] = buf[1];
			//test++;
			while(1);
			*/
			
			/*
			__asm
				LOAD S0,ff
				LOAD S1,00
				SRA S0
				SRA S2				
			__endasm;
			*/
	}
}

void do_math(unsigned char data)
{	
	unsigned char a,b,c;
	unsigned short d,e,f;
	
	a = data;
	b = 5;
	
	//d = mult8(a,b);
	d = (unsigned short)a*b;
	c = data + 1;
	e = c++;
	f = e<<1;
	
	buf[0] = (unsigned char) d;
	buf[1] = (unsigned char) (d >> 8);
	
	
	/*
	d = 0xaabb;
	
	a = (unsigned char)d;
	PBLAZEPORT[2] = a;
	a = (unsigned char)(d>>8);
	PBLAZEPORT[3] = a;
	*/
	
}

unsigned short mult8(unsigned char a, unsigned char b)
{
//	unsigned short aux;
	
	//aux = a*b;
	
	//aux = a + b;
	
	
	__asm
			STORE s2, (sF)
			SUB	sF, 01
			
			LOAD s0,sb
			LOAD s1,sc 
			LOAD sc,00 ;msb 
			LOAD sb,00 ;lsb
			LOAD s2, 01 

mul8_loop:  
			test s1, s2
            jump z, mul8_no_add
            add sb, s0
            
mul8_no_add:
			sra sb
            sra sc
            sl0 s2
            jump nz, mul8_loop 
            
            ADD	sF, 01
			FETCH	s2, (sF)
            return 
            	
	__endasm;
	
	
	
	
	//return aux;
}

unsigned short mult16(unsigned short a, unsigned short b)
{
	unsigned short aux;
	
	aux = a + b;
	
	return aux;
	
}
