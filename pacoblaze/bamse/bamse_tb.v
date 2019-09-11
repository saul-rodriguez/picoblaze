
`ifndef TEST_FILE
`define TEST_FILE "./firmware/porta.hex"
`endif

`ifndef TEST_CYCLES
`define TEST_CYCLES 100000
`endif

`ifndef TEST_IRQ
`define TEST_IRQ 100
`endif

`include "timescale_inc.v"
`include "pacoblaze_inc.v"

module bamse_tb;

parameter tck = 31.25, program_cycles = `TEST_CYCLES; //CLK at 32 MHz

reg clk, rst, irq; // clock, reset, interrupt request
//wire [`code_depth-1:0] addr; // instruction address
//wire [`operand_width-1:0] pid, pout; // port id, port output
//wire ren, wen; // read strobe, write strobe
//`ifdef HAS_INTERRUPT_ACK
//wire iak; // interrupt acknowledge
//`endif

//reg [`operand_width-1:0] port[0:`port_size-1]; // port memory

//wire [`code_width-1:0] din; // program data input
//wire [`operand_width-1:0] pin = port[pid]; // port input
wire [7:0] portA_out;

bamse dut(	
	.irq(irq),	//IRQ active H
	.rst(rst), //Reset active H
	.clk(clk),
	.portA_out(portA_out)
);

/* PacoBlaze program memory 
blockram #(.width(`code_width), .depth(`code_depth))
	rom(
	.clk(clk),
	.rst(rst),
	.enb(1'b1),
	.wen(1'b0),
	.addr(addr),
	.din(`code_width 'b0),
	.dout(din)
);

/* PacoBlaze dut 
pacoblaze3 dut(
	.clk(clk),
	.reset(rst),
	.address(addr),
	.instruction(din),
	.port_id(pid),
	.read_strobe(ren),
	.write_strobe(wen),
	.in_port(pin),
	.out_port(pout),
	.interrupt(irq)
`ifdef HAS_INTERRUPT_ACK
	,	.interrupt_ack(iak)
`endif
); */


/* Clocking device */
always #(tck/2) clk = ~clk;

/* Watch port memory */
//always @(posedge clk)	if (wen) port[pid] <= pout;

/* Display code */
always @(negedge clk)
	if (dut.pblaze.timing_control) begin
`ifdef HAS_DEBUG
		// $display("%h %h", dut.idu.instruction_0, dut.alu.operation);
//		$display("%h:%h %s %s", addr, din, dut.idu_debug, (dut.is_alu) ? {"[", dut.alu_debug, "]"} : "");
`else
		$display("%h:%h", dut.addr, dut.din);
`endif
end

/* Simulation setup */
integer idx;

initial begin
	$dumpfile("dump.vcd");
	//$dumpvars(-1, dut);
	$dumpvars(1, dut);
	for(idx = 0; idx < `register_size; idx = idx + 1) begin
	    $dumpvars(0,dut.pblaze.register.dpr[idx]);
	end
	
	
	$display("Loading firmware from file: %s",`TEST_FILE);
	$readmemh(`TEST_FILE, dut.rom.ram);
end

/* Simulation */
integer i;
initial begin
	//	for (i=0; i<`port_size; i=i+1) port[i] = i; // initialize ports
	clk = 0; rst = 1; irq = 0;
	#(tck*2);
	@(negedge clk) rst = 0; // free processor

	#(tck*`TEST_IRQ);
	@(negedge clk) irq = 1; // interrupt request
	$display("*IRQ*");
	// @(negedge clk) ;
	@(negedge clk) irq = 0;

	#(program_cycles*tck+100) $finish;
end

endmodule
