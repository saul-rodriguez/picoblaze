//gio_tb
`include "gio.v" 

module gio_tb;

//nets to drive
reg [7:0] address;
reg [7:0] value_in;
reg wen;
reg rst;

reg [7:0] port0_in;
reg [7:0] port1_in;
reg ren;
reg clk;

//output wires
wire [7:0] port_out;

wire [7:0] port_in;

parameter A='h01;


outport #(.ADDR('h01)) outp(
	.address(address),
	.value_in(value_in),
	.wen(wen),
	.rst(rst),
	.port_out(port_out)	
);
	
inport #(.ADDR0('h02) 
		 //,.ADDR1('h03) 
		 ) inp(
	.address(address),
	.port0_in(port0_in),
	//.port1_in(port1_in),
	.value_out(port_in),
	.ren(ren),
	.rst(rst),
	.clk(clk)	
);


initial begin
	$dumpfile("dump.vcd");
	$dumpvars(0,outp);	
	$dumpvars(0,inp);	
	
	address = 'h00;
	value_in = 'h00;
	port0_in = 'hcc;
	port1_in = 'hbb;
	wen = 0;
	rst = 0;
	ren = 0;
	clk = 0;
	
	#10 rst = 1;
	#10 rst = 0;
	#10 address = 'h01;
		value_in = 'haa;
	#10 wen = 1;
	#10 wen = 0;
	#50 address = 'h10;
		value_in = 'h05;
	#10 wen = 1;
	#10 wen = 0;
	#20 ren = 1;
	#10 ren = 0;
	#20 address = 'h02;
	#20 ren = 1;
	#10 ren = 0;
	#20 address = 'h03;
	#20 ren = 1;
	#10 ren = 0;
	#50 $finish;
	#50 $finish;
end

always begin
	#4 clk = ~clk;
end



endmodule
