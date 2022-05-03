#include "list.h"
#include "entity.h"

void print_on_screen(struct worker *array, int amount_of_workers) {
    printf(file, "Received information about employees: \n");
    for (int i = 0; i < amount_of_workers; i++) {
      printf("\nHave insurance: %d\nExperience: %d\nCompany: %s\nWorker name: %s %s\nEmail: %s\nCharacteristics: %s\n", (array + i)->have_insurance,(array + i)->experience, (array + i)->company,(array + i)->details.first_name, (array + i)->details.last_name,(array + i)->details.email, (array + i)->characteristics);
    }
    printf("\n");
}

