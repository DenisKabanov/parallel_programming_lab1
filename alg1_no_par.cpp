#include "utils.h"

int rows_A, cols_A, rows_B, cols_B;
int** A;
int** B;
int** C;

int main(int argc, char* argv[]) {
    if (argc < 3) // проверка наличия аргументов (сама программа + файл1 + файл2)
        throw runtime_error("The program must have arguments!");

    A = read_file(argv[1], rows_A, cols_A);
    B = read_file(argv[2], rows_B, cols_B);
    C = new int*[rows_A];
    for (int i = 0; i < rows_A; ++i) {
        C[i] = new int[cols_B];
        for(int j = 0; j < cols_B; ++j)
            C[i][j] = 0;
    }
    

    auto start = high_resolution_clock::now();

    for(int i = 0; i < rows_A; ++i){ //сколько будет строк
        for(int j = 0; j < cols_B; ++j){ //сколько будет столбцов
            for(int k = 0; k < cols_A; ++k){ //проходим по всей соответствующей строке i в A (столбцу j в B). Идём по числу столбцов в A = числу строк в B (так как строка умножается на столбец, следовательно делаем сложений = длина строки раз (то же самое, что и число столбцов A или число строк B))
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Alg 1: row by column multiplication without parallel execution" << endl;
    // cout << "Matrix A: " << endl;
    // print_arr(A, rows_A, cols_A);
    // cout << "Matrix B: " << endl;
    // print_arr(B, rows_B, cols_B);
    cout << "Result: " << endl;
    print_arr(C, rows_A, cols_B);
    cout << fixed << "Time: " << setprecision(12) << duration.count() * 1e-9 << " seconds."<< endl; // fixed - вывод без сокращения до 1e-...; setprecision(12) - вывод 12 знаков после запятой

    free_arrs(A, B, C, rows_A, rows_B);

    return 0;
}