
//Design Name: test_timer
//Generated 2019-10-07T21:54:46.

// RAMB16BWER  : In order to incorporate this function into the design,
//   Verilog   : the following instance declaration needs to be placed
//  instance   : in the body of the design code.  The instance name
// declaration : (RAMB16BWER_inst) and/or the port declarations within the
//    code     : parenthesis may be changed to properly reference and
//             : connect this function to the design.  All inputs
//             : and outputs must be connected.

//  <-----Cut code below this line---->

   // RAMB16BWER: 16k-bit Data and 2k-bit Parity Configurable Synchronous Dual Port Block RAM with Optional Output Registers
   //             Spartan-6
   // Xilinx HDL Language Template, version 14.7
//module test_timer(address, instruction, clk, WEA);
module spartan6_mem(address, instruction, clk, WEA);

input [9:0] address;
output [17:0] instruction;
input clk;
input [3:0] WEA;

wire [31:0] DOA;
wire [3:0] DOPA;
wire [31:0] DIA;
wire [3:0] DIPA; 
wire [13:0] ADDRA;
wire [3:0] WEA;
wire ENA;
wire REGCEA;
wire RSTA;


wire [31:0] DOB;
wire [3:0] DOPB;
wire [31:0] DIB;
wire [3:0] DIPB;
wire [13:0] ADDRB;
wire WEB[3:0];
wire ENB;
wire REGCEB;
wire RSTB;

assign DIA = 32'h00000000;
assign DIPA = 4'b0000;
assign ADDRA[13:4] = address[9:0];
assign ADDRA[3:0] = 4'b0000; 
//assign WEA[3:0] = wea[3:0];
assign ENA = 1'b1;
assign REGCEA = 1'b0;
assign RSTA = 1'b0;

assign DIB = 32'h00000000;
assign DIPB = 4'b0000;
assign ADDRB = 14'h0000;
//assign WEB[3:0] = 4'b0101;
assign ENB = 1'b0;
assign REGCEB = 1'b0;
assign RSTB = 1'b0;

