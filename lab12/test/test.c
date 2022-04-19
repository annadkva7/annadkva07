#include "../src/lib.h"
#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

START_TEST(test_searching)
{

  const int MAX_LENGHT = 128;
  char *data_input_text = (char*)malloc(MAX_LENGHT * sizeof(char));

  FILE *file;
  file = fopen("/home/turtlee_/programming-Diakova/lab12/assets/input_test.txt", "r");
  fgets(data_input_text, MAX_LENGHT, file);
  
  printf("%s", data_input_text);

  int SIZE = strlen(data_input_text);

  char *data_text = (char* )malloc(SIZE * sizeof(char));
  strcpy(data_text, data_input_text);

  char *data_expected_value = (char* )malloc(SIZE * sizeof(char));

  FILE *ffile;
  ffile = fopen("/home/turtlee_/programming-Diakova/lab12/assets/input_test1.txt", "r");
  fgets(data_expected_value, SIZE, ffile);

  int SIZE1 = strlen(data_expected_value);
  

  char *expected_value = (char* )malloc(SIZE1 * sizeof(char));
  strcpy(expected_value, data_expected_value);
  free(data_expected_value);

  char *result_data_searching = (char* )malloc(SIZE1 * sizeof(char));

  numbers_searching(data_text, result_data_searching);
  char *rresult_data_searching = (char* )malloc(SIZE1 * sizeof(char));
  rresult_data_searching = result_data_searching;


  /* for( int i = 0; i < SIZE; i++ ) {
    printf("%s", *(result_data_searching + i));
  } */
    
   /* for(int i = 0; i < SIZE1; i++) */
        ck_assert_str_eq(expected_value, rresult_data_searching);

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