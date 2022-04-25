/**
 * @mainpage
 * # Загальне завдання
 * Вивести структуру файлів та каталогів, як це робить утиліта Linux tree. Виклик функції system заборонено.
 *
 * @author Diakova A.
 * @date 19-apr-2022
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи функцій read_from_file, write_to_file;
 *
 * @author Diakova A.
 * @date 19-apr-2022
 * @version 1.0
 */

#include "lib.h"

struct worker {
    int experience;
    char *have_insurance; 
    char *company;
    struct contact_details {
        char *first_name;
        char *last_name;
        char *email;
    } c_d;
    char *characteristics;
} w;

int main() {

    FILE *input_file = NULL;
    FILE *output_file = NULL;

    int buf_size = 128;
    char *string = (char *)malloc(buf_size * sizeof(char));

    read_from_file(input_file, string);

    DIR *dir;
    struct dirent *de = NULL;

    if((dir = opendir(string)) == NULL) {
        printf("Sorry, haven't permission.");
        return 0;
    }

    write_to_file(output_file, de, dir);

    free(string);

    return 0;
}


