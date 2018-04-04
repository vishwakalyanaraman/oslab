argv=( "$@" )
for((i=0;i<=$#;i++));do
for((j=i;j<=$#-1;j++));do
if [[ ${argv[$i]} > ${argv[$j]} ]]; then
temp=${argv[$j]}
argv[$j]=${argv[$i]}
argv[$i]=$temp
fi
done
done
echo ${argv[@]} 





