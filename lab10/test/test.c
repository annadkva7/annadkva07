#include "../src/lib.h"
#include <check.h>
#define size 100

START_TEST(test_array) {
  int data_N = 3;

  int actual_value = bubble(line_array, data_N);
  int expected_value = test_array;

  ck_assert_int_eq(expected_value, actual_value);
}
END_TEST

int main(void) {
  Suite *s = suite_create("Programing");
  TCase *tc_core = tcase_create("lab10");
  tcase_add_test(tc_core, test_array);
  suite_add_tcase(s, tc_core);
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? 0 : 1;
}