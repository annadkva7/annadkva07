#include "../src/lib.h"
#include <check.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

/*void assert_worker(struct worker *expected_value, struct worker *result_value)
{ ck_assert_str_eq(expected_value->company, result_value->company);

} */

START_TEST(test_read_from_file) {
  int test_amount_of_workers = 1;
  FILE *test_input = NULL;

  struct worker *expected_value =
      (struct worker *)malloc(1 * sizeof(struct worker));
  expected_value->company = "Google";

  struct worker *result_value =
      (struct worker *)malloc(1 * sizeof(struct worker));

  read_from_file(test_input, result_value, test_amount_of_workers);

  ck_assert_str_eq(expected_value->company, result_value->company);
}
END_TEST

int main(void) {
  Suite *s = suite_create("Programing");
  TCase *tc_core = tcase_create("lab14");
  tcase_add_test(tc_core, test_read_from_file);
  suite_add_tcase(s, tc_core);
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? 0 : 1;
}
