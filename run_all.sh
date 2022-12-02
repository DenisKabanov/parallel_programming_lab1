#!/bin/bash
g++ alg1_no_par.cpp -o alg1_no_par.out
./alg1_no_par.out array2.txt array1.txt
# ./alg1_non_par.out arr1024x1024.txt arr1024x1024.txt
g++ alg1_par.cpp -lpthread -o alg1_par.out
./alg1_par.out array2.txt array1.txt 2