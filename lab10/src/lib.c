/**
 * @file lib.c
 * @brief Файл з реалізацією функцій, що
    1. Перетворює діагональ двувимірного масиву в одновимірний динамічний масив;
    3. Сортує одновимірний масив за зростанням за допомогою методу бульбашок;
 *
 * @author Diakova A.
 * @date 30-mar-2022
 * @version 1.0
 */
 
#include "lib.h"

void diagonal(int* line_arr, int** arr, int N) {

  for (int i = 0; i < N; i++) {
    *(line_arr + i) = *(*(arr + i) + i);
  }
}

void bubble(int* line_arr, int N) {
  int p = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {   // line_array[j] < line_array[j - 1] //
      if (*(line_arr + (j - 1)) > *(line_arr + j)) {
        p = *(line_arr + j);
        *(line_arr + j) = (*(line_arr + (j - 1)));
        *(line_arr + (j - 1)) = p;
      }
    
    }
  }
}