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


module top(
    input DIR_RIGHT, //irq (H)
    input DIR_LEFT, //rst (H)
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
    input SW6,
    input SW7,
    output ARDUINO_RESET   
);

//connect Papillio duo pins to bamse;

wire [7:0] portA_out;
wire [7:0] portB_in;

assign {LED7,LED6,LED5,LED4,LED3,LED2,LED1,LED0} = portA_out;
assign portB_in = {SW7,SW6,SW5,SW4,SW3,SW2,SW1,SW0};

//Keep arduino's pin in the Papilio board at reset
assign ARDUINO_RESET = 0;

bamse bamse1(.irq(DIR_RIGHT),
             .rst(DIR_LEFT),
             .clk(CLK), 
             .portA_out(portA_out),
             .portB_in(portB_in)
          );    
endmodule
