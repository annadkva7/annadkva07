/**
 * @mainpage
 * # Загальне завдання
 * Знайти всі числа, які зустрічаються у тексті;
 *
 * @author Diakova A.
 * @date 17-apr-2022
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи функції numbers_searching;
 *
 * @author Diakova A.
 * @date 17-apr-2022
 * @version 1.0
 */
 
#include "lib.h"

int main() {

int MAX_LENGHT = 256;
    char *input_text = (char* )malloc(MAX_LENGHT * sizeof(char));
    FILE *ftpr;
    if ((ftpr = fopen("/home/turtlee_/programming-Diakova/lab12/assets/input.txt", "r")) == NULL) {
        printf("Error! Sorry, impossible open the file.");
        return 0;
    }
    fgets(input_text, MAX_LENGHT, ftpr);

    int SIZE = strlen(input_text);

    printf("The size is: ");
    printf("%d", SIZE);
    printf("\n");

    char *text = (char* )malloc(SIZE * sizeof(char));
    strcpy(text, input_text);
    free(input_text);

    printf("Entered text to work:\n");
    for (int i = 0; i < SIZE; i++) {
    printf("%c", *(text + i));
    }
    printf("\n");

    char *temp = (char*)malloc(SIZE * sizeof(char));
    char *result = (char*)malloc(SIZE * sizeof(char));
    numbers_searching(text, temp);

    printf("Print all found numbers: ");

    for( int i = 0; i < SIZE; i++ ) {
        printf("%c", *(temp + i));
    } 

    free(text);
    free(temp);

    return 0;

}



    
