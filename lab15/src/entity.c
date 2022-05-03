/**
 * @file entity.c
 * @brief Файл з реалізацією функцій, що
 * 1. void does_not_have_insurance - виводить на екран робітників, що не мають страхування і працюють у компанії Google.
 * 2. void add_worker - додає працівника до масиву структур.
 * 3. int compare_seniority - допоміжна функція для бібліотечного qsort.
 * @author Diakova A.
 * @date 03-may-2022
 * @version 1.0
 */
#include "entity.h"
#include "list.h"

void does_not_have_insurance(struct worker *array, int amount_of_workers) {
  int temp = 0;
  printf("\n\nПрацівники компанії Google без страхування: \n");
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

void add_worker(struct worker *array, struct worker *new_array, int new_amount_of_workers) {

  for( int i = 0; i < new_amount_of_workers; i++) {
    (new_array + i)->company = (char*)malloc(16 * sizeof(char));
    (new_array + i)->details.first_name = (char*)malloc(16 * sizeof(char));
    (new_array + i)->details.last_name = (char*)malloc(16 * sizeof(char));
    (new_array + i)->details.email = (char*)malloc(16 * sizeof(char));
    (new_array + i)->characteristics = (char*)malloc(16 * sizeof(char));
  }
  
    for( int i = 0; i < new_amount_of_workers - 1; i++) {
      (new_array + i)->experience = (array + i)->experience;
      (new_array + i)->have_insurance = (array + i)->have_insurance;
      strcpy((new_array + i)->company, (array + i)->company);
      strcpy((new_array + i)->details.first_name, (array + i)->details.first_name);
      strcpy((new_array + i)->details.last_name, (array + i)->details.last_name);
      strcpy((new_array + i)->details.email, (array + i)->details.email);
      strcpy((new_array + i)->characteristics, (array + i)->characteristics);
    }
    printf("\nДосвід роботи робітника №%d: ", new_amount_of_workers);
    scanf("%d", &((new_array + (new_amount_of_workers - 1))->experience));
    printf("\nЧи має робітник №%d страхування: ", new_amount_of_workers);
    scanf("%d", &((new_array + (new_amount_of_workers - 1))->have_insurance));
    printf("\nКомпанія, у якій працює робітник №%d: ", new_amount_of_workers);
    scanf("%s", (new_array + (new_amount_of_workers - 1))->company);
    printf("\nІм'я робітника №%d: ", new_amount_of_workers);
    scanf("%s", (new_array + (new_amount_of_workers - 1))->details.first_name);
    printf("\nПрізвище робітника №%d: ", new_amount_of_workers);
    scanf("%s", (new_array + (new_amount_of_workers - 1))->details.last_name);
    printf("\nПошта робітника №%d для контакту: ", new_amount_of_workers);
    scanf("%s", (new_array + (new_amount_of_workers - 1))->details.email);
    printf("Характеристика робітника: ");
    scanf("%s", (new_array + (new_amount_of_workers - 1))->characteristics);
}

int compare_seniority(const void *a, const void *b) {
  int argument_1 = *(const int*)a;
  int argument_2 = *(const int*)b;

  return (argument_1 > argument_2) - (argument_1 < argument_2);
}
