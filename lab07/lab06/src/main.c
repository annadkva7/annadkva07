int get_words_amount(char line[], int size);

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
