#include "/home/turtlee_/programming-Diakova/lab15/src/list.h"
#include "/home/turtlee_/programming-Diakova/lab15/src/entity.h"
#include <check.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

START_TEST(test_free_struct)
{
  int test_amount_of_workers = 1;
  struct worker *test_worker = (struct worker*)malloc(test_amount_of_workers * sizeof(struct worker));

  
    test_worker->company = (char*)malloc(16 * sizeof(char));
    test_worker->details.first_name = (char*)malloc(16 * sizeof(char));
    test_worker->details.last_name = (char*)malloc(16 * sizeof(char));
    test_worker->details.email = (char*)malloc(16 * sizeof(char));
    test_worker->characteristics = (char*)malloc(16 * sizeof(char));

  test_worker->experience = 15;
  test_worker->have_insurance = 1;
  test_worker->company = "Google";
  test_worker->details.first_name = "Anna";
  test_worker->details.last_name = "Diakova";
  test_worker->details.email = "annadkva07@gmail.com";
  test_worker->characteristics = "cool";

  int index = 1;

  free_struct(test_worker, test_amount_of_workers, index - 1, 1);
  free_struct(test_worker, test_amount_of_workers, index - 1, 2);
  free_struct(test_worker, test_amount_of_workers, index - 1, 3);
  free_struct(test_worker, test_amount_of_workers, index - 1, 4);
  free_struct(test_worker, test_amount_of_workers, index - 1, 5);
  free_struct(test_worker, test_amount_of_workers, index - 1, 6);
  int expected_value = 0;
  int expected_value_1 = 0;
  char expected_value_2[] = " ";
  char expected_value_3[] = " ";
  char expected_value_4[] = " ";
  char expected_value_5[] = " ";
  char expected_value_6[] = " ";
  int result_value_1 = test_worker->have_insurance;
  int result_value = test_worker->experience;

  char *result_value_2 = (char*)malloc(1 * sizeof(char));
  char *result_value_3 = (char*)malloc(1 * sizeof(char));
  char *result_value_4 = (char*)malloc(1 * sizeof(char));
  char *result_value_5 = (char*)malloc(1 * sizeof(char));
  char *result_value_6 = (char*)malloc(1 * sizeof(char));
  result_value_2 = test_worker->company;
  result_value_3 = test_worker->details.first_name;
  result_value_4 = test_worker->details.last_name;
  result_value_5 = test_worker->details.email;
  result_value_6 = test_worker->characteristics;



  ck_assert_int_eq(expected_value, result_value);
  ck_assert_int_eq(expected_value_1, result_value_1);
  ck_assert_str_eq(expected_value_2, result_value_2);
  ck_assert_str_eq(expected_value_3, result_value_3);
  ck_assert_str_eq(expected_value_4, result_value_4);
  ck_assert_str_eq(expected_value_5, result_value_5);
  ck_assert_str_eq(expected_value_6, result_value_6);

  free(test_worker);

}
END_TEST

int main(void) {
  Suite *s = suite_create("Programing");
  TCase *tc_core = tcase_create("lab15");
  tcase_add_test(tc_core, test_free_struct);

  suite_add_tcase(s, tc_core);
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? 0 : 1;
}