/**
 * @file lib.c
 * @brief Файл з реалізацією функції рахування кількості слів у заданному тексті
 *
 * @author Diakova A.
 * @date 22-feb-2022
 * @version 1.0
 */
#include "lib.h"

int get_words_amount(char line[], int size)
{
	int words_counter = 0;

	short is_word = 0;
	for (int i = 0; i < size; i++) {
		if ((line[i] == ' ' && line[i + 1] != ' ') || line[i] != ' ') {
			is_word = 1;
		}

		if (is_word == 1 && (line[i] != ' ' && line[i] != '\0') && (line[i + 1] == ' ' || line[i + 1] == '\0')) {
			words_counter++;
			is_word = 0;
		}
	}

	return words_counter;
}