/**
 * @file lib.c
 * @brief Файл з реалізацією функції, що знаходить усі числа в заданому тексті.
 *
 * @author Diakova A.
 * @date 17-apr-2022
 * @version 1.0
 */
 
#include "lib.h"

void numbers_searching(char *text, int SIZE, char *temp) { 

        for( int i = 0; i < SIZE; i++ ) {
            if( (*(text + i) >= '0' && *(text + i) <= '9') ) {
              *(temp + i) = *(text + i);
            }

            else {

            }
      }
}