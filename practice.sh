#!/bin/sh

# get inputs:
<<comment
echo "Starting length: "
read sLength
echo "Starting length is $sLength"

echo "Ending length: "
read eLength
echo "Ending length is $eLength"

echo "Step: "
read step
echo "Step is $step"
comment

# run c program:
gcc -o cProgram sort.c
./cProgram
# c program prints the time taken
read cTime
echo "C time was $cTime"

# run python program:
python3 sort.py
# c program prints the time taken
read pythonTime
echo "Python time was $pythonTime"


