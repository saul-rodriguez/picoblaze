`define PACOBLAZE3

`ifndef TEST_FILE
//`define TEST_FILE "/home/saul/projects/picoblaze/opbasm/hello_duo/hello.hex"
`define TEST_FILE "/home/saul/projects/picoblaze/pbcc/test_ioc/ioc.hex"
//`define TEST_FILE "/home/saul/projects/picoblaze/pbcc/delays/test_delay.hex"
`endif

`ifndef TEST_CYCLES
`define TEST_CYCLES 10000
`endif

`include "timescale_inc.v"
`include "top.v"

module top_tb;

//----------Constants-----------
parameter tck = 31.25, program_cycles = `TEST_CYCLES; //Papilio Duo CLK runs at 32 MHz 

//--------Internal Variables----
reg clk, rst; // clock, reset

reg [2:0] pbuttons;//PortA IN
reg [7:0] switches; //PortB IN
wire [7:0] leds; //PortC OUT
wire ARDUINO_RESET;  

//------Instantiate DUT---------
top dut(	
	.DIR_RIGHT(pbuttons[0]),	//IRQ active H
	.DIR_LEFT(pbuttons[2]), //Reset active H
	.DIR_UP(rst),
	.DIR_DOWN(pbuttons[1]),
	.CLK(clk),
	.LED0(leds[0]),.LED1(leds[1]),.LED2(leds[2]),.LED3(leds[3]),
	.LED4(leds[4]),.LED5(leds[5]),.LED6(leds[6]),.LED7(leds[7]),
	.SW0(switches[0]),.SW1(switches[1]),.SW2(switches[2]),.SW3(switches[3]),
	.SW4(switches[4]),.SW5(switches[5]),.SW6(switches[6]),.SW7(switches[7]),
	.ARDUINO_RESET(ARDUINO_RESET)
);

/* Clocking device */
always #(tck/2) clk = ~clk;

/* Display code */
always @(negedge clk)
	if (dut.bamse1.pblaze.timing_control) begin
`ifdef HAS_DEBUG
		// $display("%h %h", dut.idu.instruction_0, dut.alu.operation);
//		$display("%h:%h %s %s", addr, din, dut.idu_debug, (dut.is_alu) ? {"[", dut.alu_debug, "]"} : "");
`else
		$display("%h:%h", dut.bamse1.addr, dut.bamse1.din);
`endif
end

/* Simulation setup */
integer idx;

initial begin
	$dumpfile("dump.vcd");
	//$dumpvars(-1, dut);
	$dumpvars(1,dut);
	$dumpvars(1,dut.bamse1, dut.bamse1.ports, dut.bamse1.ports.Port_A, dut.bamse1.din);
	
	for(idx = 0; idx < `register_size; idx = idx + 1) begin
	    $dumpvars(0,dut.bamse1.pblaze.register.dpr[idx]);
	end	
	
	$display("Loading firmware from file: %s",`TEST_FILE);
	$readmemh(`TEST_FILE, dut.bamse1.rom.ram);
end

/* Simulation */
integer i;
initial begin
	
	clk = 0;
	rst = 1; 
	pbuttons = 0;
	switches = 8'hff;
		
	#(tck*2);
	@(negedge clk) rst = 0; // free processor
		
	interrupts;

	#(program_cycles*tck+100) $finish;
end

//TODO:
task interrupts;
	begin
	#(100*tck) pbuttons[0] =1; 
	#(100*tck) pbuttons[0] =0; 
	#(100*tck) pbuttons[1] =1; 
	#(100*tck) pbuttons[1] =0; 
	#(100*tck) pbuttons[2] =1; 
	#(100*tck) pbuttons[2] =0; 
	end
endtask

endmodule
