#include "list.h"
#include "entity.h"

int main(void) {
  printf("Please, input the amount of workers for processing: ");
  scanf("%d", &amount_of_workers);

  struct worker *array = (struct worker *)malloc(amount_of_workers * sizeof(struct worker));
  for( int i = 0; i < amount_of_workers; i++) {
    (array + i)->company = (char*)malloc(16 * sizeof(char));
    (array + i)->details.first_name = (char*)malloc(16 * sizeof(char));
    (array + i)->details.last_name = (char*)malloc(16 * sizeof(char));
    (array + i)->details.email = (char*)malloc(16 * sizeof(char));
    (array + i)->characteristics = (char*)malloc(16 * sizeof(char));
  }

  printf("Please, fill the list: \n");
  int count = 1;
  for( int i = 0; i < amount_of_workers; i++) {
    printf("Input the experience of the %d worker: ", count);
    scanf("%d", &((array + i)->experience));
    printf("\nDoes the %d worker have insurance? ", count);
    scanf("%d", &((array + i)->have_insurance));
    printf("\nIn which company the %d employee works? ", count);
    scanf("%s", (array + i)->company);
    printf("\nThe first name of the %d worker: ", count);
    scanf("%s", (array + i)->details.first_name);
    printf("\nThe second name of the %d worker: ", count);
    scanf("%s", (array + i)->details.last_name);
    printf("\nmail to contact the %d employee: ", count);
    scanf("%s", (array + i)->details.email);
    printf("How would you characterize the first employee? ");
    scanf("%s", (array + i)->characteristics);
    count++;
  }
  

}