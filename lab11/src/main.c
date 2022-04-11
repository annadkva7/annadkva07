#include "lib.h"

int main() {

int N1, N2;
printf("Please, input the first array size:\n");
scanf("%d", &N1);
printf("\n");
printf("Please, input the second array size:\n");
scanf("%d", &N2);
printf("\n");

if ( N1 != N2 ) {
 printf("Sorry, according to the rules of math, it's impossible.\n");
 printf("Try again!\n");
 return 0;
}

else {
int N;
N = N1;

int **first_array = (int** )malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++) {
    *(first_array + i) = (int*)malloc(N * sizeof(int));
  }

printf("Input the first matrix:\n");
for (int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
    scanf("%4d", (*(first_array + i) + j));
    }
}

printf("First matrix is:\n");
for (int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
    printf("%4d", *(*(first_array + i) + j));
    }
    printf("\n");
}
printf("\n");


int **second_array = (int** )malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++) {
    *(second_array + i) = (int*)malloc(N * sizeof(int));
  }

printf("Input the second matrix:\n");
for (int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
    scanf("%4d", (*(second_array + i) + j));
    }
}

printf("Second matrix is:\n");
for (int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
    printf("%4d", *(*(second_array + i) + j));
    }
    printf("\n");
}
printf("\n");

int **result_array = (int** )malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++) {
    *(result_array + i) = (int*)malloc(N * sizeof(int));
  }

sum(first_array, second_array, result_array, N);

return 0;
}

}