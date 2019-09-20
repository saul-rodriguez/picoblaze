//io_bamse.v

`ifndef IO_BAMSE
`define BIO_BAMSE

`include "bamse_inc.v"
`include "gio.v"
 
module io_bamse(
    //Ports 
	PortA,
	PortB,
	PortC,	
	//Pacoblaze pins
	port_id,  //from port address in Pacoblaze
	port_out,  // to input port in Pacoblaze 
	port_in, // from output port in Pacoblaze
	interrupt, // to interrupt in Pacoblaze 
	ioc_flags, // to interrupt register input in Pacoblaze
	//interrupt_ack, // from interrupt ack Pacoblaze
	clk,
	rst,
	wen,
	ren
);

input  [`PORTA_IN_WIDTH-1:0] PortA;
input  [`PORTB_IN_WIDTH-1:0] PortB;
output [`PORTC_OUT_WIDTH-1:0] PortC;	
	//Pacoblaze pins
input [7:0]	port_id;
output [7:0] port_out;
input [7:0]	port_in;
output interrupt;
output [`PORTA_IN_WIDTH-1:0] ioc_flags;
//input  interrupt_ack;
input clk;
input rst;
input wen;
input ren;

/******************/
/***** PORTA ******/
/******************/

wire [`PORTA_IN_WIDTH-1:0] portA_IOC_Pos_bus;

//IOC Configuration register rising edge 
outport #(.ADDR(`PORTA_IOC_POS_CONF), .WIDTH(`PORTA_IN_WIDTH)) PortA_IOC_Pos_Conf(
	.address(port_id),
	.value_in(port_in[`PORTA_IN_WIDTH-1:0]),
	.wen(wen),
	.rst(rst),
	.port_out(portA_IOC_Pos_bus)	
);

//IOC Configuration register falling edge
wire [`PORTA_IN_WIDTH-1:0] portA_IOC_Neg_bus;

outport #(.ADDR(`PORTA_IOC_NEG_CONF), .WIDTH(`PORTA_IN_WIDTH)) PortA_IOC_Neg_Conf(
	.address(port_id),
	.value_in(port_in[`PORTA_IN_WIDTH-1:0]),
	.wen(wen),
	.rst(rst),
	.port_out(portA_IOC_Neg_bus)	
);

//Port A input
wire [`PORTA_IN_WIDTH-1:0] portA_bus;

inport_ioc #(.ADDR(`PORTA_IN), .WIDTH(`PORTA_IN_WIDTH)) Port_A (
	.address(port_id),
	.port_in(PortA),
	.port_out(portA_bus),
	.ren(ren),
	.rst(rst),
	.clk(clk),
	.ioc_pos_conf(portA_IOC_Pos_bus),
	.ioc_neg_conf(portA_IOC_Neg_bus),
	.int_out(interrupt),
	.int_flags(ioc_flags)
	//.int_ack(interrupt_ack)
);

wire [7:0] portA_bus_8;
assign portA_bus_8 = {{(8-`PORTA_IN_WIDTH){1'b0}},portA_bus};

/****************/
/**** PORTB *****/
/****************/

wire [`PORTB_IN_WIDTH-1:0] portB_bus;

inport #(.ADDR(`PORTB_IN), .WIDTH(`PORTB_IN_WIDTH)) Port_B(
	.address(port_id),
	.port_in(PortB),
	.port_out(portB_bus),
	.ren(ren),
	.rst(rst),
	.clk(clk)	
);

wire [7:0] portB_bus_8;
assign portB_bus_8 = {{(8-`PORTB_IN_WIDTH){1'b0}},portB_bus};

/****************/
/**** PORTC *****/
/****************/

outport #(.ADDR(`PORTC_OUT), .WIDTH(`PORTC_OUT_WIDTH)) Port_C(
	.address(port_id),
	.value_in(port_in[`PORTC_OUT_WIDTH-1:0]),
	.wen(wen),
	.rst(rst),
	.port_out(PortC)	
);

/****************/
/* INPUT MUX    */
/****************/

in_port_selector #(.ADDR0(`PORTA_IN), .ADDR1(`PORTB_IN))
	input_ports(
		.address(port_id),
		.in_port0(portA_bus_8),
		.in_port1(portB_bus_8),
		.out_port(port_out)
);


endmodule

`endif

