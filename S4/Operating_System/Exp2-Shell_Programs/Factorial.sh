#AIM: Write a shell program to find the factorial of a number
#ALGORITHM:
#STEP 01: START
#STEP 02: Read the number from the user
#STEP 03: If the number is less than 0 then print "Error: Factorial of a negative number is not defined"
#STEP 04: Else if the number is 0 then print "Factorial of 0 is 1"
#STEP 05: Else 
#STEP 06:   For i = 1 to number do factorial = factorial * i
#STEP 07:   Print the factorial of the number
#STEP 08: STOP
#CODE:
echo "Enter a Number:"
read number
factorial=1
if ((number < 0));then
    echo "Error: Factorial of a negative number is not defined"
elif ((number == 0));then
    echo "Factorial of 0 is 1"
else
    for ((i = 1; i <= number; i++));do
        factorial=$((factorial * i))
    done
    echo "The factorial of $number is $factorial"
fi
#OUTPUT:
#Enter a Number:
#5
#The factorial of 5 is 120