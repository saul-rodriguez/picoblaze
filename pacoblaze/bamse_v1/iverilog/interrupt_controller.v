`ifndef INTERRUPT_CONTROLLER
`define INTERRUPT_CONTROLLER

/* interrupt_controller   
 * This module creates a single interrupt from multiple interrupt signals
 * An output port is used to read interrupt enable bits
 */

module interrupt_controller(
	int_config_port,   //Configuration word (connected to an output port)
	int_flags,
	//Add more interrupts here	
	int_out 
);

input [7:0] int_config_port;
input [7:0] int_flags;

output reg int_out;

always @(*) begin
	//Add more interrupts here
	int_out = |(int_config_port & int_flags);
end
endmodule
 
`endif
