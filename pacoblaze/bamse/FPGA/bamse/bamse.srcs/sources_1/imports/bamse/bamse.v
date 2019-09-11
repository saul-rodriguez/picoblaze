`define PACOBLAZE3

`include "pacoblaze3.v"
`include "pacoblaze_inc.v"
`include "gio.v"

`define PORTA 8'b0000_0001

module bamse(	
	irq,	//IRQ active H
	rst, //Reset active H
	clk,
	portA_out,
);

input irq;
input rst;  
input clk;
output [7:0] portA_out; //PortA output

wire [`code_depth-1:0] addr; // instruction address
wire [`operand_width-1:0] pid, pout; // port id, port output
wire ren, wen; // read strobe, write strobe
`ifdef HAS_INTERRUPT_ACK
wire iak; // interrupt acknowledge
`endif

wire [`code_width-1:0] din; // program data input
wire [`operand_width-1:0] pin; // port input

/*IN_PORT is disabled, inputs are pulled down L*/
assign pin = 'h00;

/* PacoBlaze program memory */
/*
blockram #(.width(`code_width), .depth(`code_depth))
	rom(
	.clk(clk),
	.rst(rst),
	.enb(1'b1),
	.wen(1'b0),
	.addr(addr),
	.din(`code_width 'b0),
	.dout(din)
);
*/
porta mem(
    .address(addr),
    .instruction(din),
    .clk(clk),
    .WEA(4'b0000)
);

/* PacoBlaze dut */
pacoblaze3 pblaze(
	.clk(clk),
	.reset(rst),
	.address(addr),
	.instruction(din),
	.port_id(pid),
	.read_strobe(ren),
	.write_strobe(wen),
	.in_port(pin),
	.out_port(pout),
	.interrupt(irq)
`ifdef HAS_INTERRUPT_ACK
	,	.interrupt_ack(iak)
`endif
);

/* PortA*/
outport #(.ADDR(`PORTA)) portA(
	.address(pid),
	.value_in(pout),
	.wen(wen),
	.rst(rst),
	.port_out(portA_out)	
);
	
	


endmodule


