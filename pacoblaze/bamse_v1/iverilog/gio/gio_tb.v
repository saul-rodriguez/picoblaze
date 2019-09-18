//gio_tb
`include "gio.v" 

`define PORTA_IN 8'h01
`define PORTB_IN 8'h02
`define PORTC_OUT 8'h05

module gio_tb();

//nets to drive
reg [7:0] address;
//reg [7:0] value_in;
reg wen;
reg rst;

reg [7:0] value_in;
reg [7:0] portA_in;
reg [7:0] portB_in;
reg ren;
reg clk;

//output wires
wire [7:0] portC_out;
wire [7:0] portA_in_core;
wire [7:0] portB_in_core;

outport #(.ADDR(`PORTC_OUT)) PortC(
	.address(address),
	.value_in(value_in),
	.wen(wen),
	.rst(rst),
	.port_out(portC_out)	
);
	
inport #(.ADDR(`PORTA_IN)) PortA(
	.address(address),
	.port_in(portA_in),
	.port_out(portA_in_core),
	.ren(ren),
	.rst(rst),
	.clk(clk)	
);

inport #(.ADDR(`PORTB_IN)) PortB(
	.address(address),
	.port_in(portB_in),
	.port_out(portB_in_core),
	.ren(ren),
	.rst(rst),
	.clk(clk)	
);

in_port_selector #(.ADDR0(`PORTA_IN), .ADDR1(`PORTB_IN))
	input_ports(
		.address(address),
		.in_port0(portA_in_core),
		.in_port1(portB_in_core)
); 


initial begin
	$dumpfile("dump.vcd");
	$dumpvars(0,PortA,PortB,PortC,input_ports);	
	//$dumpvars(0,inp);	
	
	address = 'h00;
	value_in = 'h00;
	portA_in = 'haa;	
	portB_in = 'hbb;
	wen = 0;
	rst = 0;
	ren = 0;
	clk = 0;
	
	#10 rst = 1;
	#10 rst = 0;
	#10 address = `PORTA_IN;
		value_in = 'hdd;
	#10 wen = 1;
	#10 wen = 0;
	#50 address = `PORTC_OUT;
		//value_in = 'h05;
	#10 wen = 1;
	#10 wen = 0;
	#20 ren = 1;
	#10 ren = 0;
	#20 address = `PORTB_IN;
	#20 ren = 1;
	#10 ren = 0;
	#20 address = `PORTA_IN;		
	#20 ren = 1;
	#10 ren = 0;	
	#50 $finish;
end

always begin
	#4 clk = ~clk;
end

endmodule
