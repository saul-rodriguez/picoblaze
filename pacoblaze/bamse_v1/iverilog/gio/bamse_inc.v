//bamse_inc.v
`ifndef BAMSE_INC
`define BAMSE_INC

// PORTA_IN is an interrupt-on-change input port
`define PORTA_IN_WIDTH 3
`define PORTA_IN 8'h01 //address input port
`define PORTA_IOC_POS_CONF 8'h02 //address rising edge conf. register
`define PORTA_IOC_NEG_CONF 8'h03 //address falling edge conf. register

// PORTB_IN is a standard digital input port (8 bits)
`define PORTB_IN_WIDTH 8
`define PORTB_IN 8'h04

// PORTC_OUT is a standard digital output port (8 bits)
`define PORTC_OUT_WIDTH 8
`define PORTC_OUT 8'h05

`endif
