`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/08/2019 10:42:08 PM
// Design Name: 
// Module Name: top
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////
`include "bamse.v"

module top(
    input DIR_RIGHT, 
    input DIR_LEFT, 
    input DIR_UP, 
    input DIR_DOWN,
    input CLK, //32 MHz
    output LED0, 
    output LED1,
    output LED2,
    output LED3,
    output LED4,
    output LED5,
    output LED6,
    output LED7,
    input SW0,
    input SW1,
    input SW2,
    input SW3,
    input SW4,
    input SW5,
    output SW6, //UART_TX
    input SW7, //UART_RX
    output ARDUINO_RESET   
);

//connect Papillio duo pins to bamse;

wire [2:0] portA;
wire [7:0] portB;
wire [7:0] portC;

// PORTA
assign portA = {DIR_LEFT, DIR_DOWN, DIR_RIGHT}; //The pbuttons are pull-down

// PORTB
assign portB = {1'b0,1'b0,SW5,SW4,SW3,SW2,SW1,SW0}; //The switches are pull-up

// PORTC
assign {LED7,LED6,LED5,LED4,LED3,LED2,LED1,LED0} = portC;

//UART


//Keep arduino's pin in the Papilio board at reset
assign ARDUINO_RESET = 0;

bamse bamse1(.rst(DIR_UP),
             .clk(CLK), 
             .PortA(portA),
             .PortB(portB),
             .PortC(portC),
             .TxUART(SW6),
             .RxUART(SW7)
          );    
endmodule
