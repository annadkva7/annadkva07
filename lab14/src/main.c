#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct worker {
    char *have_insurance; 
    char *company;
    int *experience;
    struct contact_details {
        char *first_name;
        char *last_name;
        char *email;
    } c_d;
    char *characteristics;
} w;

void read_from_file(FILE *file, int n, struct worker array) {
    int buffer = 512;
    file = fopen("/home/turtlee_/programming-Diakova/lab14/assets/input.txt", "r");
    for( int i = 0; i < buffer; i++) {
        w.have_insurance = getc(file);
        fscanf(file, "%s", w.company);
        fscanf(file, "%d", w.experience);
        fscanf(file, "%s", w.c_d.first_name);
        fscanf(file, "%s", w.c_d.last_name);
        fscanf(file, "%s", w.c_d.email);
        fscanf(file, "%s", w.characteristics);
        }
    }

 void print_on_screen(void) {
    printf("\n%s\n%s\n%d\n%s %s\n%s\n%s", w.have_insurance, w.company, w.experience, w.c_d.first_name, w.c_d.last_name, w.c_d.email, w.characteristics);
}

int main(void) {

    FILE *input_file;
    int buffer = 32;
    int amount_of_workers = 0;
    printf("Please, input the amount of workers for processing: ");
    scanf("%d", &amount_of_workers);

    w.company = (char*)malloc(buffer * sizeof(char));
    w.have_insurance = (char*)malloc(buffer * sizeof(char));
    w.c_d.first_name = (char*)malloc(buffer * sizeof(char));
    w.c_d.last_name = (char*)malloc(buffer * sizeof(char));
    w.c_d.email = (char*)malloc(buffer * sizeof(char));
    w.characteristics = (char*)malloc(buffer * sizeof(char));

    struct worker *array = (struct worker*)malloc(amount_of_workers * sizeof(struct worker));

    for( int i = 0; i < amount_of_workers; i++) {
        read_from_file(input_file, i, *(array + i));
    }

    for( int i = 0; i < amount_of_workers; i++) {
        print_on_screen();
    }

    /* for( int i = 0; i < amount_of_workers; i++) {
        print_on_screen();
    } */

   
    /* printf("\n%s", w.company);
    printf("\n%d", w.experience);
    printf("\n%s", w.c_d.first_name);
    printf(" %s", w.c_d.last_name);
    printf("\n%s", w.c_d.email);
    printf("\n%s", w.characteristics); */


}