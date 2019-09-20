/* output is a standard digital output. The output is latched by wen
 *
 */
module outport(
	address, //Port address
	value_in,	//input value
	wen, //write enable
	rst, // reset active H 
	port_out // output 
);
	parameter ADDR = 8'b0000_0000; //This parameter must be initialized during instantiation!
	parameter WIDTH = 8;
	
	input [7:0] address;
	input [WIDTH-1:0] value_in;
	input wen;
	input rst;
	output reg [WIDTH-1:0] port_out;

    always @(*) begin
		if (rst) begin
			port_out = 0;
		end else if (wen && (address == ADDR)) begin
			port_out = value_in;
		end 
    end
endmodule

/*  inport module is a standard digital input port. The output
 *  register "port_out" takes the value of port_in only when the address
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
	parameter WIDTH = 8;
	
	input [7:0] address;	
	input [WIDTH-1:0] port_in;	
	output reg [WIDTH-1:0] port_out;
	input ren;
	input rst;
	input clk;
		
	always @(posedge clk) begin
		if (rst) begin
			port_out <= 0;
		//end else if (ren) begin
		//	if (address == ADDR)
		end else if (address == ADDR) begin
				port_out <= port_in;
		end
	end
endmodule

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
	int_flags
//	int_ack		//Interrupt acknowledge
);	

	parameter ADDR = 8'b0000_0000; 	
	parameter WIDTH = 3;
	
	input [7:0] address;
	input [WIDTH-1:0] port_in;		
	output [WIDTH-1:0] port_out;
	input ren;
	input rst;
	input clk;
	input [WIDTH-1:0] ioc_pos_conf;
	input [WIDTH-1:0] ioc_neg_conf;	
	output reg int_out;
	output reg [WIDTH-1:0] int_flags;
//	input int_ack;
	
	reg [WIDTH-1:0] sync_port;
	reg [WIDTH-1:0] c1_port;
	reg [WIDTH-1:0] c2_port;	
	
	reg [WIDTH-1:0] port_out; 
	
	wire [WIDTH-1:0] up_port;
	wire [WIDTH-1:0] down_port;	
	wire [WIDTH-1:0] int_detection;
		
	reg int_reset;
		
	//Synchronization 
	always @(posedge clk) begin
		if (rst) begin
			sync_port <= 0;
			c1_port <= 0;
			c2_port <= 0;
			port_out <= 0;
			int_reset <= 0;
		end else begin 
			sync_port <= port_in;
			c1_port <= sync_port;
			c2_port <= c1_port;		
		/*	if (ren) begin
				if (address == ADDR) begin
					port_out <= c1_port;
					int_reset <= 1;
				end 
			end else begin
				int_reset <= 0;
			end*/
			if (address == ADDR) begin
				port_out <= c1_port;
				if (ren) int_reset <= 1; //interrupt signal and interrupt flag is reset on a port read
			end else begin
				int_reset <= 0;	
			end 			
		end
	end
	
	assign up_port = c1_port & ~c2_port & ioc_pos_conf;
	assign down_port = ~c1_port & c2_port & ioc_neg_conf;
	assign int_detection = up_port | down_port;
	
	//Interrupt
		
	always @(posedge clk) begin
		if (rst) begin
			int_out <= 0;
			int_flags <= 0;
		end else begin
			//if (int_ack) begin
			if (int_reset) begin
				int_out <= 0;
				int_flags <= 0;
			end else begin				
				if (int_detection) begin
					int_out <= 1;
					int_flags <= int_detection;
				end
			end
		end
	end		
	
	

endmodule

//Note of in_port_selector are 7 bits, however the inputs can be of
// variable WIDTH and therefore a concat bus
// with a size 7:0 needs to be created and passed as input.
 
module in_port_selector(
	address,
	in_port0,
	in_port1,
	//add more ports here
	out_port
);

// These parameters must be initialized during instantiation!
parameter ADDR0 = 8'h00;
parameter ADDR1 = 8'h01;
//parameter ADDR2 = 8'h02;

input [7:0] address;
input [7:0] in_port0;
input [7:0] in_port1;
output reg [7:0] out_port;

always @(*) begin
	case (address) 
		ADDR0: out_port = in_port0;
		ADDR1: out_port = in_port1;
		default: out_port = 8'h00;	
	endcase	
end

endmodule
 

