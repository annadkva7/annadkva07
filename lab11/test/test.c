#include "../src/lib.h"
#include <check.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

START_TEST(test_sum)
{
  int N = 2;
  int M = 3;

   int **first_data_arr = (int** )malloc(N * sizeof(int *));
   for( int i = 0; i < N; i++) {  
     *(first_data_arr + i) = (int*)malloc(M * sizeof(int));
   }
   
   int **second_data_arr = (int** )malloc(N * sizeof(int *));
   for( int i = 0; i < N; i++) {  
     *(second_data_arr + i) = (int*)malloc(M * sizeof(int));
   }

   int **result_data_arr = (int** )malloc(N * sizeof(int *));
   for( int i = 0; i < N; i++) {  
     *(result_data_arr + i) = (int*)malloc(M * sizeof(int));
   }

    for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      *(*(first_data_arr + i) + j) = i + j;
    }
  }
    for (int i = 0; i < N; i++) {
      for ( int j = 0; j < M; j++) {
        *(*(second_data_arr + i) + j) = i + j;
      }
    }

    int expected_value[2][3] = {{0, 2, 4},{2, 4, 6}};

    sum(first_data_arr, second_data_arr, result_data_arr, N, M);
    
    for(int i = 0; i < N; i++) 
    {    
      for( int j = 0; j < M; j++) {
        ck_assert_int_eq(expected_value[i][j], result_data_arr[i][j]);
      }
    }
}
END_TEST

int main(void) {
  Suite *s = suite_create("Programing");
  TCase *tc_core = tcase_create("lab11");
  tcase_add_test(tc_core, test_sum);
  suite_add_tcase(s, tc_core);
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? 0 : 1;
}