#include "lib.h"

int main() {

printf("Laboratory work 11 by theme\n");
printf("User interaction by input/output\n");
printf("by student KN-921g Diakova Anna.\n\n");

int N1; 
int N2;
int M1;
int M2;

scanf("%d", &N1); /* Размер первого массива */
printf("\n");

scanf("%d", &M1);
printf("\n");

scanf("%d", &N2); /* Размер второго массива */
printf("\n");

scanf("%d", &M2);
printf("\n");

if(-1000 <= N1 && N1 >= 1000 && -1000 <= N2 && N2 >= 1000 && -1000 <= M1 &&  M1>= 1000 && -1000 <= M2 && M2 >= 1000) {

if ( N1 != N2 && M1 != M2 ) {
 printf("Sorry, according to the rules of math, it's impossible.\n");
 printf("Try again!\n");
 return 0;
}

else {
int N;
int M;
N = N1;
M = M1 ;

int **first_array = (int** )malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++) {
    *(first_array + i) = (int*)malloc(M * sizeof(int));
  }

for (int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
    *(*(first_array + i) + j) = random() % 10;
    }
}

printf("First matrix is:\n");
for (int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
    printf("%4d", *(*(first_array + i) + j));
    }
    printf("\n");
}
printf("\n");


int **second_array = (int** )malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++) {
    *(second_array + i) = (int*)malloc(M * sizeof(int));
  }

for (int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
    *(*(second_array + i) + j) = random() % 10;
    }
}

printf("Second matrix is:\n");
for (int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
    printf("%4d", *(*(second_array + i) + j));
    }
    printf("\n");
}
printf("\n");

int **result_array = (int** )malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++) {
    *(result_array + i) = (int*)malloc(M * sizeof(int));
  }

sum(first_array, second_array, result_array, N, M);

return 0;
}

}
else {
  printf("Sorry, these number are very big!\n");
  printf("Operating range from -1000 to 1000.\n");
  printf("Try again!");
  return 0;
}

}