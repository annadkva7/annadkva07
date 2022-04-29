#include "../src/lib.h"
#include <check.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

START_TEST(test_read_from_file)
{
    int buf_size = 128;

    FILE *file = fopen("/home/turtlee_/programming-Diakova/lab13/assets/input.txt", "r");
    char *string = (char*)malloc(buf_size * sizeof(char));
    fgets(string, buf_size, file);
    
    struct dirent *de;
    DIR *dir = opendir(string);

    char *expected_value = (char *)malloc(buf_size * sizeof(char));
    fgets(expected_value, buf_size, file);

    char *result_data_input = (char *)malloc(buf_size * sizeof(char));

    write_to_file(file, de, dir);
    ck_assert_str_eq(expected_value, result_data_input);
  
}
END_TEST

int main(void) {
  Suite *s = suite_create("Programing");
  TCase *tc_core = tcase_create("lab13");
  tcase_add_test(tc_core, test_read_from_file);
  suite_add_tcase(s, tc_core);
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? 0 : 1;
}