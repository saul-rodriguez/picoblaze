/*
Complete test of picoblaze C compiler
*/

unsigned char accumulate(unsigned char arg);
unsigned char substract(unsigned char data);
void _interrupt_handler(void) __interrupt (1);

volatile unsigned char b; 


void _interrupt_handler(void) __interrupt (1)
{
	b++;
}


//Array for handling input/output ports
extern volatile char PBLAZEPORT[]; 


void main()
{
	unsigned char a,c;
	
	b = 0;
	
	while(1) {
		a = PBLAZEPORT[1];
		PBLAZEPORT[2] = a;
		c = accumulate(a);
	}
	
}

unsigned char accumulate(unsigned char arg)
{
	b += arg;
	substract(b);
	return b;
}

unsigned char substract(unsigned char data)
{
	data--;
	return data;
}


