iverilog -o output blockram.v pacoblaze3.v pacoblaze3_tb.v
vvp output
#gtkwave dump.vcd 

