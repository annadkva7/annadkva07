/**
 * @file lib.c
 * @brief Файл з реалізацією функцій, що
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

#include "lib.h"

void read_from_file(FILE *file, struct worker *array, int amount_of_workers) {
    for (int i = 0; i < amount_of_workers; i++) {
      fscanf(file, "%d", &((array + i)->experience));

      fscanf(file, "%d", &((array + i)->have_insurance));

      fscanf(file, "%s", (array + i)->company);
      fscanf(file, "%s", (array + i)->details.first_name);
      fscanf(file, "%s", (array + i)->details.last_name);
      fscanf(file, "%s", (array + i)->details.email);
      fscanf(file, "%s", (array + i)->characteristics);
    }
}

void write_to_file(FILE *file, struct worker *array, int amount_of_workers) {
    fprintf(file, "Received information about employees: \n");
    for (int i = 0; i < amount_of_workers; i++) {
      fprintf(file, "\nHave insurance: %d\nExperience: %d\nCompany: %s\nWorker name: %s %s\nEmail: %s\nCharacteristics: %s\n",(array + i)->have_insurance, (array + i)->experience,(array + i)->company, (array + i)->details.first_name,(array + i)->details.last_name, (array + i)->details.email, (array + i)->characteristics);
      printf("\nHave insurance: %d\nExperience: %d\nCompany: %s\nWorker name: %s %s\nEmail: %s\nCharacteristics: %s\n", (array + i)->have_insurance,(array + i)->experience, (array + i)->company,(array + i)->details.first_name, (array + i)->details.last_name,(array + i)->details.email, (array + i)->characteristics);
    }
    printf("\n");
}

void does_not_have_insurance(struct worker *array, int amount_of_workers) {
  int temp = 0;
  printf("\n\nUninsured Google workers: \n");
  for ( int i = 0; i < amount_of_workers; i++) {
      if ( (array + i)->have_insurance == false) {
          temp = strcmp((array + i)->company, "Google");
          if( temp == 0) {
          printf("%s %s", (array + i)->details.first_name, (array + i)->details.last_name);
          printf("; ");
          }
      }    
  }
}

int compare_seniority(const void *a, const void *b) {
  int argument_1 = *(const int*)a;
  int argument_2 = *(const int*)b;

  return (argument_1 > argument_2) - (argument_1 < argument_2);
}