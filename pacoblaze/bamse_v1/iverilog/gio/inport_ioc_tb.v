//inport_ioc_tb.v
`include "gio.v"

`define PORTD_IN 8'h03
`define PORTD_IOC_POS_CONF 3'b000
`define PORTD_IOC_NEG_CONF 3'b111

`define PORTD_WIDTH 3

module inport_ioc_tb;

reg [7:0] address;
reg [`PORTD_WIDTH-1:0] port_in;		
reg ren;
reg rst;
reg clk;
//reg [7:0] ioc_pos_conf;
//reg [7:0] ioc_neg_conf;		
reg int_ack;

wire [`PORTD_WIDTH-1:0] port_out;
wire int_out;

inport_ioc #(.ADDR(`PORTD_IN), .WIDTH(3)) PortD (
	.address(address),
	.port_in(port_in),
	.port_out(port_out),
	.ren(ren),
	.rst(rst),
	.clk(clk),
	.ioc_pos_conf(`PORTD_IOC_POS_CONF),
	.ioc_neg_conf(`PORTD_IOC_NEG_CONF),
	.int_out(int_out),
	.int_ack(int_ack)
);

initial begin
	$dumpfile("dump.vcd");
	$dumpvars(0,PortD);
	
	address = 'h00;
	port_in = 'h00;
	ren = 0;
	rst = 0;
	clk = 0;
	int_ack = 0;
	
	#10 rst = 1;
	#10 rst = 0;
	#20 port_in = 8'haa;
	#30 int_ack = 1;
	#10 int_ack = 0;
	#10 address = `PORTD_IN;
	#10 ren = 1;
	#10 ren = 0;
	#20 port_in = 8'h00;
	#30 int_ack = 1;
	#10 int_ack = 0;
	#10 port_in = 8'hee;
	#10 address = 8'h10;
	#10 ren = 1;
	#10 ren = 0;
	
	#50 $finish;
	
end

always begin
	#4 clk = ~clk;
end


endmodule
