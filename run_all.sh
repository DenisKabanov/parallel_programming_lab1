#!/bin/bash
g++ alg1_no_par.cpp -o exe/alg1_no_par.out
./exe/alg1_no_par.out arrs/array1.txt arrs/array2.txt
# ./exe/alg1_non_par.out arrs/arr1024x1024.txt arrs/arr1024x1024.txt




# g++ alg1_par.cpp -lpthread -o exe/alg1_par.out
# ./exe/alg1_par.out arrs/array1.txt arrs/array2.txt 2
# ./exe/alg1_par.out arrs/arr1024x1024.txt arrs/arr1024x1024.txt 32

# g++ alg2_no_par.cpp -o exe/alg2_no_par.out
# ./exe/alg2_no_par.out arrs/arr64x64.txt arrs/arr64x64.txt