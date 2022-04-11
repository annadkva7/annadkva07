#include "lib.h"

int sum(int **first_array, int **second_array, int **result_array, int N) {

printf("The result of sum is:");
for( int i = 0; i < N; i++ ) {
    for(int j = 0; j < N; j++) {
        *(*(result_array + i) + j) = *(*(first_array + i) + j) + *(*(second_array + i) + j);
    }
    printf("\n");
}
for (int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
    printf("%4d", *(*(result_array + i) + j));
    }
    printf("\n");

} 

return **result_array;
}