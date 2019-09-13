iverilog -o output blockram.v pacoblaze3.v bamse.v top.v $1
vvp output
#gtkwave dump.vcd 
