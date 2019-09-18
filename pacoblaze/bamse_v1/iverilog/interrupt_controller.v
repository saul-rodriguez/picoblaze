`ifndef INTERRUPT_CONTROLLER
`define INTERRUPT_CONTROLLER

/* interrupt_controller   
 * This module creates a single interrupt from multiple interrupt signals
 * An output port is used to read interrupt enable bits
 */

module interrupt_controller(
	int_config_port,   //Configuration word (connected to an output port)
	int0,
	int1,
	//Add more interrupts here	
	int_out 
);

input [7:0] int_config_port;
input int0;
input int1;
//Add more interrupts here
output reg int_out;

always @(*) begin
	//Add more interrupts here
	int_out = (int_config_port[0] & int0) | 
			  (int_config_port[1] & int1); 
end
endmodule

/* capture_ext_int is used to synchronize an external interrupt int_p. 
 * The syncrhonized interrupt output int_out is cleared by int_ack.
 */
module capture_ext_int(
	int_inp, //external interrupt
	rst, //reset (H)
	clk, 
	int_pos_en, //enable positive edge detection
	int_neg_en, //enable negative edge detection
	int_ack, // interrupt acknowledge
	int_out, // synchronized interrupt output	
);

input int_inp;
input rst;
input clk;
input int_pos_en;
input int_neg_en;
input int_ack;
output reg int_out;

wire up, down;
reg sync, c1, c2;

always @(posedge clk) begin
	if (rst) begin
		sync <= 0;
		c1 <= 0;
		c2 <= 0;		
	end else begin
		sync <= int_inp;
		c1 <= sync;
		c2 <= c1;	
	end
end

assign up = int_pos_en? (c1 & ~c2): 0;
assign down = int_neg_en? (~c1 & c2): 0;

always @(posedge clk) begin
	if (rst) begin
		int_out <= 0;
	end else begin
		if (int_ack) begin
			int_out <= 0;
		end else begin
			if (up | down) begin
				int_out <= 1;		 
			end
		end
	end	
end

endmodule
 
`endif
