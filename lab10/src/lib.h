/**
 * @file lib.h
 * @brief Файл з описом функцій, що
    1. Перетворює діагональ двувимірного масиву в одновимірний динамічний масив;
    3. Сортує одновимірний масив за зростанням за допомогою методу бульбашок;
 *
 * @author Diakova A.
 * @date 30-mar-2022
 * @version 1.0
 */
 
#ifndef LAB10_LIB_H
#define LAB10_LIB_H

#include <malloc.h>
#include <stdlib.h>

void diagonal(long int* line_arr, long int** arr, unsigned long int N);
void bubble(long int* line_arr, unsigned long int N);

#endif