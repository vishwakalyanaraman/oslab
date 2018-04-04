a=$1
b=$2
case $1 in
'-linecount')wc -l $b;;
'-wordcount')wc -w $b;;
'-charcount')wc -c $b;;
esac
