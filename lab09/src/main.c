/**
 * @mainpage
 * # Загальне завдання
 * 1. У заданому тексті знайти кількість слів за умови, що між словами може бути будь-яка кількість пропусків;
 *
 * 2. Сформувати функцію, яка буде знаходити кількість слів у заданому тексті
 *
 * @author Diakova A.
 * @date 22-feb-2022
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи функції get_words_amount
 *
 * @author Diakova A.
 * @date 22-feb-2022
 * @version 1.0
 */
int get_words_amount(char line[], int size);

int main()
{
#define SIZE 100
	char words[SIZE];

	int words_in_array = get_words_amount(words, SIZE);

	return 0;
}
