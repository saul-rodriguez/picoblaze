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
wire go_clear;
reg [7:0] address;
reg ren;
reg wen;


reg go_aux;

parameter ADDR=8'h00

//Resetable register
always @(posedge clk_in) begin
	if (rst) begin
		go_aux <= 0;
	end else if (go_clear) begin
		go_aux <= ~go_clear & go_aux;
	end	else if (address == (ADDR && wen)) begin
		go_aux <= go;	
	end
end


timer #(.ADDR(8'h00)) dut(
	.clk_in(clk_in),
	.rst(rst),
	.prescaler_conf(prescaler_conf),
	.timer_conf(timer_conf),
	.en(en),
	.go(go_aux),
	.auto_load(auto_load),
	.tmr_int(tmr_int),
	.address(address),
	.ren(ren),
	.go_clear(go_clear)
);

always #(2) clk_in = ~clk_in;

initial begin
	$dumpfile("dump.vcd");
	$dumpvars(0,dut,go,go_aux);
	
	clk_in = 0;
	rst = 0;
	prescaler_conf = 0;
	timer_conf = 16'hfff0;
	en = 0;
	go = 0;
	auto_load = 0;
	address = 8'h00;
	ren = 0;
	
	#10 rst = 1;
	#10 rst = 0;
	#50 en = 1;
	#10 go = 1;
	#10 go = 0;
	
		
	#100 rst = 1;
	#10 rst = 0;
	#10 auto_load = 1;
	#10 go = 1;
	#10 go = 0;	
	
	#100 ren = 1;
	#10 ren = 0;
	
	#100 ren = 1;
	#10 ren = 0;
	
	#200 
	#(250) $finish;
end

endmodule
