#ifndef LAB15_LIST_H
#define LAB15_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct contact_details {
    char *first_name;
    char *last_name;
    char *email;
};

struct worker {
  int experience;
  bool have_insurance;
  char *company;
  struct contact_details details;
  char *characteristics;
} w;

void print_on_screen(struct worker *array, int amount_of_workers);

#endif