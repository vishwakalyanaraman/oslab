
echo "enter name"
read name
if [ -e $name ]; then
echo "its a file"
elif [ -d $name ]; then
echo "its a directory"
fi

