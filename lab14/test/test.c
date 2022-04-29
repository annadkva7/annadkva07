#include "/home/turtlee_/programming-Diakova/lab14/src/lib.h"
#include <check.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

START_TEST(test_read_from_file)
{
  int test_amount = 1;
    FILE *test_file = fopen("/home/turtlee_/programming-Diakova/lab14/assets/input.txt", "r");
    struct worker *result_value = (struct worker*)malloc(test_amount * sizeof(struct worker));
    struct worker *expected_value = (struct worker*)malloc(test_amount * sizeof(struct worker));
    read_from_file(test_file, result_value, 1);
    for( int i = 0; i < test_amount; i++) {
    (result_value + i)->company = (char*)malloc(16 * sizeof(char));
    (result_value + i)->details.first_name = (char*)malloc(16 * sizeof(char));
    (result_value + i)->details.last_name = (char*)malloc(16 * sizeof(char));
    (result_value + i)->details.email = (char*)malloc(16 * sizeof(char));
    (result_value + i)->characteristics = (char*)malloc(16 * sizeof(char));
    }

    expected_value->experience = 10;

    ck_assert_int_eq(expected_value->experience, result_value->experience);

    free(result_value);
    free(expected_value);

    fclose(test_file);

}
END_TEST

START_TEST(test_write_to_file) {
  int test_amount = 1;
  FILE *test_file = fopen("/home/turtlee_/programming-Diakova/lab14/assets/input.txt", "r");
  FILE *test_file1 = fopen("/home/turtlee_/programming-Diakova/lab14/assets/test.txt", "w");
  struct worker *test_array = (struct worker*)malloc(test_amount * sizeof(struct worker));
  struct worker *expected_value = (struct worker*)malloc(test_amount * sizeof(struct worker));
  struct worker *result_value = (struct worker*)malloc(test_amount * sizeof(struct worker));
  for( int i = 0; i < test_amount; i++) {
    (result_value + i)->company = (char*)malloc(16 * sizeof(char));
    (result_value + i)->details.first_name = (char*)malloc(16 * sizeof(char));
    (result_value + i)->details.last_name = (char*)malloc(16 * sizeof(char));
    (result_value + i)->details.email = (char*)malloc(16 * sizeof(char));
    (result_value + i)->characteristics = (char*)malloc(16 * sizeof(char));
  }

  read_from_file(test_file, result_value, test_amount);

  write_to_file(test_file1, result_value, test_amount);

  FILE *test_file2 = fopen("/home/turtlee_/programming-Diakova/lab14/assets/test.txt", "r");

  read_from_file(test_file2, result_value, test_amount);

  expected_value->experience = 10;

  ck_assert_int_eq(expected_value->experience, result_value->experience);

  fclose(test_file2);
  fclose(test_file1);
  fclose(test_file);

  free(result_value);
  free(expected_value);


}
END_TEST

int main(void) {
  Suite *s = suite_create("Programing");
  TCase *tc_core = tcase_create("lab14");
  tcase_add_test(tc_core, test_read_from_file);
  tcase_add_test(tc_core, test_write_to_file);

  suite_add_tcase(s, tc_core);
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? 0 : 1;
}