/**
 * @file lib.h
 * @brief Файл з описом функції, що визначає суму двох матриць.
 *
 * @author Diakova A.
 * @date 12-apr-2022
 * @version 1.0
 */
 
#ifndef LAB11_LIB_H
#define LAB11_LIB_H

#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

int sum(int **first_array, int **second_array, int **result_array, int N, int M);

#endif