#include "../src/lib.h"
#include <check.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

START_TEST(test_sum)
{
  int N1 = 3;
  int N2 = 3;
  int N = 3;

   int **first_data_arr = (int** )malloc(N * sizeof(int *));
   for( int i = 0; i < N; i++) {  
     *(first_data_arr + i) = (int*)malloc(N * sizeof(int));
   }
   
   int **second_data_arr = (int** )malloc(N * sizeof(int *));
   for( int i = 0; i < N; i++) {  
     *(second_data_arr + i) = (int*)malloc(N * sizeof(int));
   }

   int **result_data_arr = (int** )malloc(N * sizeof(int *));
   for( int i = 0; i < N; i++) {  
     *(result_data_arr + i) = (int*)malloc(N * sizeof(int));
   }

    for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      *(*(first_data_arr + i) + j) = i + j;
    }
  }
    for (int i = 0; i < N; i++) {
      for ( int j = 0; j < N; j++) {
        *(*(second_data_arr + i) + j) = i + j;
      }
    }

    int expected_value[3][3] = {{0, 2, 4},{2, 4, 6},{4, 6, 8}};

    sum(first_data_arr, second_data_arr, result_data_arr, N);
    
    for(int i = 0; i < N; i++) 
    {    
      for( int j = 0; j < N; j++) {
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