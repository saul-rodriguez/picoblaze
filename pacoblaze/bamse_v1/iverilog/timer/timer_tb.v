//timer_tb.v

`timescale 1ns/1ps

`include "timer.v"

module timer_tb();

reg clk;
reg rst;
reg [2:0] prescaler_conf;
reg [15:0] timer_conf; 
reg en; //enable (H)
reg go; //start (H)
reg auto_load; //automatic restart timer after rolloff (H)
reg int;
reg [7:0] address;
wire [7:0] config_in;
wire [7:0] config_out;
reg ren;
reg wen;

wire interrupt;

assign interrupt = config_out[0];

assign config_in = {{1'b0},prescaler_conf,auto_load,en,go,int};
parameter ADDR=8'h00;

TIMER_BAMSE #(.ADDR(8'h00)) dut(
	.clk(clk),
	.rst(rst),	
	.timer_conf(timer_conf),
	.address(address),
	.config_in(config_in),
	.config_out(config_out),
	.ren(ren),
	.wen(wen)
);

always #(2) clk = ~clk;

initial begin
	$dumpfile("dump.vcd");
	$dumpvars(-1,dut,config_in,config_out,interrupt);
	
	en = 0;
	clk = 0;
	rst = 0;
	prescaler_conf = 0;
	timer_conf = 16'hfff0;
	en = 0;
	go = 0;
	auto_load = 0;
	address = 8'h00;
	ren = 0;
	wen = 0;
	int = 0;
		
	
	#10 rst = 1;
	#10 rst = 0;
	
	//task1;
	task2;
	
	#(100) $finish;
end

task task1; //selected_clk = 000
	begin
	#50 en = 1;
	#10 go = 1;
	#10 wen = 1;
	#10 go = 0; wen = 0;
	
	#80 wen = 1; 
	#10 wen = 0;
	
	#50 auto_load = 1; go = 1;
	#10 wen = 1;
	#10 wen = 0;
	
	#70 go = 0; int = 0;
	#10 wen = 1;
	#10 wen = 0;
	
	#80 auto_load = 0; int = 0;
	#10 wen = 1;
	#10 wen = 0;
	
	#80 auto_load = 1;
	#10 wen = 1;
	#10 wen = 0;
	
	#80 en = 0;
	#10 wen = 1;
	#10 wen = 0;
	
	end
endtask

task task2; //selected_clk = 001
	begin
	#10 prescaler_conf = 3'b001;
	#50 en = 1;
	#10 go = 1;
	#10 wen = 1;
	#10 go = 0; wen = 0;
	
	#160 wen = 1; 
	#10 wen = 0;
	
	#100 auto_load = 1; go = 1;
	#10 wen = 1;
	#10 wen = 0;
	
	#160 go = 0; int = 0;
	#10 wen = 1;
	#10 wen = 0;
	
	#160 auto_load = 0; int = 0;
	#10 wen = 1;
	#10 wen = 0;
	
	#160 auto_load = 1;
	#10 wen = 1;
	#10 wen = 0;
	
	#160 en = 0;
	#10 wen = 1;
	#10 wen = 0;
	
	end
endtask


endmodule
