echo "enter bascis and ta"
read b
read t
sum=`bc -l<<<$b+$t+0.1*$b`
echo "GS=$sum"
