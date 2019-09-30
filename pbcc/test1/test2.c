#include "../common/bamse.h"

void main()
{
	__asm
	LOAD s0, f0
	LOAD S1, 00	
	SLA s0
	SLA s1
	LOAD s0, 0f
	LOAD s1, 0
	SRA s0
	SRA s1	
	__endasm;

}
