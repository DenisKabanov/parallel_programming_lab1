#!/bin/bash
# g++ alg1_no_par.cpp -o exe/alg1_no_par.exe
# ./exe/alg1_no_par.exe arrs/array1.txt arrs/array2.txt
# ./exe/alg1_no_par.exe arrs/arr64x64.txt arrs/arr64x64.txt
# ./exe/alg1_no_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt

g++ alg1_par.cpp -lpthread -o exe/alg1_par.exe -fpermissive
./exe/alg1_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 1 >> results/res64x64_alg1_th1.txt
./exe/alg1_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 2 >> results/res64x64_alg1_th2.txt
./exe/alg1_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 4 >> results/res64x64_alg1_th4.txt
./exe/alg1_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 8 >> results/res64x64_alg1_th8.txt
./exe/alg1_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 16 >> results/res64x64_alg1_th16.txt
./exe/alg1_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 32 >> results/res64x64_alg1_th32.txt
./exe/alg1_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 64 >> results/res64x64_alg1_th64.txt

./exe/alg1_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 1 >> results/res128x128_alg1_th1.txt
./exe/alg1_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 2 >> results/res128x128_alg1_th2.txt
./exe/alg1_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 4 >> results/res128x128_alg1_th4.txt
./exe/alg1_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 8 >> results/res128x128_alg1_th8.txt
./exe/alg1_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 16 >> results/res128x128_alg1_th16.txt
./exe/alg1_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 32 >> results/res128x128_alg1_th32.txt
./exe/alg1_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 64 >> results/res128x128_alg1_th64.txt

./exe/alg1_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 1 >> results/res256x256_alg1_th1.txt
./exe/alg1_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 2 >> results/res256x256_alg1_th2.txt
./exe/alg1_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 4 >> results/res256x256_alg1_th4.txt
./exe/alg1_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 8 >> results/res256x256_alg1_th8.txt
./exe/alg1_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 16 >> results/res256x256_alg1_th16.txt
./exe/alg1_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 32 >> results/res256x256_alg1_th32.txt
./exe/alg1_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 64 >> results/res256x256_alg1_th64.txt

./exe/alg1_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 1 >> results/res512x512_alg1_th1.txt
./exe/alg1_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 2 >> results/res512x512_alg1_th2.txt
./exe/alg1_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 4 >> results/res512x512_alg1_th4.txt
./exe/alg1_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 8 >> results/res512x512_alg1_th8.txt
./exe/alg1_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 16 >> results/res512x512_alg1_th16.txt
./exe/alg1_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 32 >> results/res512x512_alg1_th32.txt
./exe/alg1_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 64 >> results/res512x512_alg1_th64.txt

./exe/alg1_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 1 >> results/res1024x1024_alg1_th1.txt
./exe/alg1_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 2 >> results/res1024x1024_alg1_th2.txt
./exe/alg1_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 4 >> results/res1024x1024_alg1_th4.txt
./exe/alg1_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 8 >> results/res1024x1024_alg1_th8.txt
./exe/alg1_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 16 >> results/res1024x1024_alg1_th16.txt
./exe/alg1_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 32 >> results/res1024x1024_alg1_th32.txt
./exe/alg1_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 64 >> results/res1024x1024_alg1_th64.txt

# # __________________________________________
# # 2й алгоритм

g++ alg2_par.cpp -lpthread -o exe/alg2_par.exe -fpermissive
./exe/alg2_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 1 >> results/res64x64_alg2_th1.txt
./exe/alg2_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 2 >> results/res64x64_alg2_th2.txt
./exe/alg2_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 4 >> results/res64x64_alg2_th4.txt
./exe/alg2_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 8 >> results/res64x64_alg2_th8.txt
./exe/alg2_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 16 >> results/res64x64_alg2_th16.txt
./exe/alg2_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 32 >> results/res64x64_alg2_th32.txt
./exe/alg2_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 64 >> results/res64x64_alg2_th64.txt

./exe/alg2_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 1 >> results/res128x128_alg2_th1.txt
./exe/alg2_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 2 >> results/res128x128_alg2_th2.txt
./exe/alg2_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 4 >> results/res128x128_alg2_th4.txt
./exe/alg2_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 8 >> results/res128x128_alg2_th8.txt
./exe/alg2_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 16 >> results/res128x128_alg2_th16.txt
./exe/alg2_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 32 >> results/res128x128_alg2_th32.txt
./exe/alg2_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 64 >> results/res128x128_alg2_th64.txt

./exe/alg2_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 1 >> results/res256x256_alg2_th1.txt
./exe/alg2_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 2 >> results/res256x256_alg2_th2.txt
./exe/alg2_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 4 >> results/res256x256_alg2_th4.txt
./exe/alg2_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 8 >> results/res256x256_alg2_th8.txt
./exe/alg2_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 16 >> results/res256x256_alg2_th16.txt
./exe/alg2_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 32 >> results/res256x256_alg2_th32.txt
./exe/alg2_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 64 >> results/res256x256_alg2_th64.txt

