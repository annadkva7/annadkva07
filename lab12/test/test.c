#include "../src/lib.h"
#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

START_TEST(test_searching)
{

   char *data_text = (char* )malloc(128 * sizeof(char));
   data_text = "552Lalalala 7 kkkkkkkkkkkkkk<<<<< ,,,,,,,, 333/// 9";
   int SIZE = strlen(data_text);

   int expected_value[8] = {-5, -5, -2, -7, -3, -3, -3, -9};

   numbers_searching(data_text, SIZE);

   int result_data_searching[8];
    
    for(int i = 0; i < 8; i++)
    {
        ck_assert_int_eq(expected_value[i], result_data_searching[i]);
    }

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