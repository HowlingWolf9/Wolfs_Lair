#AIM: Write a shell program to check whether a number is even or odd.
#ALGORITHM:
#STEP 01: START
#STEP 02: Read the number from the user
#STEP 03: If the number is divisible by 2 then print the number is even
#STEP 04: Else print the number is odd
#STEP 05: STOP
#CODE:
echo "Enter a Number:"
read number
if ((number % 2 == 0));then
	echo "The number $number is Even"
else
	echo "The number $number is Odd"
fi
#OUTPUT:
#Enter a Number:
#25
#The number 25 is Odd