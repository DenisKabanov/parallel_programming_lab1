#include "utils.h"

int thread_count;
int rows_A, cols_A, rows_B, cols_B, cols_per_block_A, rows_per_block_A, cols_per_block_B, rows_per_block_B;

int deg; // число потоков - это какая степень двойки
int blocks_on_one_row_A, blocks_on_one_col_A, blocks_on_one_row_B, blocks_on_one_col_B; // число блоков по горизонтали и вертикали
int** A;
int** B;
int** C;
pthread_mutex_t mutex;

void* Routine(void* rank);

// предположение 1: число потоков = степени двойки
// предположение 2: размерность пришедших матриц делится нацело на число используемых потоков, так для матрицы размера 64x64 возможное число потоков: 1, 2, 4, 8, 16, 32, 64 (но не 3, 5...)
int main(int argc, char* argv[]) {
    if (argc < 4) // проверка наличия аргументов (сама программа + файл1 + файл2 + число потоков)
        throw runtime_error("The program must have 3 arguments!");

    A = read_file(argv[1], rows_A, cols_A);
    B = read_file(argv[2], rows_B, cols_B);
    C = new int*[rows_A];
    for (int i = 0; i < rows_A; ++i) {
        C[i] = new int[cols_B];
        for(int j = 0; j < cols_B; ++j)
            C[i][j] = 0;
    }

    thread_count = strtol(argv[3], NULL, 10);

    degree(thread_count, deg);

    if (deg % 2 == 0){
        // cout << "even degree" << endl;
        rows_per_block_A = rows_A / sqrt(thread_count);
        cols_per_block_A = cols_A / sqrt(thread_count);
        rows_per_block_B = rows_B / sqrt(thread_count);
        cols_per_block_B = cols_B / sqrt(thread_count);
    } else { // разбиение в блоки-строки
        // cout << "odd degree" << endl;
        rows_per_block_A = rows_A / thread_count;
        cols_per_block_A = cols_A;
        rows_per_block_B = rows_B;
        cols_per_block_B = cols_B / thread_count;
    }

    blocks_on_one_row_A = cols_A / cols_per_block_A;
    blocks_on_one_col_A = rows_A / rows_per_block_A;
    blocks_on_one_row_B = cols_B / cols_per_block_B;
    blocks_on_one_col_B = rows_B / rows_per_block_B;

    pthread_t *thread_handles = new pthread_t[thread_count];

    pthread_mutex_init(&mutex, NULL);

    auto start = high_resolution_clock::now();

    for(long thread = 0; thread < thread_count; ++thread)
        pthread_create(&thread_handles[thread], NULL, Routine, (void*) thread);

    for(long thread = 0; thread < thread_count; ++thread)
        pthread_join(thread_handles[thread], NULL);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    // cout << "Alg 3: block by block multiplication with parallel execution" << endl;
    // cout << "Matrix A: " << endl;
    // print_arr(A, rows_A, cols_A);
    // cout << "Matrix B: " << endl;
    // print_arr(B, rows_B, cols_B);
    // cout << "Result: " << endl;
    // print_arr(C, rows_A, cols_B);
    // cout << fixed << "Time: " << setprecision(12) << duration.count() * 1e-9 << " seconds."<< endl; // fixed - вывод без сокращения до 1e-...; setprecision(12) - вывод 12 знаков после запятой
    cout << fixed << setprecision(12) << duration.count() * 1e-9 << endl;
    
    pthread_mutex_destroy(&mutex);
    free_arrs(A, B, C, rows_A, rows_B);

    return 0;
}

void* Routine(void* rank) {// исполняемая на потоках функция
    long my_rank = (long) rank;

    int rows_start_for_block_A = my_rank / blocks_on_one_row_A * rows_per_block_A;
    int rows_finish_for_block_A = rows_start_for_block_A + rows_per_block_A;
    int cols_start_for_block_A = my_rank % blocks_on_one_row_A * cols_per_block_A;
    int cols_finish_for_block_A = cols_start_for_block_A + cols_per_block_A;

    int rows_start_for_block_B = cols_start_for_block_A;
    int rows_finish_for_block_B = rows_start_for_block_B + rows_per_block_B;
    // int rows_start_for_block_B = my_rank / blocks_on_one_row_B * rows_per_block_B;
    // int rows_finish_for_block_B = rows_start_for_block_B + rows_per_block_B;
    // int cols_start_for_block_B = my_rank % blocks_on_one_row_B * cols_per_block_B;
    // int cols_finish_for_block_B = cols_start_for_block_B + cols_per_block_B;

    // cout << "Thread: " << my_rank << " Stats: A_rows from: " << rows_start_for_block_A << " to " << rows_finish_for_block_A << " A_cols from: " << cols_start_for_block_A << " to " << cols_finish_for_block_A << " B_rows from " << rows_start_for_block_B << " to " << rows_finish_for_block_B << endl;
    // cout << "Thread: " << my_rank << " Stats: A_rows from: " << rows_start_for_block_A << " to " << rows_finish_for_block_A << " A_cols from: " << cols_start_for_block_A << " to " << cols_finish_for_block_A << " B_rows from " << rows_start_for_block_B << " to " << rows_finish_for_block_B << " B_cols from: " << cols_start_for_block_B << " to " << cols_finish_for_block_B << endl;

    int** temp_arr = new int*[rows_per_block_A];
    for(int i = 0; i < rows_per_block_A; ++i) {
        // temp_arr[i] = new int[cols_per_block_B];
        // for(int j = 0; j < cols_per_block_B; ++j)
        temp_arr[i] = new int[cols_B];
        for(int j = 0; j < cols_B; ++j)
            temp_arr[i][j] = 0;
    }

    // for(int i = rows_start_for_block_A; i < rows_finish_for_block_A; ++i) {
    //     for(int j = cols_start_for_block_B; j < cols_finish_for_block_B; ++j){
    //         for(int k = 0; k < cols_per_block_A; ++k){ // |cols_finish_for_block_A - cols_start_for_block_A| == |rows_finish_for_block_B - rows_start_for_block_B|
    //             temp_arr[i - rows_start_for_block_A][j - cols_start_for_block_B] += A[i][k] * B[k][j];
    //         }
    //     }
    // }

    for(int i = 0; i < rows_per_block_A; ++i) {
        for(int j = 0; j < cols_B; ++j){
            for(int k = 0; k < cols_per_block_A; ++k){
                // cout << "Thread: " << my_rank << " i,j,k: " << i << j << k << " A=" << A[i + rows_start_for_block_A][k + cols_start_for_block_A] << endl;
                // cout << "Thread: " << my_rank << " i,j,k: " << i << j << k << " B=" << B[k + rows_start_for_block_B][j] <<endl;
                temp_arr[i][j] += A[i + rows_start_for_block_A][k + cols_start_for_block_A] * B[k + rows_start_for_block_B][j];
            }
        }
    }

    // pthread_mutex_lock(&mutex);
    for (int i = rows_start_for_block_A; i < rows_finish_for_block_A; ++i) {
        for(int j = 0; j < cols_B; ++j) {
            pthread_mutex_lock(&mutex);
            C[i][j] += temp_arr[i-rows_start_for_block_A][j];
            pthread_mutex_unlock(&mutex);
        }
    }
    // pthread_mutex_unlock(&mutex);
    free_arr(temp_arr, rows_per_block_A);


    return NULL;
}
