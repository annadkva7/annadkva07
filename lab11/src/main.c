#include <malloc.h>


int multiply(int** first_array, int** second_array, int** result, int M1, int N2, int N) {
    printf("The result of multyplying two matrices:\n");
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        *(*(result + i) + j) = 0;
        for (int k = 0; k < N2; k++) {
            *(*(result + i) + j) += *(*(first_array + i) + k) * *(*(second_array + k) + j);
        }
    }
}
return **result;
}



int main() {

int N1 = 0;
int M1 = 0;
printf("Please, input the first column:\n");
scanf("%d", &N1);
printf("\n");

printf("Please, input the first line:\n");
scanf("%d", &M1);
printf("\n");

int **first_array = (int** )malloc(N1 * sizeof(int *));
  for (int i = 0; i < M1; i++) {
    *(first_array + i) = (int*)malloc(M1 * sizeof(int));
  }

printf("Please, input the first matrix:\n");
for (int i = 0; i < N1; i++) {
    for(int j = 0; j < M1; j++) {
    scanf("%4d", (*(first_array + i) + j));
    }
}

printf("Your first matrix is:\n");
for (int i = 0; i < N1; i++) {
    for(int j = 0; j < M1; j++) {
    printf("%4d", *(*(first_array + i) + j));
    }
    printf("\n");
}
printf("\n");


int N2 = 0;
int M2 = 0;
printf("Please, input the second column:\n");
scanf("%d", &N2);
printf("\n");

printf("Please, input the second line:\n");
scanf("%d", &M2);
printf("\n");

int **second_array = (int** )malloc(N2 * sizeof(int *));
  for (int i = 0; i < N2; i++) {
    *(second_array + i) = (int*)malloc(M2 * sizeof(int));
  }

printf("Please, input the second matrix:\n");
for (int i = 0; i < N2; i++) {
    for(int j = 0; j < M2; j++) {
    scanf("%4d", (*(second_array + i) + j));
    }
}

printf("Your second matrix is:\n");
for (int i = 0; i < N2; i++) {
    for(int j = 0; j < M2; j++) {
    printf("%4d", *(*(second_array + i) + j));
    }
    printf("\n");
}
printf("\n");

int **result_array = (int** )malloc(N1 * sizeof(int *));
  for (int i = 0; i < N2; i++) {
    *(result_array + i) = (int*)malloc(M2 * sizeof(int));
  }

if (N1 == M2) {
    int N = N1;
multiply(first_array, second_array, result_array, M1, N2, N);
for (int i = 0; i < N2; i++) {
    for(int j = 0; j < M2; j++) {
    printf("%4d", *(*(result_array + i) + j));
    }
    printf("\n");

} 
}
else {
    printf("Sorry, this matrices cannot be multiplied. Set another dimension.");
    return 0;
}
free(first_array);
free(second_array);
free(result_array);

return 0;
}



