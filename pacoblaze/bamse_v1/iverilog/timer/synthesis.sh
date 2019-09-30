cp template.ys $1.ys
sed -i 's/NAME/'$1'.v/g' $1.ys
yosys $1.ys


