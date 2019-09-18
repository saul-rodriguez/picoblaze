`include "interrupt_controller.v"

module capture_int_tb(	
);

reg int_inp;
reg rst;
reg clk;
reg int_pos_en;
reg int_neg_en;
reg int_ack;

wire int_out;	

capture_ext_int dut(.int_inp(int_inp), 
				.rst(rst), 
				.clk(clk), 
				.int_pos_en(int_pos_en), 
				.int_neg_en(int_neg_en), 
				.int_ack(int_ack));

initial begin
	$dumpfile("dump.vcd");
    $dumpvars(0,dut);
    
    int_inp = 0;
    int_pos_en = 1;
    int_neg_en = 0;
    rst = 0;
    int_ack = 0;
    clk = 0;
    
    #10 rst = 1;
	#10 rst = 0;
	#10 int_inp = 1;
	#50 int_ack = 1;
	#10 int_ack = 0;	
	#50 int_inp = 0;
	#40 int_ack = 1;
	#10 int_ack = 0;
	#30 int_inp = 1;
	//#10 rst = 1;
	//#10 rst = 0;
	#50 int_inp = 0;
	#50 $finish;
end

always begin
    #5 clk = ~clk;
end


endmodule
