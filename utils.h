#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <chrono>
#include <pthread.h>

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