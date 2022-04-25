/**
 * @mainpage
 * # Загальне завдання
 * З розділу "Індивідуальні завдання комплексної роботи" взяти прикладну галузь номеру варіанту за попередньо-визначеною формулою.
 * Створити структуру, що відображає "базовий клас".
 *
 * Розробити функції, які 1) читають дані з файлу, 2) записують дані у файл, 3) виводить масив елементів на екран, 4) №1 з категорії "Методи для роботи з колекцією", 5) сортування масиву за
 * заданим критерієм.
 * # Додаткове завдання
 * Виконати запис та читання масиву структур у двох форматах: текстовому та бінарному.
 *
 * @author Diakova A.
 * @date 25-apr-2022
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи функцій read_from_file, write_to_file, convertion_int, convertion_char, print_on_screen, does_not_have_insurance, sorting_by_seniority;
 *
 * @author Diakova A.
 * @date 25-apr-2022
 * @version 1.0
 */
 
#include "lib.h"


int main(void) {

    FILE *input_file = NULL;
    FILE *output_file = NULL;
    int buffer = 32;
    int amount_of_workers = 0;
    printf("Please, input the amount of workers for processing: ");
    scanf("%d", &amount_of_workers);

    struct worker *array = (struct worker*)malloc(amount_of_workers * sizeof(struct worker));

    for( int i = 0; i < amount_of_workers; i++) {
        (array + i)->company = (char*)malloc(buffer * sizeof(char));
        (array + i)->have_insurance = (char*)malloc(buffer * sizeof(char));
        (array + i)->c_d.first_name = (char*)malloc(buffer * sizeof(char));
        (array + i)->c_d.last_name = (char*)malloc(buffer * sizeof(char));
        (array + i)->c_d.email = (char*)malloc(buffer * sizeof(char));
        (array + i)->characteristics = (char*)malloc(buffer * sizeof(char));
    }

    read_from_file(input_file, array, amount_of_workers);
    write_to_file(output_file, array, amount_of_workers);
    print_on_screen(array, amount_of_workers);
    
    sorting_by_seniority(array, amount_of_workers);

    does_not_have_insurance(array, amount_of_workers);
    int temp = 0;

    printf("Please, input the index of the structure for binary convertion: ");
    scanf("%d", &temp);

    if (temp >= amount_of_workers) {
        printf("Sorry, invalid value!\n");
    }

    else {
        printf("\nHave insurance:\n");
        for( int j = 0; j < buffer; j++) {
            convertion_char((array + temp)->have_insurance[j]);
        }
        printf("\nExpierence:\n");
         unsigned char* M = (unsigned char*)&(array + temp)->experience;
        for (int byte = 0; byte < sizeof(int); byte++, M++) {
            convertion_int(*M);
        }
        printf("\nCompany:\n");
        for( int j = 0; j < buffer; j++) {
            convertion_char((array + temp)->company[j]);
        }
        printf("\nFirst name:\n");
        for( int j = 0; j < buffer; j++) {
            convertion_char((array + temp)->c_d.first_name[j]);
        }
        printf("\nLast name:\n");
        for( int j = 0; j < buffer; j++) {
            convertion_char((array + temp)->c_d.last_name[j]);
        }
        printf("\nEmail:\n");
        for( int j = 0; j < buffer; j++) {
            convertion_char((array + temp)->c_d.email[j]);
        }
        printf("\nCharacteristics:\n");
        for( int j = 0; j < buffer; j++) {
            convertion_char((array + temp)->characteristics[j]);
        }
    }   

    return 0;
}