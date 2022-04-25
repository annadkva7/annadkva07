#include "../src/lib.h"
#include <check.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

START_TEST(test_convertion_int)
{
  int test_number = 12;
  FILE *test_file = fopen("/home/turtlee_/programming-Diakova/lab14/assets/test.txt", "w");
    
  unsigned char* M = (unsigned char*)&test_number;
    for (int byte = 0; byte < sizeof(int); byte++, M++) {
      fprintf(test_file, convertion_int(*M));
    }

  
  ck_assert_str_eq(expected_value.company, test_array->company[1]);
  

}
END_TEST

int main(void) {
  Suite *s = suite_create("Programing");
  TCase *tc_core = tcase_create("lab14");
  tcase_add_test(tc_core, test_convertion_int);
  suite_add_tcase(s, tc_core);
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? 0 : 1;
}