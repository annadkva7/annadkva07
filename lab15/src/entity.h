#ifndef LAB15_ENTITY_H
#define LAB15_ENTITY_H

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

void does_not_have_insurance(struct worker *array, int amount_of_workers);
int compare_seniority(const void *a, const void *b);

#endif