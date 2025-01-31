#AIM: Write a shell program to check whether a year is a leap year or not
#ALGORITHM:
#STEP 01: START
#STEP 02: Read the year from the user
#STEP 03: If the year is divisible by 400 then print the year is a leap year
#STEP 04: Else if the year is divisible by 100 then print the year is not a leap year
#STEP 05: Else if the year is divisible by 4 then print the year is a leap year
#STEP 06: Else print the year is not a leap year
#STEP 07: STOP
#CODE:
echo "Enter a Year:"
read year
if ((year % 400 == 0));then
    echo "$year is a Leap Year"
elif ((year % 100 == 0));then
    echo "$year is not a Leap Year"
elif ((year % 4 == 0));then
    echo "$year is a Leap Year"
else
    echo "$year is not a Leap Year"
fi
#OUTPUT:
#Enter a Year:
#2004
#2004 is a Leap Year