#!/bin/bash
echo "Bash version ${BASH_VERSION}..."

for n in {1..5}
  do
    echo "Bench #$n"
    printf "niter\tndarts\tdiff\t\tpi\n"
    for i in {1000..1000000..1000}
      do 
        ./dartboard 10 $i
done
done