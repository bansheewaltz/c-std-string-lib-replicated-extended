# grep suite
tmp=$1
sed 's/.*\.c:[0-9]*:/\t/g' $1 && grep 'suite' $tmp | sed 's/.*suite(s): //'