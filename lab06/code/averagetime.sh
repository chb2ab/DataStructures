#!/bin/bash
echo "Enter Dictionary .txt file: " #Crispin Bernier, lab06
read dict
echo "Enter Grid .txt file"
read grid
declare -i run1=`./a.out $dict $grid | tail -1` #Get 5 values for the run time
declare -i run2=`./a.out $dict $grid | tail -1`
declare -i run3=`./a.out $dict $grid | tail -1`
declare -i run4=`./a.out $dict $grid | tail -1`
declare -i run5=`./a.out $dict $grid | tail -1`
declare -i sum=($run1+$run2+$run3+$run4+$run5)/5 #Average the 5 values
echo The average time was $sum milliseconds #Print the average, which is in milliseconds
