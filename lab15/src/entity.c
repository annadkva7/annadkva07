#include "entity.h"
#include "list.h"

void does_not_have_insurance(struct worker *array, int amount_of_workers) {
  int temp = 0;
  printf("\n\nUninsured Google workers: \n");
  for ( int i = 0; i < amount_of_workers; i++) {
      if ( (array + i)->have_insurance == false) {
          temp = strcmp((array + i)->company, "Google");
          if( temp == 0) {
          printf("%s %s", (array + i)->details.first_name, (array + i)->details.last_name);
          printf("; ");
          }
      }    
  }
}

int compare_seniority(const void *a, const void *b) {
  int argument_1 = *(const int*)a;
  int argument_2 = *(const int*)b;

  return (argument_1 > argument_2) - (argument_1 < argument_2);
}
