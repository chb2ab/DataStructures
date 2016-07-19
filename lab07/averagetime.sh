#!/bin/bash
declare -i com=0 				#Crispin Bernier, chb2ab
declare -i it=5					#Number of trials to do
echo "Enter number of iterations: "
read e 						#Number of iterations
if [[ $e = "quit" ]] ; then
 echo quit 					#quit if input is quit
else
 for (( a=1; a<=$it; a++ )) ; do		#Loop through it times
  echo Running iteration $a...
  declare -i run=`./a.out $e | tail -1`
  echo time taken: $run ms
  com=`expr $com + $run`			#Sum up time taken
 done
 echo $it iterations took $com ms
 echo Average time was `expr $com / 5` ms	#Print output
fi
