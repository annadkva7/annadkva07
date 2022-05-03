/**
 * @file list.h
 * @brief Файл з описом функцій, що
 * 1. void print_on_screen - виводить на екран масив структур.
 * 2. void free_struct - видаляє обраний елемент у обраній структурі.
 * @author Diakova A.
 * @date 03-may-2022
 * @version 1.0
 */
#ifndef LAB15_LIST_H
#define LAB15_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "entity.h"

void print_on_screen(struct worker *array, int amount_of_workers);
void free_struct(struct worker *array, int amount_of_workers, int index, int temp);

#endif