./exe/alg2_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 1 >> results/res512x512_alg2_th1.txt
./exe/alg2_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 2 >> results/res512x512_alg2_th2.txt
./exe/alg2_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 4 >> results/res512x512_alg2_th4.txt
./exe/alg2_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 8 >> results/res512x512_alg2_th8.txt
./exe/alg2_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 16 >> results/res512x512_alg2_th16.txt
./exe/alg2_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 32 >> results/res512x512_alg2_th32.txt
./exe/alg2_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 64 >> results/res512x512_alg2_th64.txt

./exe/alg2_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 1 >> results/res1024x1024_alg2_th1.txt
./exe/alg2_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 2 >> results/res1024x1024_alg2_th2.txt
./exe/alg2_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 4 >> results/res1024x1024_alg2_th4.txt
./exe/alg2_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 8 >> results/res1024x1024_alg2_th8.txt
./exe/alg2_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 16 >> results/res1024x1024_alg2_th16.txt
./exe/alg2_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 32 >> results/res1024x1024_alg2_th32.txt
./exe/alg2_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 64 >> results/res1024x1024_alg2_th64.txt


# g++ alg2_no_par.cpp -o exe/alg2_no_par.exe
# ./exe/alg2_no_par.exe arrs/array1.txt arrs/array2.txt
# ./exe/alg2_no_par.exe arrs/arr64x64.txt arrs/arr64x64.txt
# ./exe/alg2_no_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt

# g++ alg2_par.cpp -lpthread -o exe/alg2_par.exe
# ./exe/alg2_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 8

# __________________________________________
# 3й алгоритм

g++ alg3_par.cpp -lpthread -o exe/alg3_par.exe -fpermissive
./exe/alg3_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 1 >> results/res64x64_alg3_th1.txt
./exe/alg3_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 2 >> results/res64x64_alg3_th2.txt
./exe/alg3_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 4 >> results/res64x64_alg3_th4.txt
./exe/alg3_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 8 >> results/res64x64_alg3_th8.txt
./exe/alg3_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 16 >> results/res64x64_alg3_th16.txt
./exe/alg3_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 32 >> results/res64x64_alg3_th32.txt
./exe/alg3_par.exe arrs/arr64x64.txt arrs/arr64x64.txt 64 >> results/res64x64_alg3_th64.txt

./exe/alg3_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 1 >> results/res128x128_alg3_th1.txt
./exe/alg3_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 2 >> results/res128x128_alg3_th2.txt
./exe/alg3_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 4 >> results/res128x128_alg3_th4.txt
./exe/alg3_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 8 >> results/res128x128_alg3_th8.txt
./exe/alg3_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 16 >> results/res128x128_alg3_th16.txt
./exe/alg3_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 32 >> results/res128x128_alg3_th32.txt
./exe/alg3_par.exe arrs/arr128x128.txt arrs/arr128x128.txt 64 >> results/res128x128_alg3_th64.txt

./exe/alg3_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 1 >> results/res256x256_alg3_th1.txt
./exe/alg3_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 2 >> results/res256x256_alg3_th2.txt
./exe/alg3_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 4 >> results/res256x256_alg3_th4.txt
./exe/alg3_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 8 >> results/res256x256_alg3_th8.txt
./exe/alg3_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 16 >> results/res256x256_alg3_th16.txt
./exe/alg3_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 32 >> results/res256x256_alg3_th32.txt
./exe/alg3_par.exe arrs/arr256x256.txt arrs/arr256x256.txt 64 >> results/res256x256_alg3_th64.txt

./exe/alg3_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 1 >> results/res512x512_alg3_th1.txt
./exe/alg3_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 2 >> results/res512x512_alg3_th2.txt
./exe/alg3_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 4 >> results/res512x512_alg3_th4.txt
./exe/alg3_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 8 >> results/res512x512_alg3_th8.txt
./exe/alg3_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 16 >> results/res512x512_alg3_th16.txt
./exe/alg3_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 32 >> results/res512x512_alg3_th32.txt
./exe/alg3_par.exe arrs/arr512x512.txt arrs/arr512x512.txt 64 >> results/res512x512_alg3_th64.txt

./exe/alg3_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 1 >> results/res1024x1024_alg3_th1.txt
./exe/alg3_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 2 >> results/res1024x1024_alg3_th2.txt
./exe/alg3_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 4 >> results/res1024x1024_alg3_th4.txt
./exe/alg3_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 8 >> results/res1024x1024_alg3_th8.txt
./exe/alg3_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 16 >> results/res1024x1024_alg3_th16.txt
./exe/alg3_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 32 >> results/res1024x1024_alg3_th32.txt
./exe/alg3_par.exe arrs/arr1024x1024.txt arrs/arr1024x1024.txt 64 >> results/res1024x1024_alg3_th64.txt


# g++ alg3_par.cpp -o exe/alg3_par.exe -fpermissive
# ./exe/alg3_par.exe arrs/array1.txt arrs/array2.txt

# execution example:
# bash ./run_all.sh > results/1024x1024.txt