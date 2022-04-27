/**
 * @file lib.h
 * @brief Файл з описом функцій, що
 * 1. void convertion_int - трансформує десятичне число типу int до його
 * бінарного подання.
 * 2. void convertion_char - трансформує символ типу char до його бінарного
 * подання.
 * 3. void read_from_file - зчитує з файлу input.txt вхідну інформацію про
 * працівників і передає її програмі.
 * 4. void write_to_file - передає файлу output.txt інформацію про кількість і
 * характеристику робітників.
 * 5. void does_not_have_insuranse - аналізує масив структур і видає на екран
 * кількість працівників компанії Google без страхування.
 * 6. void sorting_by_seniority - сортує масив структур за характерною ознакою -
 * стаж роботи.
 * 7. void print_on_screen - виводить на екран усю інформацію, отриману з
 * вхідного файлу.
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
void print_on_screen(struct worker *array, int amount_of_workers);
void does_not_have_insurance(struct worker *array, int amount_of_workers);
void sorting_by_seniority(struct worker *array, int amount_of_workers);
int intComparator ( const void * first, const void * second );

#endif