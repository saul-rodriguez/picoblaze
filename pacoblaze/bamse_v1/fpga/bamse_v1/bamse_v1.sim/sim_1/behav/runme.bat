@echo off


rem  PlanAhead(TM)
rem  runme.bat: a PlanAhead-generated ISim simulation Script
rem  Copyright 1986-1999, 2001-2013 Xilinx, Inc. All Rights Reserved.


set PATH=$XILINX/lib/$PLATFORM:$XILINX/bin/$PLATFORM;/pkg/Xilinx/14.7/ISE_DS/EDK/bin/lin64:/pkg/Xilinx/14.7/ISE_DS/ISE/bin/lin64:/pkg/Xilinx/14.7/ISE_DS/common/bin/lin64;/pkg/Xilinx/14.7/ISE_DS/EDK/lib/lin64:/pkg/Xilinx/14.7/ISE_DS/ISE/lib/lin64:/pkg/Xilinx/14.7/ISE_DS/common/lib/lin64;/pkg/Xilinx/14.7/ISE_DS/PlanAhead/bin;%PATH%

set XILINX_PLANAHEAD=/pkg/Xilinx/14.7/ISE_DS/PlanAhead

fuse -intstyle pa -incremental --include /home/saul/projects/picoblaze/pacoblaze/bamse_v1/fpga/bamse_v1/bamse_v1.srcs/sources_1/imports/iverilog -L work -L unisims_ver -L unimacro_ver -L xilinxcorelib_ver -L secureip -o top_tb.exe --prj /home/saul/projects/picoblaze/pacoblaze/bamse_v1/fpga/bamse_v1/bamse_v1.sim/sim_1/behav/top_tb.prj -top work.top_tb -top work.glbl
if errorlevel 1 (
   cmd /c exit /b %errorlevel%
)
