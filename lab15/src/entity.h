/**
 * @file entity.h
 * @brief Файл з описом функцій, що
 * 1. void does_not_have_insurance - виводить на екран робітників, що не мають страхування і працюють у компанії Google.
 * 2. void add_worker - додає працівника до масиву структур.
 * 3. int compare_seniority - допоміжна функція для бібліотечної qsort.
 * @author Diakova A.
 * @date 03-may-2022
 * @version 1.0
 */
#ifndef LAB15_ENTITY_H
#define LAB15_ENTITY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

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
}w;

void does_not_have_insurance(struct worker *array, int amount_of_workers);
int compare_seniority(const void *a, const void *b);
void add_worker(struct worker *array, struct worker *new_array, int new_amount_of_workers);

#endif