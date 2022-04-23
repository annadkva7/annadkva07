#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct worker {
    char *have_insurance; 
    char *company;
    char *experience;
    struct contact_details {
        char *first_name;
        char *last_name;
        char *email;
    } c_d;
    char *characteristics;
} w;

void read_from_file(FILE *file, struct worker *array, int amount_of_workers) {
    
    file = fopen("/home/turtlee_/programming-Diakova/lab14/assets/input.txt", "r");
    if (file != NULL) {
        for( int i = 0; i < amount_of_workers; i++) {

            fscanf(file, "%s", array[i].have_insurance);
            fscanf(file, "%s", array[i].experience);
            fscanf(file, "%s", array[i].company);  
            fscanf(file, "%s", array[i].c_d.first_name);
            fscanf(file, "%s", array[i].c_d.last_name);
            fscanf(file, "%s", array[i].c_d.email);
            fscanf(file, "%s", array[i].characteristics);
        }
        fclose(file);
    }
    else {
        printf("Sorry, open file error. Try again!");
        fclose(file);
    }
}

/* void print_on_screen(struct worker *array, int amount_of_workers) {
    printf("Received information about employees: \n");
    for( int i = 0; i < amount_of_workers; i++) {
        printf("\n%s\n%s\n%s\n%s %s\n%s\n%s\n", array[i].have_insurance, array[i].experience, array[i].company, array[i].c_d.first_name, array[i].c_d.last_name, array[i].c_d.email, array[i].characteristics);
    }
} */

void does_not_have_insurance(FILE *file, struct worker *array, int amount_of_workers) {
    int temp;
    file = fopen("/home/turtlee_/programming-Diakova/lab14/assets/output.txt", "w");
    fprintf(file, "Uninsured Google workers: \n");
    
    for( int i = 0; i < amount_of_workers; i++) {
        temp = strcmp(array[i].have_insurance, "no");

        if ( temp == 0) {
            temp = strcmp(array[i].company, "Google");
            if ( temp == 0) {
                fprintf(file, "%s %s", array[i].c_d.first_name, array[i].c_d.last_name);
                fprintf(file, "; ");
                
            }
        }
    }
    fclose(file);
}

char compare(const void *x1, const void *x2) {
    return (*(char*)x1 - *(char*)x2);
}

/* void sorting_by_seniority(FILE *file, struct worker *array, int amount_of_workers) {
    file = fopen("/home/turtlee_/programming-Diakova/lab14/assets/output.txt", "w");
    fprintf(file, "\nSorted workers by seniority: \n");
    for( int i = 0; i < amount_of_workers; i++) {
    qsort(array[i].experience, amount_of_workers, sizeof(char), compare);
    }
    for( int i = 0; i < amount_of_workers; i++) {
        fprintf(file, "\n%s", array[i].experience);
    }
    fclose(file);

} */

int main(void) {

    FILE *input_file;
    int buffer = 32;
    int amount_of_workers = 0;
    printf("Please, input the amount of workers for processing: ");
    scanf("%d", &amount_of_workers);

    struct worker *array = (struct worker*)malloc(amount_of_workers * sizeof(struct worker));

    for( int i = 0; i < amount_of_workers; i++) {
        array[i].company = (char*)malloc(buffer * sizeof(char));
        array[i].have_insurance = (char*)malloc(buffer * sizeof(char));
        array[i].experience = (char*)malloc(buffer * sizeof(char));
        array[i].c_d.first_name = (char*)malloc(buffer * sizeof(char));
        array[i].c_d.last_name = (char*)malloc(buffer * sizeof(char));
        array[i].c_d.email = (char*)malloc(buffer * sizeof(char));
        array[i].characteristics = (char*)malloc(buffer * sizeof(char));
    }

    FILE *output_file;

    read_from_file(input_file, array, amount_of_workers);
    /* print_on_screen(array, amount_of_workers); */
    does_not_have_insurance(output_file, array, amount_of_workers);
    sorting_by_seniority(output_file, array, amount_of_workers);

    

    return 0;
}