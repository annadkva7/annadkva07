/**
 * @mainpage
 * # Загальне завдання
 * Виконати одне завдання з пулу завдань на свій розсуд.
 * У заданому тексті знайти кількість слів за умови, що між словами може бути будь-яка кількість пропусків.
 * @author Diakova A.
 * @date 19-dec-2021
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Головний файл.
 *
 * @author Diakova A.
 * @date 19-dec-2021
 * @version 1.0
 */

/**
 * Знаходить кількість слів в рядку
 *
 * Функція проходиться по кожному символу у рядку та перевіряє: якщо поточний символ пустий та наступний не пустий, то в змінній відмічається що поточний символ є словом, далі якщо слово знайдено та наступний символ пустий, значить що це слово та воно заноситься в каунтер. А в кінці повертає кількіть слів.
 *
 */
int get_words_amount(char line[], int size);

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - визиваємо функцію get_words_amount
 * @return успішний код повернення з програми (0)
 */
int main()
{
#define SIZE 100
	char words[SIZE] = " lfffffff    Im  Aaboba     BOBBBAAAAAA        ";

	int words_in_array = get_words_amount(words, SIZE);

	return 0;
}

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
