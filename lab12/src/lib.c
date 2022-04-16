/**
 * @file lib.c
 * @brief Файл з реалізацією функції, що знаходить усі числа в заданому тексті.
 *
 * @author Diakova A.
 * @date 17-apr-2022
 * @version 1.0
 */
 
#include "lib.h"

void numbers_searching(char *text, int SIZE) { 
    
    int *temp = (int*)malloc(SIZE * sizeof(int));
    
    for ( int i = 0; i < SIZE; i++ ) {

    int number = 0;
        if ( *(text + i) >= '0' && *(text + i) <= '9' ) {
            number = 10*number - ( *(text + i) - '0' );   
        }
        else {
            number = 0;
        }
    *(temp + i) = number;
        
    }
    
    printf("Input all numbers in this text:\n");

    for ( int i = 0; i < SIZE; i++) {
        switch (*(temp + i)) {
            case 0: {
            break;
            }
            default: {
                printf("%d", *(temp + i));
            }
        }
    }

    printf("\n");
    free(temp);

    }