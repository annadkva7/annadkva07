int main()
{
#define SIZE 100
	char words[SIZE] = "Xochu   pyaterku        po      programirovaniu  ";

	int words_counter = 0;

	short is_word = 0;
	for (int i = 0; i < SIZE; i++) {
		if ((words[i] == ' ' && words[i + 1] != ' ') || words[i] != ' ') {
			is_word = 1;
		}

		if (is_word == 1 && (words[i] != ' ' && words[i] != '\0') && (words[i + 1] == ' ' || words[i + 1] == '\0')) {
			words_counter++;
			is_word = 0;
		}
	}

	return 0;
}
