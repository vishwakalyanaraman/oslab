echo "enter 2 values"
read a
read b
echo "enter operator(+,-,/,*,%)"
read op
result=$((a $op b))
echo "result is $result"


