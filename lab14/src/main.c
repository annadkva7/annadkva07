#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void convertion_int(unsigned char letter) {
  for (int bit = 128; bit >= 1; bit >>= 1) {
    /* cout << ((letter & bit) ? '1' : '0'); */
    if(letter & bit) {
      printf("1");
    }
    else {
      printf("0");
    }
  }
  printf(" ");
}

void convertion_char(char symbol) {
    unsigned char mask = 128;
    for ( int i = 0; i < 8; ++i ) {
        printf( "%s", ((mask & symbol) ? "1" : "0"));
        mask >>= 1;
    }
    printf(" ");
}

void read_from_file(FILE *file, struct worker *array, int amount_of_workers) {
    
    file = fopen("/home/turtlee_/programming-Diakova/lab14/assets/input.txt", "r");
    if (file != NULL) {
        for( int i = 0; i < amount_of_workers; i++) {

            fscanf(file, "%d", &array[i].experience);

            fscanf(file, "%s", array[i].have_insurance);
            
            fscanf(file, "%s", array[i].company);  
            fscanf(file, "%s", array[i].c_d.first_name);
            fscanf(file, "%s", array[i].c_d.last_name);
            fscanf(file, "%s", array[i].c_d.email);
            fscanf(file, "%s", array[i].characteristics);
        }
    }
    else {
        printf("Sorry, open file error. Try again!");
        fclose(file);
    }
}

void print_on_screen(struct worker *array, int amount_of_workers) {
    printf("Received information about employees: \n");
    for( int i = 0; i < amount_of_workers; i++) {
        printf("\n%s\n%d\n%s\n%s %s\n%s\n%s\n", array[i].have_insurance, array[i].experience, array[i].company, array[i].c_d.first_name, array[i].c_d.last_name, array[i].c_d.email, array[i].characteristics);
    }
}

void does_not_have_insurance(struct worker *array, int amount_of_workers) {
    int temp;
    printf("\n\nUninsured Google workers: \n");
    
    for( int i = 0; i < amount_of_workers; i++) {
        temp = strcmp(array[i].have_insurance, "no");

        if ( temp == 0) {
            temp = strcmp(array[i].company, "Google");
            if ( temp == 0) {
                printf("%s %s", array[i].c_d.first_name, array[i].c_d.last_name);
                printf("; ");
                
            }
        }
    }
    printf("\n\n");
}

void sorting_by_seniority(struct worker *array, int amount_of_workers) {

    printf("\nSorted workers by seniority: \n");

    struct worker temp;

    for (int i = 0; i < amount_of_workers - 1; ++i) {
        for(int j = 0; j < amount_of_workers - 1; ++j) {
            if (array[j + 1].experience < array[j].experience) {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;

            }
        }
    }

    for( int i = 0; i < amount_of_workers; ++i) {
        printf("%s %s: %d\n", array[i].c_d.first_name, array[i].c_d.last_name, array[i].experience);
    }

}

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
        array[i].c_d.first_name = (char*)malloc(buffer * sizeof(char));
        array[i].c_d.last_name = (char*)malloc(buffer * sizeof(char));
        array[i].c_d.email = (char*)malloc(buffer * sizeof(char));
        array[i].characteristics = (char*)malloc(buffer * sizeof(char));
    }

    read_from_file(input_file, array, amount_of_workers);
    print_on_screen(array, amount_of_workers);
    
    sorting_by_seniority(array, amount_of_workers);

    does_not_have_insurance(array, amount_of_workers);
    int temp = 0;

    printf("Please, input the index of the structure for binary convertion: ");
    scanf("%d", &temp);
    if (temp >= amount_of_workers) {
        printf("Sorry, invalid value!\n");
    }
    else {
        printf("\nHave insurance:\n");
        for( int j = 0; j < buffer; j++) {
            convertion_char(array[temp].have_insurance[j]);
        }
        printf("\nExpierence:\n");
         unsigned char* M = (unsigned char*)&array[temp].experience;
        for (int byte = 0; byte < sizeof(int); byte++, M++) {
            convertion_int(*M);
        }
        printf("\nCompany:\n");
        for( int j = 0; j < buffer; j++) {
            convertion_char(array[temp].company[j]);
        }
        printf("\nFirst name:\n");
        for( int j = 0; j < buffer; j++) {
            convertion_char(array[temp].c_d.first_name[j]);
        }
        printf("\nLast name:\n");
        for( int j = 0; j < buffer; j++) {
            convertion_char(array[temp].c_d.last_name[j]);
        }
        printf("\nEmail:\n");
        for( int j = 0; j < buffer; j++) {
            convertion_char(array[temp].c_d.email[j]);
        }
        printf("\nCharacteristics:\n");
        for( int j = 0; j < buffer; j++) {
            convertion_char(array[temp].characteristics[j]);
        }
    }



    

    

    return 0;
}