#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <chrono>
#include <pthread.h>
#include <cmath> // ceil
#include <iomanip> // std::setprecision

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

// вспомогательные команды
// cout << "thread: " << my_rank << " rows per thread: " << rows_per_thread << " my_first_row: " << my_first_row << " my_last_row: " << my_last_row<< endl;