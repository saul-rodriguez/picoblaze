//io_bamse.v

`ifndef IO_BAMSE
`define IO_BAMSE

`include "bamse_inc.v"
`include "gio.v"
`include "usart.v"
`include "timer.v"
 
module io_bamse(
    //Ports 
	PortA,
	PortB,
	PortC,	
	TxUART,
	RxUART,
	//Pacoblaze pins
	port_id,  //from port address in Pacoblaze
	port_out,  // to input port in Pacoblaze 
	port_in, // from output port in Pacoblaze
	interrupt, // to interrupt in Pacoblaze 
	clk,
	rst,
	wen,
	ren
);

input  [`PORTA_IN_WIDTH-1:0] PortA;
input  [`PORTB_IN_WIDTH-1:0] PortB;
output [`PORTC_OUT_WIDTH-1:0] PortC;
output TxUART;
input  RxUART;	
	//Pacoblaze pins
input [7:0]	port_id;
output [7:0] port_out;
input [7:0]	port_in;
output interrupt;
//output 
//input  interrupt_ack;
input clk;
input rst;
input wen;
input ren;

/******************/
/***** PORTA ******/
/******************/

wire [`PORTA_IN_WIDTH-1:0] portA_IOC_Pos_bus;

//IOC Configuration register rising edge 
outport #(.ADDR(`PORTA_IOC_POS_CONF), .WIDTH(`PORTA_IN_WIDTH)) PortA_IOC_Pos_Conf(
	.address(port_id),
	.value_in(port_in[`PORTA_IN_WIDTH-1:0]),
	.wen(wen),
	.rst(rst),
	.port_out(portA_IOC_Pos_bus)	
);

//IOC Configuration register falling edge
wire [`PORTA_IN_WIDTH-1:0] portA_IOC_Neg_bus;

outport #(.ADDR(`PORTA_IOC_NEG_CONF), .WIDTH(`PORTA_IN_WIDTH)) PortA_IOC_Neg_Conf(
	.address(port_id),
	.value_in(port_in[`PORTA_IN_WIDTH-1:0]),
	.wen(wen),
	.rst(rst),
	.port_out(portA_IOC_Neg_bus)	
);

//Port A input
wire [`PORTA_IN_WIDTH-1:0] portA_bus;
wire [`PORTA_IN_WIDTH-1:0] ioc_flags;

inport_ioc #(.ADDR(`PORTA_IN), .WIDTH(`PORTA_IN_WIDTH)) Port_A (
	.address(port_id),
	.port_in(PortA),
	.port_out(portA_bus),
	.ren(ren),
	.rst(rst),
	.clk(clk),
	.ioc_pos_conf(portA_IOC_Pos_bus),
	.ioc_neg_conf(portA_IOC_Neg_bus),
	//.int_out(interrupt),
	.int_flags(ioc_flags)
	//.int_ack(interrupt_ack)
);

wire [7:0] portA_bus_8;
assign portA_bus_8 = {{(8-`PORTA_IN_WIDTH){1'b0}},portA_bus};

/****************/
/**** PORTB *****/
/****************/

wire [`PORTB_IN_WIDTH-1:0] portB_bus;

inport #(.ADDR(`PORTB_IN), .WIDTH(`PORTB_IN_WIDTH)) Port_B(
	.address(port_id),
	.port_in(PortB),
	.port_out(portB_bus),
	.ren(ren),
	.rst(rst),
	.clk(clk)	
);

wire [7:0] portB_bus_8;
assign portB_bus_8 = {{(8-`PORTB_IN_WIDTH){1'b0}},portB_bus};

/****************/
/**** PORTC *****/
/****************/

outport #(.ADDR(`PORTC_OUT), .WIDTH(`PORTC_OUT_WIDTH)) Port_C(
	.address(port_id),
	.value_in(port_in[`PORTC_OUT_WIDTH-1:0]),
	.wen(wen),
	.rst(rst),
	.port_out(PortC)	
);

/*******************/
/****** UART *******/
/*******************/

// Configuration registers
// UART_OUT_CONFIG_H                      UART_OUT_CONFIG_L
// 7   6   5   4   3   2   1   0    7   6   5   4   3   2   1   0
//                 CB11----------------------------------------CB0 


// RX
wire [7:0] uart_config_l;

outport #(.ADDR(`UART_OUT_CONFIG_L)) UART_Config_L(
	.address(port_id),
	.value_in(port_in),
	.wen(wen),
	.rst(rst),
	.port_out(uart_config_l)	
);

wire [7:0] uart_config_h;

outport #(.ADDR(`UART_OUT_CONFIG_H)) UART_Config_H(
	.address(port_id),
	.value_in(port_in),
	.wen(wen),
	.rst(rst),
	.port_out(uart_config_h)	
);

wire [11:0] clk_per_bit;
wire [7:0] uart_rx_bus_8; 
wire uart_rx_int_flag;

assign clk_per_bit[11:0] = {uart_config_h[3:0],uart_config_l};

USART_RX_BAMSE #(.ADDR(`UART_RX)) rx_uart(
	.rst(rst),
	.rx(RxUART),
	.clk(clk),
	.clk_per_bit(clk_per_bit),
	.port_out(uart_rx_bus_8),	
	.address(port_id),		
	.ren(ren),
	.int_rx(uart_rx_int_flag)
);

// TX

wire [7:0] uart_tx_data;

outport #(.ADDR(`UART_TX)) UART_TX(
	.address(port_id),
	.value_in(port_in),
	.wen(wen),
	.rst(rst),
	.port_out(uart_tx_data)	
);

wire uart_tx_int_flag;

wire start_tx;
assign start_tx = (port_id == `UART_TX && wen) ? 1'b1 : 1'b0;

UART_TX tx_uart( 
	  .i_Rst_H(rst),
      .i_Clock(clk),
      .i_TX_DV(start_tx),
	  .i_TX_Byte(uart_tx_data),
	  .i_Clk_per_bit(clk_per_bit),
	  .o_TX_Active_L(uart_tx_int_flag),
	  .o_TX_Serial(TxUART),
	  .o_TX_Done()
   );

/******************/
/**** TIMER0 ******/
/******************/

//Timer LREG
wire [7:0] timer0_lreg;

outport #(.ADDR(`TIMER0_LREG)) Timer0_LREG(
	.address(port_id),
	.value_in(port_in),
	.wen(wen),
	.rst(rst),
	.port_out(timer0_lreg)	
);

