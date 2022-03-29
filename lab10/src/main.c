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
 * @brief Файл з демонстрацією роботи функцій filling, diagonal, bubble;
 *
 * @author Diakova A.
 * @date 30-mar-2022
 * @version 1.0
 */
 
 #include "lib.h"

int main() {
  int N = 0;
    int **array = (int** )malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++) {
    array[i] = (int*)malloc(N * sizeof(int));
  }
    filling(array, N);
    for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d", array[i][j]);
      printf(" ");
    }
  }
   printf("\n");
  

  int *line_array = (int *)malloc(N * sizeof(int *));
  diagonal(line_array, array, N);
  for (int i = 0; i < N; i++) {
    printf("%d", line_array[i]);
    printf(" ");
  }
  bubble(line_array, N);
  for (int i = 0; i < N; i++) {
    printf("%d", line_array[i]);
  }

    return 0;
}