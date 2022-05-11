#include "../src/lib.h"
#include <check.h>
#include <malloc.h>

START_TEST(test_diagonal)
{
   int **data_arrr = (int** )malloc(3 * sizeof(int *));
   for( int i = 0; i < 3; i++) {  
     *(data_arrr + i) = (int*)malloc(3 * sizeof(int));
   }
   int *data_line_arr = (int* )malloc(3 * sizeof(int));

   

    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      *(*(data_arrr + i) + j) = i + j;
    }
  }

    int expected_value[] = {0, 2, 4};

    diagonal(data_line_arr, data_arrr, 3);
    
    for(int i = 0; i < 3; i++) 
    {    
        ck_assert_int_eq(expected_value[i], data_line_arr[i]);
    }
    free(data_arrr);
    free(data_line_arr);
}
END_TEST

int main(void) {
  Suite *s = suite_create("Programing");
  TCase *tc_core = tcase_create("lab10");
  tcase_add_test(tc_core, test_diagonal);
  suite_add_tcase(s, tc_core);
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? 0 : 1;
}