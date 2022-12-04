#include "utils.h"

int thread_count;
int rows_A, cols_A, rows_B, cols_B;
int** A;
int** B;
int** C;
pthread_mutex_t mutex;

void* Routine(void* rank);

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

    pthread_t *thread_handles = new pthread_t[thread_count];

    pthread_mutex_init(&mutex, NULL);

    auto start = high_resolution_clock::now();

    for(long thread = 0; thread < thread_count; ++thread)
        pthread_create(&thread_handles[thread], NULL, Routine, (void*) thread);

    for(long thread = 0; thread < thread_count; ++thread)
        pthread_join(thread_handles[thread], NULL);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Alg 2: column by row multiplication without parallel execution" << endl;
    // cout << "Matrix A: " << endl;
    // print_arr(A, rows_A, cols_A);
    // cout << "Matrix B: " << endl;
    // print_arr(B, rows_B, cols_B);
    cout << "Result: " << endl;
    print_arr(C, rows_A, cols_B);
    cout << fixed << "Time: " << setprecision(12) << duration.count() * 1e-9 << " seconds."<< endl; // fixed - вывод без сокращения до 1e-...; setprecision(12) - вывод 12 знаков после запятой

    pthread_mutex_destroy(&mutex);
    free_arrs(A, B, C, rows_A, rows_B);

    return 0;
}

void* Routine(void* rank) // исполняемая на потоках функция
{
    long my_rank = (long) rank;
    //=========================================================
    int cols_per_thread = ceil((double)cols_A / thread_count); // число строк/число потоков = число строк на один поток (округление в большую сторону, так как при случае с тремя строками и двумя потоками - последняя строка не будет обработана из-за rows_per_thread=3/2=1)
    int my_first_col = my_rank * cols_per_thread;
    int my_last_col = min<int>((my_rank + 1) * cols_per_thread, cols_A); // min - чтобы поток не вышел за края массива (по строкам)
    //-------faster realization but not so compatible----------
    // int cols_per_thread = cols_A / thread_count;
    // int my_first_col = my_rank * cols_per_thread;
    // int my_last_col = (my_rank + 1) * cols_per_thread; // min - чтобы поток не вышел за края массива (по строкам)
    //=========================================================

    int** temp_arr = new int*[rows_A];
    for (int i = 0; i < rows_A; ++i) {
        temp_arr[i] = new int[cols_B];
        for(int j = 0; j < cols_B; ++j)
            temp_arr[i][j] = 0;
    }

    for (int i = my_first_col; i < my_last_col; ++i) {
        for (int j = 0; j < cols_B; ++j) {
            for (int k = 0; k < rows_A; ++k) {
                temp_arr[k][j] += A[k][i] * B[i][j];
            }
        }
    }
    // Пример с двумя потоками, матрицы размера 3x4 и 4x2 ==> rows_A=3, cols_B=2, temp_arr размера 3x2: 
    //                      |  m  n  |
    // |  a  b  c  d  |     |  o  p  |      | am+bo+cq+ds  an+bp+cr+dt |
    // |  e  f  g  h  |  X  |  q  r  |  ==  | em+fo+gq+hs  en+fp+gr+ht |
    // |  i  j  k  l  |     |  s  t  |      | im+jo+kq+ls  in+jp+kr+lt |
    // 
    //             | 0 0 |
    // temp_arr =  | 0 0 |
    //             | 0 0 |
    // 
    // Первый поток берёт столбцы 0, 1 матрицы A
    // в коде выше i - столбцы, которые берёт поток из A и строки из B, j - столбцов в B (столбец записи в temp_arr), k - для прохода по выбранному столбцу в A, умножая его на соответствующее залоченное значение из B (строка записи в temp_arr)
    // столбец в A:0, B:0 (i=0,j=0,k от 0 до 3)
    //                      | {m} n  |
    // | {a} b  c  d  |     |  o  p  |   temp_arr  |  am  0  |
    // | {e} f  g  h  |  X  |  q  r  |     ==>     |  em  0  |
    // | {i} j  k  l  |     |  s  t  |   потока 0  |  im  0  |
    // столбец в A:0, B:1 (i=0,j=1,k от 0 до 3)
    //                      |  m {n} |
    // | {a} b  c  d  |     |  o  p  |   temp_arr  |  am  an  |
    // | {e} f  g  h  |  X  |  q  r  |     ==>     |  em  en  |
    // | {i} j  k  l  |     |  s  t  |   потока 0  |  im  in  |
    // столбец в A:1, B:0 (i=1,j=0,k от 0 до 3)
    //                       |  m  n  |
    // |  a {b}  c  d  |     | {o} p  |   temp_arr  |  am+bo  an  |
    // |  e {f}  g  h  |  X  |  q  r  |     ==>     |  em+fo  en  |
    // |  i {j}  k  l  |     |  s  t  |   потока 0  |  im+jo  in  |
    // столбец в A:1, B:1 (i=1,j=1,k от 0 до 3)
    //                       |  m  n  |
    // |  a {b}  c  d  |     |  o {p} |   temp_arr  |  am+bo  an+bp  |
    // |  e {f}  g  h  |  X  |  q  r  |     ==>     |  em+fo  en+fp  |
    // |  i {j}  k  l  |     |  s  t  |   потока 0  |  im+jo  in+jp  |
    // далее аналогично рассматривается второй поток, где получается другой temp_arr
    // после получения всех temp_arr от потоков, они добавляются в искомый массив C

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < rows_A; ++i) {
        for(int j = 0; j < cols_B; ++j) {
            // pthread_mutex_lock(&mutex);
            C[i][j] += temp_arr[i][j];
            // pthread_mutex_unlock(&mutex);
        }
    }
    pthread_mutex_unlock(&mutex);
    free_arr(temp_arr, rows_A);

    return NULL;
}
