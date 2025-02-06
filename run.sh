#!/bin/bash

gcc ./HITOSIS_JM_EXER1.c -lm

for i in 100 200 300 400 500 600 700 800 900 1000 2000 4000 8000 16000 20000 40000 50000 100000
  do 
    echo "n = $i"
    ./a.out $i
    ./a.out $i
    ./a.out $i
  done
