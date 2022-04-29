/**
 * @file lib.h
 * @brief Файл з описом функцій, що
 * 1. void read_from_file - зчитує з файлу input.txt вхідну інформацію про
 * працівників і передає її програмі.
 * 2. void write_to_file - передає файлу output.txt інформацію про кількість і
 * характеристику робітників і виводить у термінал.
 * 3. void does_not_have_insuranse - аналізує масив структур і видає на екран
 * кількість працівників компанії Google без страхування.
 * 4. int comparing_seniority - допоміжна функція для функції qsort.
 *
 * @author Diakova A.
 * @date 25-apr-2022
 * @version 1.0
 */

#ifndef LAB14_LIB_H
#define LAB14_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct contact_details {
    char *first_name;
    char *last_name;
    char *email;
};

struct worker {
  int experience;
  bool have_insurance;
  char *company;
  struct contact_details details;
  char *characteristics;
} w;

void read_from_file(FILE *file, struct worker *array, int amount_of_workers);
void write_to_file(FILE *file, struct worker *array, int amount_of_workers);
void does_not_have_insurance(struct worker *array, int amount_of_workers);
int compare_seniority(const void *a, const void *b);

#endif