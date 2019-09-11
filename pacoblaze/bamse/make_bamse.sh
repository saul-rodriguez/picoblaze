iverilog -o output blockram.v pacoblaze3.v bamse.v bamse_tb.v
vvp output
#gtkwave dump.vcd 
