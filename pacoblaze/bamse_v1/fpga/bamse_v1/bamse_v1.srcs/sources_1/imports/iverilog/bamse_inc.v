//bamse_inc.v
`ifndef BAMSE_INC
`define BAMSE_INC

// Program Memory
// Comment below if implementation's memory is used
// for program (FPGA, ASIC)
//`define PROG_MEM_BEHAVIORAL 

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

// UART
`define UART_RX 8'h06
`define UART_OUT_CONFIG_L 8'h07
`define UART_OUT_CONFIG_H 8'h08
`define UART_TX 8'h09

// Interrupts
`define INT_OUT_CONFIG 8'h00 // address interrupt config. register
`define INT_IN_FLAGS  8'h00 //address interrupt flags

`endif
