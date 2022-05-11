/**
 * @mainpage
 * # Загальне завдання
 * 1. Дано масив з N*N цілих чисел. Елементи головної діагоналі записати в одновимірний масив, отриманий масив упорядкувати за зростанням;
 * 2. Використовувати динамічне виділення пам'яті для масивів;
 *
 * @author Diakova A.
 * @date 30-mar-2022
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи функцій diagonal, bubble;
 *
 * @author Diakova A.
 * @date 30-mar-2022
 * @version 1.0
 */
 
 #include "lib.h"

int main() {
 int N = 3;
    int **array = (int** )malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++) {
    *(array + i) = (int*)malloc(N * sizeof(int));
  }
 
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      *(*(array + i) + j) = i + j;
    }
  }
 for( int i = 0; i < N; i++) {
   for( int j = 0; j < N; j++) {
     printf("%d ", *(*(array + i) + j));
   }
 }
  int *line_array = (int *)malloc(N * sizeof(int *));
  diagonal(line_array, array, N);
  bubble(line_array, N);

  free(array);
  free(line_array);
  

    return 0;
}