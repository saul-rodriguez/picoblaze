//`include "interrupt_controller"

module outport(
	address, //Port address
	value_in,	//input value
	wen, //write enable
	rst, // reset active H 
	port_out // output 
);
	parameter ADDR = 8'b0000_0000; //This parameter must be initialized during instantiation!
	
	input [7:0] address;
	input [7:0] value_in;
	input wen;
	input rst;
	output reg [7:0] port_out;

    always @(*) begin
		if (rst) begin
			port_out = 0;
		end else if (wen && (address == ADDR)) begin
			port_out = value_in;
		end 
    end
endmodule

/*  inport module is a standard digital input port. The output
 *  register port_out takes the calue of port_in only when the address
 *  input matches ADDR. port_out must be connected to a mux controlled by
 *  ADDR.
 *  NOTE: the input does not have clock syncrhonization!
 */
module inport(
	address, //Port address
	port_in, 	
	port_out,
	ren,
	rst,
	clk
);	

	//More input ports are added here. Addresses must be initalized during instantiation! 
	parameter ADDR = 8'b0000_0000; 	
	input [7:0] address;	
	input [7:0] port_in;	
	output reg [7:0] port_out;
	input ren;
	input rst;
	input clk;
		
	always @(posedge clk) begin
		if (rst) begin
			port_out <= 0;
		end else if (ren) begin
			if (address == ADDR)
				port_out <= port_in;
		end
	end
endmodule


//TODO add gio_ioc
/* gio_ioc
 * This module configures the interrupt-on-change for a input port
 * An output port is used as configuration word to mask the bits that produce ioc
 * The inputs are syncrhonized since this port is supposed to be used
 * with external signals.
 */
 
 module inport_ioc(
	address, //Port address
	port_in, 
	port_out,
	ren,
	rst,
	clk,
	ioc_pos_conf, //rising-edge detection enable 
	ioc_neg_conf, //falling-edge detection enable	
	int_out,	//Interrupt on change 
	int_ack		//Interrupt acknowledge
);	

	parameter ADDR = 8'b0000_0000; 	
	input [7:0] address;
	input [7:0] port_in;		
	output [7:0] port_out;
	input ren;
	input rst;
	input clk;
	input [7:0] ioc_pos_conf;
	input [7:0] ioc_neg_conf;	
	output reg int_out;
	input int_ack;
	
	reg [7:0] sync_port;
	reg [7:0] c1_port;
	reg [7:0] c2_port;	
	
	wire [7:0] up_port;
	wire [7:0] down_port;
	
	
	always @(posedge clk) begin
		if (rst) begin
			sync_port <= 0;
			c1_port <= 0;
			c2_port <= 0;
		end else begin //Input is syncrhonized
			sync_port <= port_in;
			c1_port <= sync_port;
			c2_port <= c1_port;						
		end
	end
	
	assign port_out = c1_port;
	
	assign up_port = c1_port & ~c2_port & ioc_pos_conf;
	assign down_port = ~c1_port & c2_port & ioc_pos_conf;
	
	always @(posedge clk) begin
		if (rst) begin
			int_out <= 0;
		end else begin
			if (int_ack) begin
				int_out <= 0;
			end else begin
				if (up_port | down_port) begin
					int_out <= 1;
				end
			end
		end
	end		

endmodule


 

