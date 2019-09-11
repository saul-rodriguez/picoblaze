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
    input irq,
    input rst,
    input clk,
    //output [7:0] portA_out,    
    output ard_reset,
    output led
);

wire [7:0] A_out;
 
assign ard_reset = 0;

assign led = A_out[0];
//assign led = 1;

bamse bamse1(.irq(irq),
          .rst(rst),
          .clk(clk), 
          .portA_out(A_out)
          );
          

    
    
endmodule
