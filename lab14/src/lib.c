/**
 * @file lib.c
 * @brief Файл з реалізацією функцій, що
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

#include "lib.h"

void read_from_file(FILE *file, struct worker *array, int amount_of_workers) { /* исправно */
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

void write_to_file(FILE *file, struct worker *array, int amount_of_workers) { /* исправно */
    fprintf(file, "Received information about employees: \n");
    for (int i = 0; i < amount_of_workers; i++) {
      fprintf(file, "\nHave insurance: %d\nExperience: %d\nCompany: %s\nWorker name: %s %s\nEmail: %s\nCharacteristics: %s\n",(array + i)->have_insurance, (array + i)->experience,(array + i)->company, (array + i)->details.first_name,(array + i)->details.last_name, (array + i)->details.email, (array + i)->characteristics);
      printf("\nHave insurance: %d\nExperience: %d\nCompany: %s\nWorker name: %s %s\nEmail: %s\nCharacteristics: %s\n", (array + i)->have_insurance,(array + i)->experience, (array + i)->company,(array + i)->details.first_name, (array + i)->details.last_name,(array + i)->details.email, (array + i)->characteristics);
    }
    printf("\n");
}

void does_not_have_insurance(struct worker *array, int amount_of_workers) { /* исправно */
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

void write_to_bin(FILE *file, struct worker *array, int amount_of_workers) {
  for( int i = 0; i < amount_of_workers; i++) {
    fwrite((array + i), sizeof(struct worker), amount_of_workers, file);
  }
}
void read_from_bin(FILE *file, struct worker *for_reading) {
  int temp = 0;
  printf("Please, input the index for reading structure: ");
  scanf("%d", &temp);
  fseek(file, (temp *sizeof(struct worker)), SEEK_CUR);
  fread(&(for_reading->have_insurance), sizeof(int), 1, file);
  fread(&(for_reading->experience), sizeof(int), 1, file);
  fread(for_reading->company, 16, 1, file);
  fread(for_reading->details.last_name, 16, 1, file);
  fread(for_reading->details.first_name, 16, 1, file);
  fread(for_reading->details.email, 16, 1, file);
  fread(for_reading->characteristics, 16, 1, file);

  printf("\nHave insurance: %d\nExperience: %d\nCompany: %s\nWorker name: %s %s\nEmail: %s\nCharacteristics: %s\n", for_reading->have_insurance,for_reading->experience, for_reading->company,for_reading->details.first_name, for_reading->details.last_name,for_reading->details.email, for_reading->characteristics);

  
}