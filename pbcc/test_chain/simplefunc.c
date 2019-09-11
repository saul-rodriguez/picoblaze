
#include <port.h>

char inc(char number)
{
	return number + 1;
}


void main()
{
	char a,b;	
	char c = 42;
	a = inc(c);
	b = inc(a);
	b = b + 2;
	c = b;
	__port_write(3,c);
	
}