//Timer HREG
wire [7:0] timer0_hreg;

outport #(.ADDR(`TIMER0_HREG)) Timer0_HREG(
	.address(port_id),
	.value_in(port_in),
	.wen(wen),
	.rst(rst),
	.port_out(timer0_hreg)	
);

//Timer module
wire [15:0] timer_conf;
assign timer_conf = {timer0_hreg,timer0_lreg};

wire [7:0] timer0_bus_8;

TIMER_BAMSE #(.ADDR(`TIMER0)) timer0(
	.clk(clk),
	.rst(rst),	
	.timer_conf(timer_conf),
	.address(port_id),
	.config_in(port_in),
	.config_out(timer0_bus_8),
	.ren(ren),
	.wen(wen)
);

/******************/
/*** INTERRUPTS ***/
/******************/

// Interrupt bits order in IntCon and inflags
//  B7     B6     B5     B4      B3     B2     B1     B0
//  -      -      TMR0 TX_UART RX_UART  IOC2  IOC1   IOC0

//Iterrupt enable config
wire [7:0] interrupt_enable; 

outport #(.ADDR(`INT_OUT_CONFIG)) IntCon(
	.address(port_id),
	.value_in(port_in[7:0]),
	.wen(wen),
	.rst(rst),
	.port_out(interrupt_enable)	
); 

//Iterrupt flags are assigned here
wire [7:0] interrupt_flags;  

assign interrupt_flags[7] = 0;
assign interrupt_flags[6] = 0;
assign interrupt_flags[5] = timer0_bus_8[0];
assign interrupt_flags[4] = uart_tx_int_flag;
assign interrupt_flags[3] = uart_rx_int_flag;
assign interrupt_flags[2] = ioc_flags[2];
assign interrupt_flags[1] = ioc_flags[1];
assign interrupt_flags[0] = ioc_flags[0];

wire [7:0] interruptFlags_bus_8;

inport #(.ADDR(`INT_IN_FLAGS)) intflags(
	.address(port_id),
	.port_in(interrupt_flags),
	.port_out(interruptFlags_bus_8),
	.ren(ren),
	.rst(rst),
	.clk(clk)	
);

//Interrupt generation
assign interrupt = | ( interrupt_flags & interrupt_enable);

/****************/
/* INPUT MUX    */
/****************/

in_port_selector #(.ADDR0(`INT_IN_FLAGS), 
                   .ADDR1(`PORTA_IN), 
                   .ADDR2(`PORTB_IN),
                   .ADDR3(`UART_RX),
                   .ADDR4(`TIMER0))
	input_ports(
		.address(port_id),
		.in_port0(interruptFlags_bus_8),
		.in_port1(portA_bus_8),
		.in_port2(portB_bus_8),
		.in_port3(uart_rx_bus_8),
		.in_port4(timer0_bus_8),
		.out_port(port_out)
);


endmodule

`endif

