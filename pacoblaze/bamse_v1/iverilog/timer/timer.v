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
	tmr_int,
	go_clear,
	address,
	ren,	
);

input clk_in;
input rst; //(H)
input [2:0] prescaler_conf; //Select between 8 possible frequencies 000 -> clk_in : 111 -> clk_in/128
input [15:0] timer_conf; // 16 bit load value for the counter 
input en; //enable (H)
input go; //start (H)
input auto_load; //automatic restart timer after rolloff (H)
output reg tmr_int; //interrupt (H)
output reg go_clear;
input [7:0] address;
input ren;

parameter ADDR = 8'b0000_0000; 

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
		  ROLL  = 2'b11,
		  WAIT  = 2'b10;


wire read_flag;
assign read_flag = (address == ADDR && ren)? 1'b1 : 1'b0;

always @(posedge selected_freq) begin
	if (rst) begin
		timer_count <= 0;					
		tmr_int <= 0;
		timer_state <= IDLE;
		prescaler_reset <= 0;
		go_clear <= 0;
	end else begin 
		if (en) begin
			case (timer_state)
				IDLE:	begin
							if (go) begin 
								timer_count <= timer_conf;														
								timer_state <= GO;
								prescaler_reset <= 1;
							end 
							
							if (read_flag) tmr_int <= 0;
						
						end
				GO:		begin 
							prescaler_reset <= 0;
							timer_count <= timer_count + 1;
							
							if (timer_count == 16'hffff) begin
								timer_state <= ROLL;
								go_clear <= 1;
							end							
							
							if (read_flag) tmr_int <= 0;													
						end
				ROLL: 	begin
							tmr_int <= 1;
							go_clear <= 0;
							if (auto_load) begin
								timer_count <= timer_conf;														
								timer_state <= GO;
							end else begin
								timer_state <= IDLE;
							end
						end				
			endcase
		end else begin
			timer_state <= IDLE;
		end
	
	end
end

endmodule

`endif
