echo "enter a number"
read number
echo "enterd number is $number"
sum=`expr $number + 5`
sum2=$((number + 5))
sum3=`bc -l<<<$number+5`
echo "sum=$sum sum2=$sum2 sum3=$sum3"
