//gio_tb
`include "gio.v" 

module gio_tb;

//nets to drive
reg [7:0] address;
reg [7:0] value_in;
reg wen;
reg rst;

//output wires
wire [7:0] port_out;

parameter A='h01;

initial begin
	$dumpfile("dump.vcd");
	$dumpvars(0,dut);	
	
	address = 'h00;
	value_in = 'h00;
	wen = 0;
	rst = 0;
	
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
	#50 $finish;
end

outport #(.ADDR('h01)) dut(
	.address(address),
	.value_in(value_in),
	.wen(wen),
	.rst(rst),
	.port_out(port_out)	
	);
	




endmodule
