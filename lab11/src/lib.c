#include "lib.h"

int sum(int **first_array, int **second_array, int **result_array, int N, int M) {

printf("The result of sum is:");
for( int i = 0; i < N; i++ ) {
    for(int j = 0; j < M; j++) {
        *(*(result_array + i) + j) = *(*(first_array + i) + j) + *(*(second_array + i) + j);
    }
    printf("\n");
}
for (int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
    printf("%4d", *(*(result_array + i) + j));
    }
    printf("\n");
} 

return **result_array;
}