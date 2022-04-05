/**
 * @file lib.c
 * @brief Файл з реалізацією функцій, що
    1. Перетворює діагональ двувимірного масиву в одновимірний динамічний масив;
    3. Сортує одновимірний масив за зростанням за допомогою методу бульбашок;
 *
 * @author Diakova A.
 * @date 22-feb-2022
 * @version 1.0
 */
 
#include "lib.h"

void diagonal(long int* line_arr, long int** arr, unsigned long int N) {

  for (unsigned long int i = 0; i < N; i++) {
    line_arr[i] = arr[i][i];
  }
}

void bubble(long int* line_arr, unsigned long int N) {
  long int p = 0;
  for (unsigned long int i = 0; i < N; i++) {
    for (unsigned long int j = 0; j < N; j++) {   // line_array[j] < line_array[j - 1] //
      if (line_arr[j - 1] > line_arr[j]) {
        p = line_arr[j];
        line_arr[j] = line_arr[j - 1];
        line_arr[j - 1] = p;
      }
    
    }
  }
}