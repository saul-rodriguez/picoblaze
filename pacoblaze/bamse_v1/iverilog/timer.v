`ifndef TIMER_V
`define TIMER_V

module timer(
	input clk_in,
	input rst, //(H)
	input [2:0] prescaler_conf, //Select between 8 possible frequencies 000 -> clk_in : 111 -> clk_in/128
	input [15:0] timer_conf, // 16 bit load value for the counter 
	input en, //enable (H)
	input go, //start (H)
	input auto_load, //automatic restart timer after rolloff (H)
	input write,
	output reg tmr_int, //roll of - interrupt 1 pulse (H)
	output reg go_clear // 1 pulse (H)
);

reg [6:0] prescaler_out;
		  
//reg prescaler_state;

always @(posedge clk_in) begin
	if (rst) begin
		prescaler_out <= 0;			
	end else begin
		if (write) begin
			prescaler_out <= 0;					
		end else begin
			prescaler_out <= prescaler_out + 1;
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
		default: selected_freq = clk_in;
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
		//prescaler_reset <= 0;
		go_clear <= 0;
	end else begin 
		if (en) begin
			case (timer_state)
				IDLE:	begin
							if (go) begin 
								timer_count <= timer_conf;														
								timer_state <= GO;
								//prescaler_reset <= 1;
							end 
														
							tmr_int <= 0;
						
						end
				GO:		begin 
							//prescaler_reset <= 0;
							timer_count <= timer_count + 1;
							
							if (timer_count == 16'hffff) begin
								timer_state <= ROLL;
								go_clear <= 1;
							end							
							
							tmr_int <= 0;													
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

/**************************/
/*    TIMER BAMSE         */
/**************************/

// Configuration word (config_in and config_out)
//      B7       B6        B5       B4        B3        B2        B1        B0
//   	-        PS2      PS1       PS0      AUTO_LD    EN        GO      INT_TMR
//
// Note: GO and INT_TMR R&W bits that are set/cleared by the timer.
// 

module TIMER_BAMSE (
	input clk,
	input rst, //(H)
	input [15:0] timer_conf, // 16 bit load value for the counter 
	input [7:0] address,
	input [7:0] config_in,
	output [7:0] config_out,
	input ren,
	input wen	
);

parameter ADDR = 8'h00; // This same register address is used for read and write

reg  [7:0] timer_config_reg;
wire [1:0] mask_reset;

wire go_clear;
reg  go_clear_sync;
wire go_clear_pulse;

wire tmr_int;
reg tmr_int_sync;
wire tmr_int_pulse;

//synchronize signals from timer

always @(posedge clk) begin
	if (rst) begin
		go_clear_sync <= 0;
		tmr_int_sync <= 0;
	end else begin
		go_clear_sync <= go_clear;
		tmr_int_sync <= tmr_int;	
	end		
end

assign go_clear_pulse = go_clear & (~go_clear_sync);
assign tmr_int_pulse = tmr_int & (~tmr_int_sync);



//outputs from timer
assign mask_reset[0] = tmr_int_pulse;
assign mask_reset[1] = go_clear_pulse;

wire update_config;
assign update_config = ((address == ADDR) & wen)? 1'b1 : 1'b0;

always @(posedge clk) begin
	if (rst) begin
		timer_config_reg <= 0;
	end else if (|mask_reset) begin // Signals from timer module 
		if (mask_reset[0]) timer_config_reg[0] <= 1; // To interrupt out
		if (mask_reset[1]) timer_config_reg[1] <= 0; // To GO
	//	end	else if (address == ADDR) begin //signals written from software
	//	if (wen) begin
	end else if (update_config) begin
			timer_config_reg <= config_in;
	end				
end

assign config_out = timer_config_reg;

wire go, en, auto_load;
wire [2:0] prescaler_conf;

assign go = config_out[1];
assign en = config_out[2];
assign auto_load = config_out[3];
assign prescaler_conf[2:0] = config_out[6:4];


timer tmt(
	.clk_in(clk),
	.rst(rst),
	.prescaler_conf(prescaler_conf),
	.timer_conf(timer_conf),
	.en(en),
	.go(go),
	.auto_load(auto_load),	
	.write(wen),
	.tmr_int(tmr_int),
	.go_clear(go_clear)
);

endmodule

`endif
