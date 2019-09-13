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

module inport(
	address, //Port address
	port0_in, 
	//port1_in, //More ports need to be manually added here
	value_out,
	ren,
	rst,
	clk
);	

	//More input ports are added here. Addresses must be initalized during instantiation! 
	parameter ADDR0 = 8'b0000_0000; 
	//parameter ADDR1 = 8'b0000_0001; 
	input [7:0] port0_in;
	//input [7:0] port1_in;
		
	input [7:0] address;	
	output reg [7:0] value_out;
	input ren;
	input rst;
	input clk;
		
	always @(posedge clk) begin
		if (rst) begin
			value_out <= 0;
		end else if (ren) begin
			case (address) 
				ADDR0:  value_out <= port0_in;						
		//		ADDR1:	value_out <= port1_in;
				//More ports need to be added here:						
				default: value_out <= 8'b0000_0000;	
		    endcase					
		end
	end
endmodule

