/**
 * @file lib.c
 * @brief Файл з реалізацією функцій, що зчитує та записує інформацію у файл.
 *
 * @author Diakova A.
 * @date 19-apr-2022
 * @version 1.0
 */
  
#include "lib.h"

void read_from_file(FILE *file, char *string) {
    file = fopen("/home/turtlee_/programming-Diakova/lab13/assets/input.txt", "r");
    fscanf(file, "%s", string);
}

void write_to_file(FILE *file, struct dirent *de, DIR *dir) {
    file = fopen("/home/turtlee_/programming-Diakova/lab13/assets/output.txt", "w");

    while (de = readdir(dir)) {
        printf("%s\n├─ ", de -> d_name);
        fprintf(file, "%s\n├─ ", de -> d_name);
    }
    closedir(dir);
 
}
