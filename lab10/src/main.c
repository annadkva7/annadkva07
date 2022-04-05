/**
 * @mainpage
 * # Загальне завдання
 * 1. Дано масив з N*N цілих чисел. Елементи головної діагоналі записати в одновимірний масив, отриманий масив упорядкувати за зростанням;
 *
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
  unsigned long int N = 3;
    long int **array = (long int** )malloc(N * sizeof(long int *));
  for (unsigned long int i = 0; i < N; i++) {
    array[i] = (long int*)malloc(N * sizeof(long int));
  }
 
  for (unsigned long int i = 1; i < N; i++) {
    for (unsigned long int j = 0; j < N; j++) {
      array[i][j] = random() % 10;
    }
  }

  long int *line_array = (long int *)malloc(N * sizeof(long int *));
  diagonal(line_array, array, N);
  
  bubble(line_array, N);

  free(array);
  free(line_array);
  

    return 0;
}