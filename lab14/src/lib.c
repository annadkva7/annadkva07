/**
 * @file lib.c
 * @brief Файл з реалізацією функцій, що
 * 1. void convertion_int - трансформує десятичне число типу int до його бінарного подання.
 * 2. void convertion_char - трансформує символ типу char до його бінарного подання.
 * 3. void read_from_file - зчитує з файлу input.txt вхідну інформацію про працівників і передає її програмі.
 * 4. void write_to_file - передає файлу output.txt інформацію про кількість і характеристику робітників.
 * 5. void does_not_have_insuranse - аналізує масив структур і видає на екран кількість працівників компанії Google без страхування.
 * 6. void sorting_by_seniority - сортує масив структур за характерною ознакою - стаж роботи.
 * 7. void print_on_screen - виводить на екран усю інформацію, отриману з вхідного файлу.
 *
 * @author Diakova A.
 * @date 25-apr-2022
 * @version 1.0
 */
  
#include "lib.h"

void convertion_int(unsigned char letter) {
  for (int bit = 128; bit >= 1; bit >>= 1) {
    /* cout << ((letter & bit) ? '1' : '0'); */
    if(letter & bit) {
      printf("1");
    }
    else {
      printf("0");
    }
  }
  printf(" ");
}

void convertion_char(char symbol) {
    unsigned char mask = 128;
    for ( int i = 0; i < 8; ++i ) {
        printf( "%s", ((mask & symbol) ? "1" : "0"));
        mask >>= 1;
    }
    printf(" ");
}

void read_from_file(FILE *file, struct worker *array, int amount_of_workers) {
    
    file = fopen("/home/turtlee_/programming-Diakova/lab14/assets/input.txt", "r");
    if (file != NULL) {
        for( int i = 0; i < amount_of_workers; i++) {

            fscanf(file, "%d", &(array + i)->experience);

            fscanf(file, "%s", (array + i)->have_insurance);
            
            fscanf(file, "%s", (array + i)->company);  
            fscanf(file, "%s", (array + i)->c_d.first_name);
            fscanf(file, "%s", (array + i)->c_d.last_name);
            fscanf(file, "%s", (array + i)->c_d.email);
            fscanf(file, "%s", (array + i)->characteristics);
        }
    }
    else {
        printf("Sorry, open file error. Try again!");
        fclose(file);
    }
}

void write_to_file(FILE *file, struct worker *array, int amount_of_workers) {
    file = fopen("/home/turtlee_/programming-Diakova/lab14/assets/output.txt", "w");
    if (file != NULL) {
        fprintf(file, "Received information about employees: \n");
        for( int i = 0; i < amount_of_workers; i++) {
            fprintf(file, "\n%s\n%d\n%s\n%s %s\n%s\n%s\n", (array + i)->have_insurance, (array + i)->experience, (array + i)->company, (array + i)->c_d.first_name, (array + i)->c_d.last_name, (array + i)->c_d.email, (array + i)->characteristics);    
        }
    }
    else {
        printf("Sorry, open file error. Try again!");
        fclose(file);
    }
}

void print_on_screen(struct worker *array, int amount_of_workers) {
    printf("Received information about employees: \n");
        for( int i = 0; i < amount_of_workers; i++) {
            printf("\n%s\n%d\n%s\n%s %s\n%s\n%s\n", (array + i)->have_insurance, (array + i)->experience, (array + i)->company, (array + i)->c_d.first_name, (array + i)->c_d.last_name, (array + i)->c_d.email, (array + i)->characteristics);    
        }
}

void does_not_have_insurance(struct worker *array, int amount_of_workers) {
    int temp;
    printf("\n\nUninsured Google workers: \n");
    
    for( int i = 0; i < amount_of_workers; i++) {
        temp = strcmp((array + i)->have_insurance, "no");

        if ( temp == 0) {
            temp = strcmp((array + i)->company, "Google");
            if ( temp == 0) {
                printf("%s %s", (array + i)->c_d.first_name, (array + i)->c_d.last_name);
                printf("; ");
                
            }
        }
    }
    printf("\n\n");
}

void sorting_by_seniority(struct worker *array, int amount_of_workers) {

    printf("\nSorted workers by seniority: \n");

    struct worker temp;

    for (int i = 0; i < amount_of_workers - 1; ++i) {
        for(int j = 0; j < amount_of_workers - 1; ++j) {
            if ((array + (j - 1))->experience < (array + j)->experience) {
                temp = *(array + (j + 1));
                *(array + (j + 1)) = *(array + j);
                *(array + j) = temp;

            }
        }
    }

    for( int i = 0; i < amount_of_workers; ++i) {
        printf("%s %s: %d\n", (array + i)->c_d.first_name, (array + i)->c_d.last_name, (array + i)->experience);
    }

}