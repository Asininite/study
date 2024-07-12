i=1
j=1

echo "Enter the number whose factorial you want to find"
read f

if [$f eq 0]
then
echo "Factorial is 1"
else
for((i=1;i<=$f;i++))
do
j=$((i * j))
done
fi

echo "$j"

