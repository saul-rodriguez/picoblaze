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
wire tmr_interrupt; //interrupt (H)
reg [7:0] address;
wire [7:0] config_in;
wire [7:0] config_out;
reg ren;
reg wen;

assign config_in = {{1'b0},prescaler_conf,auto_load,en,go,tmr_interrupt};
parameter ADDR=8'h00;
/*
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
*/

TIMER_BAMSE #(.ADDR(8'h00)) dut(
	.clk(clk),
	.rst(rst),	
	.timer_conf(timer_conf),
	//.en(en),		
	.tmr_interrupt(tmr_interrupt),
	.address(address),
	.config_in(config_in),
	.config_out(config_out),
	.ren(ren),
	.wen(wen)
);

always #(2) clk = ~clk;

initial begin
	$dumpfile("dump.vcd");
	$dumpvars(0,dut,config_in,config_out);
	
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
		
	
	#10 rst = 1;
	#10 rst = 0;
	
	#50 en = 1;
	#10 go = 1;
	#10 wen = 1;
	#10 go = 0; wen = 0;
	
	
		/*
	#100 rst = 1;
	#10 rst = 0;
	#10 auto_load = 1;
	#10 go = 1;
	#10 go = 0;	
	
	#100 ren = 1;
	#10 ren = 0;
	
	#100 ren = 1;
	#10 ren = 0;
	
	#200 */
	#(250) $finish;
end

endmodule
