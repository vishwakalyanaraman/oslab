echo "enter 2 values"
read a
read b
echo "enter 1 or 2"
read ch
if [ "$ch" = "1" ]; then
result=$((a + b))
elif [ "$ch" = "2" ]; then
result=$((a - b))
else
echo "equal"
fi
echo "$result"

