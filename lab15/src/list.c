/**
 * @file list.c
 * @brief Файл з реалізацією функцій, що
 * 1. void print_on_screen - виводить на екран масив структур.
 * 2. void free_struct - видаляє обраний елемент у обраній структурі.
 * @author Diakova A.
 * @date 03-may-2022
 * @version 1.0
 */
#include "list.h"
#include "entity.h"

void print_on_screen(struct worker *array, int amount_of_workers) {
    printf("Отримана інформація: \n");
    for (int i = 0; i < amount_of_workers; i++) {
      printf("\nСтрахування: %d\nДосвід: %d\nКомпанія: %s\nІм'я та прізвище: %s %s\nПошта: %s\nХарактеристика: %s\n", (array + i)->have_insurance,(array + i)->experience, (array + i)->company,(array + i)->details.first_name, (array + i)->details.last_name,(array + i)->details.email, (array + i)->characteristics);
    }
    printf("\n");
}

void free_struct(struct worker *array, int amount_of_workers, int index, int temp) {
    switch(temp) {
      case 1:
        (array + index)->experience = 0;
        break;
      case 2:
        (array + index)->have_insurance = 0;
        break;
      case 3:
        (array + index)->company = " ";
        break;
      case 4:
        (array + index)->details.first_name = " ";
        (array + index)->details.last_name = " ";
        break;
      case 5:
        (array + index)->details.email = " ";
        break;
      case 6:
        (array + index)->characteristics = " ";
        break;
      default: 
        printf("\nНекоректне найменування!");
        break;
    }
}

