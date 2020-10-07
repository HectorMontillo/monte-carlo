#!/bin/bash
echo "Bash version ${BASH_VERSION}..."

for n in {1..5}
  do
    echo "Bench #$n"
    printf "nneedles\ttime(seq)\tpi(seq)\ttime(fork)\tpi(fork)\ttime(th)\tpi(th)\n"
    for i in {100000..1000000000..100000}
      do 
        ./needles $i
        ./needles_process $i
        ./needles_threads $i
        
done
done