#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <chrono>
#include <pthread.h>
#include <cmath> // ceil
#include <iomanip> // std::setprecision
#include <cmath> // sqrt

using namespace std;
using namespace std::chrono;

int** read_file(string path, int &rows, int &cols){ // функция, возвращающая массив
    string s;
    ifstream file;
    file.open(path, ifstream::in);
    getline(file, s);
    stringstream ss(s);
    getline(ss, s, ' ');
    rows = stoi(s);
    getline(ss, s, ' ');
    cols = stoi(s);
    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i){
        arr[i] = new int[cols];
        getline(file, s);
        stringstream ss(s);
        for (int j = 0; j < cols; ++j){
            getline(ss, s, ' ');
            arr[i][j] = stoi(s);
        }
    }
    file.close();
    return arr;
}

void print_arr(int **array, size_t rows, size_t cols){
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
            cout << array[i][j] << " ";
        cout << endl;
    }
}

void free_arr(int **array, size_t rows){
    for(int i = 0; i < rows; ++i)
        delete[] array[i];
    delete[] array;
}

void free_arrs(int **arrayA, int **arrayB, int **arrayC, size_t rows_A, size_t rows_B){ // освобождение памяти
    for(int i = 0; i < rows_A; ++i){
        delete[] arrayA[i];
        delete[] arrayC[i];
    }
    for(int i = 0; i < rows_B; ++i)
        delete[] arrayB[i];

    delete[] arrayA;
    delete[] arrayB;
    delete[] arrayC;
}

void degree(int number, int &res){ // получение степени двойки
    int i = 0;
    while (number / 2 != 0){
        if ((float)number / 2 != number / 2)
            throw runtime_error("Please, set thread_count to 2 in an even degree");
        number = number / 2;
        i++;
    }
    res = i;
}

// вспомогательные команды
// cout << "thread: " << my_rank << " rows per thread: " << rows_per_thread << " my_first_row: " << my_first_row << " my_last_row: " << my_last_row<< endl;

// int*** temp_arr = new int**[cols_A]; // массив для избежания data race 
// for (int i = 0; i < cols_A; ++i) {
//     temp_arr[i] = new int*[cols_B];
//     for(int j = 0; j < cols_B; ++j){
//         temp_arr[i][j] = new int[rows_A];
//         for(int k = 0; k < rows_A; ++k)
//             temp_arr[i][j][k] = 0;
//     }
// }

// for(int i = 0; i < cols_A; ++i) {
//     for(int j = 0; j < cols_B; ++j){
//         for(int k = 0; k < rows_A; ++k){
//             //cout << "i:" << i << " j: " << j << " k: " << k << endl;
//             cout << temp_arr[i][j][k] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl << endl;
// }