assign instruction[17:0] = {DOPA[1:0],DOA[15:0]};


   RAMB16BWER #(
      // DATA_WIDTH_A/DATA_WIDTH_B: 0, 1, 2, 4, 9, 18, or 36
      .DATA_WIDTH_A(18),
      .DATA_WIDTH_B(18),
      // DOA_REG/DOB_REG: Optional output register (0 or 1)
      .DOA_REG(0),
      .DOB_REG(0),
      // EN_RSTRAM_A/EN_RSTRAM_B: Enable/disable RST
      .EN_RSTRAM_A("TRUE"),
      .EN_RSTRAM_B("TRUE"),
      // INITP_00 to INITP_07: Initial memory contents.
      .INITP_00(256'h000000000000000000C44463001818FD0186E0E0F63D0F3308828A080BA80FC8),
      .INITP_01(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INITP_02(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INITP_03(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INITP_04(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INITP_05(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INITP_06(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INITP_07(256'hC000000000000000000000000000000000000000000000000000000000000000),
      // INIT_00 to INIT_3F: Initial memory contents.
      .INIT_00(256'h11C010B0A000C001A000E000C000D010610010B04005001C40040F3FE0000000),
      .INIT_01(256'h0C000B00E0010000A0001B00400AA000C00A10B0A000C30C04011310C20B1200),
      .INIT_02(256'h403454304000E20102004027542B410061010000000C00060B2000160B7E000E),
      .INIT_03(256'hA02010101100CF01F1F04000CF01F0F04027C20502FF00014027C20502000000),
      .INIT_04(256'h1B0010201230A3FE1300CF01F3F010201200CF01F2F010B00019405354434000),
      .INIT_05(256'h0000000000000000800170F08F0171F08F0172F08F0173F08F01E00100010016),
      .INIT_06(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_07(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_08(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_09(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_0A(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_0B(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_0C(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_0D(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_0E(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_0F(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_10(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_11(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_12(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_13(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_14(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_15(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_16(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_17(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_18(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_19(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_1A(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_1B(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_1C(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_1D(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_1E(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_1F(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_20(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_21(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_22(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_23(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_24(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_25(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_26(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_27(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_28(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_29(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_2A(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_2B(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_2C(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_2D(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_2E(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_2F(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_30(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_31(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_32(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_33(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_34(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_35(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_36(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_37(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_38(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_39(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_3A(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_3B(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_3C(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_3D(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_3E(256'h0000000000000000000000000000000000000000000000000000000000000000),
      .INIT_3F(256'h4038000000000000000000000000000000000000000000000000000000000000),
      // INIT_A/INIT_B: Initial values on output port
      .INIT_A(36'h000000000),
      .INIT_B(36'h000000000),
      // INIT_FILE: Optional file used to specify initial RAM contents
      .INIT_FILE("NONE"),
      // RSTTYPE: "SYNC" or "ASYNC" 
      .RSTTYPE("SYNC"),
      // RST_PRIORITY_A/RST_PRIORITY_B: "CE" or "SR" 
      .RST_PRIORITY_A("CE"),
      .RST_PRIORITY_B("CE"),
      // SIM_COLLISION_CHECK: Collision check enable "ALL", "WARNING_ONLY", "GENERATE_X_ONLY" or "NONE" 
      .SIM_COLLISION_CHECK("ALL"),
      // SIM_DEVICE: Must be set to "SPARTAN6" for proper simulation behavior
      //.SIM_DEVICE("SPARTAN3ADSP"),
      .SIM_DEVICE("SPARTAN6"),
      // SRVAL_A/SRVAL_B: Set/Reset value for RAM output
      .SRVAL_A(36'h000000000),
      .SRVAL_B(36'h000000000),
      // WRITE_MODE_A/WRITE_MODE_B: "WRITE_FIRST", "READ_FIRST", or "NO_CHANGE" 
      .WRITE_MODE_A("WRITE_FIRST"),
      .WRITE_MODE_B("WRITE_FIRST") 
   )
   RAMB16BWER_inst (
      // Port A Data: 32-bit (each) output: Port A data
      .DOA(DOA),       // 32-bit output: A port data output
      .DOPA(DOPA),     // 4-bit output: A port parity output
      // Port B Data: 32-bit (each) output: Port B data
      .DOB(DOB),       // 32-bit output: B port data output
      .DOPB(DOPB),     // 4-bit output: B port parity output
      // Port A Address/Control Signals: 14-bit (each) input: Port A address and control signals
      .ADDRA(ADDRA),   // 14-bit input: A port address input
      .CLKA(clk),     // 1-bit input: A port clock input
      .ENA(ENA),       // 1-bit input: A port enable input
      .REGCEA(REGCEA), // 1-bit input: A port register clock enable input
      .RSTA(RSTA),     // 1-bit input: A port register set/reset input
      .WEA(WEA),       // 4-bit input: Port A byte-wide write enable input
      // Port A Data: 32-bit (each) input: Port A data
      .DIA(DIA),       // 32-bit input: A port data input
      .DIPA(DIPA),     // 4-bit input: A port parity input
      // Port B Address/Control Signals: 14-bit (each) input: Port B address and control signals
      .ADDRB(ADDRB),   // 14-bit input: B port address input
      .CLKB(clk),     // 1-bit input: B port clock input
      .ENB(ENB),       // 1-bit input: B port enable input
      .REGCEB(REGCEB), // 1-bit input: B port register clock enable input
      .RSTB(RSTB),     // 1-bit input: B port register set/reset input
      .WEB(4'b0000),       // 4-bit input: Port B byte-wide write enable input
      // Port B Data: 32-bit (each) input: Port B data
      .DIB(DIB),       // 32-bit input: B port data input
      .DIPB(DIPB)      // 4-bit input: B port parity input
   );

   // End of RAMB16BWER_inst instantiation
endmodule
			
				

