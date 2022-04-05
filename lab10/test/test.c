#include "../src/lib.h"
#include <check.h>
#include <malloc.h>

START_TEST(test_diagonal)
{
    long int **data_arrr = (long int** )malloc(3 * sizeof(long int *));
    long int **data_arr = (long int** )malloc(3 * sizeof(long int *));
    long int** data_arrr = { { 0, 0, 0}, 
                            {3, 6, 7},
                            {5, 3, 5 } };
    data_arr = data_arrr;
    long int data_line_arr[0];
    long int expected_value[] = {0, 6, 5};

    diagonal(data_line_arr, data_arr, 3);
    
    for(int i = 0; i < 3; i++) 
    {    
        ck_assert_int_eq(expected_value[i], data_line_arr[i]);
    }
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