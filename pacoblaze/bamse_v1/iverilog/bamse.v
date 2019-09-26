//`define PACOBLAZE3

`ifndef BAMSE
`define BAMSE

`include "pacoblaze3.v"
`include "pacoblaze_inc.v"
`include "bamse_inc.v"
`include "io_bamse.v"

`ifdef PROG_MEM_BEHAVIORAL
`include "blockram.v"
`endif


module bamse(	
	//irq,	//IRQ active H
	rst, //Reset active H
	clk,
	PortA,
	PortB,
	PortC,
	TxUART,
	RxUART
);

//input irq;
input rst;  
input clk;

input [`PORTA_IN_WIDTH-1:0] PortA; 
input [`PORTB_IN_WIDTH-1:0] PortB; 
output [`PORTC_OUT_WIDTH-1:0] PortC;
output TxUART;
input RxUART;


wire [`code_depth-1:0] addr; // instruction address
wire [`operand_width-1:0] pid;   // port id 
wire [`operand_width-1:0] pout; // port output
wire ren;  // read strobe
wire wen;  // write strobe
`ifdef HAS_INTERRUPT_ACK
wire iak; // interrupt acknowledge
`endif

wire [`code_width-1:0] din; // program data input
wire [`operand_width-1:0] pin; // port input

wire irq;

//wire [`operand_width-1:0] interrupt_flags;
//assign interrupt_flags[7:3] = 0;

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

io_bamse ports(
//Ports 
	.PortA(PortA),
	.PortB(PortB),
	.PortC(PortC),	
	.TxUART(TxUART),
	.RxUART(RxUART),
	//Pacoblaze pins
	.port_id(pid),  //from port address in Pacoblaze
	.port_out(pin),  // to input port in Pacoblaze 
	.port_in(pout), // from output port in Pacoblaze
	.interrupt(irq), // to interrupt in Pacoblaze 
	//.ioc_flags(interrupt_flags[2:0]),
	//.interrupt_ack(iak), // from interrupt ack Pacoblaze
	.clk(clk),
	.rst(rst),
	.wen(wen),
	.ren(ren)
);

endmodule

`endif

