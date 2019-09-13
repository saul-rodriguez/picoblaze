/*
 * test.c
*/

#include <port.h>
#define PORTA 0x00

void main()
{
	unsigned char aux;
	
	aux = 0xaa;
	
	while(aux) {
		__port_write(PORTA,aux);
		
		delay(1);
		aux ^= 0xff;
	}
}

