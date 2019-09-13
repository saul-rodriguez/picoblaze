//`define PACOBLAZE3

`include "pacoblaze3.v"
`include "pacoblaze_inc.v"
`include "gio.v"

//Comment if implementation memory is used for program (FPGA, ASIC)
//`define PROG_MEM_BEHAVIORAL 

//I/O devices addresses
`define PORTA 8'h01 //Digital output
`define PORTB 8'h02 //Digital input

module bamse(	
	irq,	//IRQ active H
	rst, //Reset active H
	clk,
	portA_out,
	portB_in
);

input irq;
input rst;  
input clk;

output [7:0] portA_out; //PortA output
input [7:0] portB_in; //PortB input


wire [`code_depth-1:0] addr; // instruction address
wire [`operand_width-1:0] pid;   // port id 
wire [`operand_width-1:0] pout; // port output
wire ren;  // read strobe, write strobe
wire wen;
`ifdef HAS_INTERRUPT_ACK
wire iak; // interrupt acknowledge
`endif

wire [`code_width-1:0] din; // program data input
wire [`operand_width-1:0] pin; // port input


/* PacoBlaze program memory behavioral model */

`ifdef PROG_MEM_BEHAVIORAL 
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
`else
spartan6_mem mem(
    .address(addr),
    .instruction(din),
    .clk(clk),
    .WEA(4'b0000)
);
`endif

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

/* Output ports */
outport #(.ADDR(`PORTA)) portA(
	.address(pid),
	.value_in(pout),
	.wen(wen),
	.rst(rst),
	.port_out(portA_out)	
);
	
/* Input ports */
inport #(.ADDR0(`PORTB)) inp_control(
	.address(pid),
	.port0_in(portB_in),
	.value_out(pin),
	.ren(ren),
	.rst(rst),
	.clk(clk)
);

endmodule


