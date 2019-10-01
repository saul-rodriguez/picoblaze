//timer_tb.v

`timescale 1ns/1ps

`include "timer.v"

module timer_tb();

reg clk_in;
reg rst;
reg [2:0] prescaler_conf;
reg [15:0] timer_conf; 
reg en; //enable (H)
reg go; //start (H)
reg auto_load; //automatic restart timer after rolloff (H)
wire tmr_int; //interrupt (H)

timer dut(
	.clk_in(clk_in),
	.rst(rst),
	.prescaler_conf(prescaler_conf),
	.timer_conf(timer_conf),
	.en(en),
	.go(go),
	.auto_load(auto_load),
	.tmr_int(tmr_int)
);

always #(2) clk_in = ~clk_in;

initial begin
	$dumpfile("dump.vcd");
	$dumpvars(1,dut);
	
	clk_in = 0;
	rst = 0;
	prescaler_conf = 0;
	timer_conf = 16'hfff0;
	en = 0;
	go = 0;
	auto_load = 0;
	
	#10 rst = 1;
	#10 rst = 0;
	#50 en = 1;
	#10 go = 1;
		
	#100 rst = 1;
	#10 rst = 0;
	#10 auto_load = 1;
	#100 go = 0;
	
	
	#(150) $finish;
end

endmodule
