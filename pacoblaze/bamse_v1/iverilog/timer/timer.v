`ifndef TIMER_V
`define TIMER_V

module timer(
	clk_in,
	rst,
	prescaler_conf,
	timer_conf,
	en,
	go,
	auto_load,
	tmr_int	
);

input clk_in;
input rst;
input [2:0] prescaler_conf;
input [15:0] timer_conf; 
input en; //enable (H)
input go; //start (H)
input auto_load; //automatic restart timer after rolloff (H)
output reg tmr_int; //interrupt (H)

reg [6:0] prescaler_out;

//Prescaler
reg prescaler_reset;

always @(posedge clk_in) begin
	if (rst) begin
		prescaler_out <= 0;		
	end else begin
		if (en) begin
			if (prescaler_reset) begin
				prescaler_out <= 0;
			end else begin
				prescaler_out <= prescaler_out + 1;
			end		
		end
	end
end

//Prescaler selector

reg selected_freq;

always @(*) begin
	case (prescaler_conf)
		3'b000: selected_freq = clk_in;
		3'b001: selected_freq = prescaler_out[0];
		3'b010: selected_freq = prescaler_out[1];
		3'b011: selected_freq = prescaler_out[2];
		3'b100: selected_freq = prescaler_out[3];
		3'b101: selected_freq = prescaler_out[4]; 
		3'b110: selected_freq = prescaler_out[5];
		3'b111: selected_freq = prescaler_out[6];
	endcase
end

//Timer
reg [15:0] timer_count;
reg [1:0] timer_state;

parameter IDLE  = 2'b00, 
		  GO =    2'b01,
		  ROLL  = 2'b11;

always @(posedge selected_freq) begin
	if (rst) begin
		timer_count <= 0;					
		tmr_int <= 0;
		timer_state <= IDLE;
		prescaler_reset <= 0;
	end else begin 
		if (en) begin
			case (timer_state)
				IDLE:	begin
							if (go) begin 
								timer_count <= timer_conf;														
								timer_state <= GO;
								prescaler_reset <= 1;
							end else begin
								tmr_int <= 0; //When go == L the interrupt is reset
							end
						end
				GO:		begin 
							prescaler_reset <= 0;
							timer_count <= timer_count + 1;
							if (timer_count == 16'hffff) begin
								timer_state <= ROLL;
							end
							
							if (go == 0) begin
								tmr_int <= 0;
								timer_state <= IDLE;
							end
						end
				ROLL: 	begin
							tmr_int <= 1;
							if (auto_load) begin
								timer_count <= timer_conf;														
								timer_state <= GO;
							end else begin
								timer_state <= IDLE;
							end
						end
				default: timer_state <= IDLE;
			endcase
		end
	
	end
end

endmodule

`endif
