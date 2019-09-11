module outport(
	address, //Port address
	value_in,	//input value
	wen, //write enable
	rst, // reset active H 
	port_out // output 
);
	parameter ADDR = 8'b0000_0000; 
	input [7:0] address;
	input [7:0] value_in;
	input wen;
	input rst;
	output reg [7:0] port_out;

    always @(*) begin
		if (rst) begin
			port_out <= 0;
		end else if (wen && (address == ADDR)) begin
			port_out <= value_in;
		end 
    end
endmodule

