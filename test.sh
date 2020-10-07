#!/bin/bash
echo "Bash version ${BASH_VERSION}..."

for n in {1..5}
  do
    echo "Bench #$n"
    printf "ndarts\ttime(seq)\tpi(seq)\ttime(fork)\tpi(fork)\n"
    for i in {100000..1000000000..100000}
      do 
        ./dartboard 10 $i
        ./dartboard_process 10 $i
        ./dartboard_threads 10 $i
done
done