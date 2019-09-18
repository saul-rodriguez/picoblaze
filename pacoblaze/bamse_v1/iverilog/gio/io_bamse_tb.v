//io_bamse_tb

`include "io_bamse.v"

module io_bamse_tb();

reg  [`PORTA_IN_WIDTH-1:0] PortA;
reg  [`PORTB_IN_WIDTH-1:0] PortB;
wire [`PORTC_OUT_WIDTH-1:0] PortC;	
	//Pacoblaze pins
reg [7:0]	port_id;
wire [7:0] port_out;
reg [7:0]	port_in;
wire interrupt;
reg  interrupt_ack;
reg clk;
reg rst;
reg wen;
reg ren;

io_bamse ports(
	//Ports 
	.PortA(PortA),
	.PortB(PortB),
	.PortC(PortC),	
	//Pacoblaze pins
	.port_id(port_id),  //from port address in Pacoblaze
	.port_out(port_out),  // to input port in Pacoblaze 
	.port_in(port_in), // from output port in Pacoblaze
	.interrupt(interrupt), // to interrupt in Pacoblaze 
	.interrupt_ack(interrupt_ack), // from interrupt ack Pacoblaze
	.clk(clk),
	.rst(rst),
	.wen(wen),
	.ren(ren)
);

initial begin
	$dumpfile("dump.vcd");
	$dumpvars(0,ports);	
	
	PortA = 0;
	PortB = 0;
	port_id = 0;
	port_in = 0;
	interrupt_ack = 0;
	clk = 0;
	rst = 0;
	wen = 0; 
	ren = 0;	
	#10 rst = 1;
	#10 rst = 0;
	
	write_config_PORTA;
	interrupt_read_PORTA;
	read_PORTB;	
	write_PORTC;
	
	#100 $finish;
	
end

task write_config_PORTA;
	begin
	// Write to PORTA configuration registers
	#10 port_id = `PORTA_IOC_POS_CONF;
	#10 port_in = 3'b011;
	#10 wen = 1;
	#10 wen = 0;
	#10 port_id = `PORTA_IOC_NEG_CONF;
	#10 port_in = 3'b101;
	#10 wen = 1;
	#10 wen = 0;	
	end
endtask

task interrupt_read_PORTA;
	begin
	// Interruption and read of PORTA
	#10 PortA = 3'b001;
	#30 interrupt_ack = 1;
	#10 interrupt_ack = 0;
	#10 port_id = `PORTA_IN;
	#10 ren = 1;
	#10 ren = 0;
	#40 PortA = 0;
	#30 interrupt_ack = 1;
	#10 interrupt_ack = 0;
	
	#10 PortA = 3'b010;
	#30 interrupt_ack = 1;
	#10 interrupt_ack = 0;
	#10 port_id = `PORTA_IN;
	#10 ren = 1;
	#10 ren = 0;
	#40 PortA = 0;
	#30 interrupt_ack = 1;
	#10 interrupt_ack = 0;
	
	#10 PortA = 3'b100;
	#30 interrupt_ack = 1;
	#10 interrupt_ack = 0;
	#10 port_id = `PORTA_IN;
	#10 ren = 1;
	#10 ren = 0;
	#40 PortA = 0;
	#30 interrupt_ack = 1;
	#10 interrupt_ack = 0;
	end
endtask

task read_PORTB;
	begin
	#10 PortB = 8'hbb;
	#10 port_id = `PORTB_IN;
	#10 ren = 1;
	#10 ren = 0;
	end	
endtask

task write_PORTC;
	begin
	#10 port_id = `PORTC_OUT;
	#10 port_in = 8'hcc;
	#10 wen = 1;
	#10 wen = 0;	
	end
endtask

always begin
	#4 clk = ~clk;
end

endmodule
