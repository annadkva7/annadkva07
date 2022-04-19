/**
 * @file lib.h
 * @brief Файл з описом функцій, що зчитує та записує інформацію у файл.
 *
 * @author Diakova A.
 * @date 19-apr-2022
 * @version 1.0
 */
 
#ifndef LAB13_LIB_H
#define LAB13_LIB_H

#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

void read_from_file(FILE *file, char *string);
void write_to_file(FILE *file, struct dirent *de, DIR *dir);

#endif