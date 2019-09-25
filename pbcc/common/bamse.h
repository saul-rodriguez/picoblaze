//bamse.h

#ifndef BAMSE_H
#define BAMSE_H

#define PORTA_IN 0x01
#define PORTA_IN_WIDTH 3
#define PORTA_IOC_POS_CONF 0x02
#define PORTA_IOC_NEG_CONF 0x03

#define PORTB_IN 0x04
#define PORTB_IN_WIDTH 8

#define PORTC_OUT 0x05
#define PORTC_OUT_WIDTH 8

#define INT_OUT_CONFIG 0x00 
#define INT_IN_FLAGS  0x00 

//Array used to write and read Pacoblaze's ports
extern volatile char PBLAZEPORT[]; 


#endif

