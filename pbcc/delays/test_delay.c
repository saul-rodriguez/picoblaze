
#include "../common/delay.h"
#include "../common/bamse.h"

void main()
{
	unsigned char aux;
	
	aux = 0;
	
	while(1) {
		PBLAZEPORT[PORTC_OUT] = 0x00;
		delay_ms(5);
		PBLAZEPORT[PORTC_OUT] = 0xff;
		delay_ms(5);		
	}
	
}
