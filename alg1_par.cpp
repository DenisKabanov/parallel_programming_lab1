#include "utils.h"

int thread_count;
int rows_A, cols_A, rows_B, cols_B;
int** A;
int** B;
int** C;

void* Routine(void* rank);

int main(int argc, char* argv[]) {
    if (argc < 4) // проверка наличия аргументов (сама программа + файл1 + файл2 + число потоков)
        throw runtime_error("The program must have arguments!");

    A = read_file(argv[1], rows_A, cols_A);
    B = read_file(argv[2], rows_B, cols_B);
    C = new int*[rows_A];
    for (int i = 0; i < rows_A; ++i) {
        C[i] = new int[cols_B];
        for(int j = 0; j < cols_B; ++j)
            C[i][j] = 0;
    }

    thread_count = strtol(argv[3], NULL, 10);

    pthread_t *thread_handles = new pthread_t[thread_count];

    auto start = high_resolution_clock::now();

    for(long thread = 0; thread < thread_count; ++thread)
        pthread_create(&thread_handles[thread], NULL, Routine, (void*) thread);

    for(long thread = 0; thread < thread_count; ++thread)
        pthread_join(thread_handles[thread], NULL);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Alg 1: row by column multiplication with parallel execution" << endl;
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

void* Routine(void* rank) // исполняемая на потоках функция
{
    long my_rank = (long) rank;
    //=========================================================
    int rows_per_thread = ceil((double)rows_A / thread_count); // число строк/число потоков = число строк на один поток (округление в большую сторону, так как при случае с тремя строками и двумя потоками - последняя строка не будет обработана из-за rows_per_thread=3/2=1)
    int my_first_row = my_rank * rows_per_thread;
    int my_last_row = min<int>((my_rank + 1) * rows_per_thread, rows_A); // min - чтобы поток не вышел за края массива (по строкам)
    //-------faster realization but not so compatible----------
    // int rows_per_thread = rows_A / thread_count;
    // int my_first_row = my_rank * rows_per_thread;
    // int my_last_row = (my_rank + 1) * rows_per_thread; // min - чтобы поток не вышел за края массива (по строкам)
    //=========================================================

    for(int i = my_first_row; i < my_last_row; ++i) {// проходим по соответствующим потоку строчкам массива
        for(int j = 0; j < cols_B; ++j){ //сколько будет столбцов (умножение матрицы размера aXb на bXd приведёт к матрице размера aXd ==> число столбцов, как у матрицы, на которую умножаем)
            for(int k = 0; k < cols_A; ++k){ //проходим по всей соответствующей строке i в A (столбцу j в B). Идём по числу столбцов в A = числу строк в B (так как строка умножается на столбец, следовательно делаем сложений = длина строки раз (то же самое, что и число столбцов A или число строк B))
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return NULL;

}
