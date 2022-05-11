#include "/home/turtlee_/programming-Diakova/lab12/src/lib.h"
#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

START_TEST(test_searching)
{

  char *data_input_text = (char*)malloc(5 * sizeof(char));

  FILE *test_file = fopen("/home/turtlee_/programming-Diakova/lab12/assets/input.txt", "r");

  fscanf(test_file, "%s", data_input_text);

  char *expected_value = (char*)malloc(1 * sizeof(char));

  char *result_data_searching = (char* )malloc(1 * sizeof(char));

  *(expected_value + 0) = '8';

  numbers_searching(data_input_text, result_data_searching);

  printf("%s", result_data_searching);

  ck_assert_str_eq(expected_value, result_data_searching);

}
END_TEST

int main(void) {

  Suite *s = suite_create("Programing");
  TCase *tc_core = tcase_create("lab12");
  tcase_add_test(tc_core, test_searching);
  suite_add_tcase(s, tc_core);
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? 0 : 1;

}