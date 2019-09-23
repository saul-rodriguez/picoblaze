wine bin/sdcc.exe $1.c -mpblaze -S --dialect=kcpsm3 --verbose -I"device/include/pblaze/"
sed -i 's/__interrupt_handler/_interrupt_handler/g' $1.psm
