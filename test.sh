#!/bin/bash

echo "Please enter the value of n:"
read n
start=$(date +%s%N)
echo $n | ./1.out
end=$(date +%s%N)
time_ns=$((end - start))
time_ms=$(echo "scale=3; $time_ns / 1000000" | bc)
echo "execution time: $time_ns ns"
echo "execution time: $time_ms ms"
