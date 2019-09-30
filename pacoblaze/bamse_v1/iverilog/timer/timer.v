`ifndef TIMER_V
`define TIMER_V

module timer(
	clk_in,
	rst,
	prescaler_conf,
	timer_conf,
	go,
	tmr_int	
);

input clk_in;
input rst;
input [2:0] prescaler_conf;
input [15:0] timer_conf; 
input go;
output tmr_int;

reg [7:0] prescaler_out;

//Prescaler
always @(posedge clk_in) begin
	if (rst || go) begin
		prescaler_out <= 0;
	end else begin 
		prescaler_out <= prescaler_out + 1;
	end
end

//Prescaler selector

//Timer

endmodule

`endif
