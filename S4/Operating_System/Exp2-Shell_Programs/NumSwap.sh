#AIM: Write a shell program to swap two numbers
#ALGORITHM:
#STEP 01: START
#STEP 02: Read the first number from the user
#STEP 03: Read the second number from the user
#STEP 04: Print the numbers before swapping
#STEP 05: Swap the numbers using a temporary variable
#STEP 06: Print the numbers after swapping
#STEP 07: STOP
#CODE:
echo "Enter the first number:"
read a
echo "Enter the second number:"
read b
echo "Before Swapping: a = $a and b = $b"
temp=$a
a=$b
b=$temp
echo "After Swapping: a = $a and b = $b"
#OUTPUT:
#Enter the first number:
#25
#Enter the second number:
#69
#Before Swapping: a = 25 and b = 69
#After Swapping: a = 69 and b = 25