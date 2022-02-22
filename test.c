#include "/home/turtlee_/programming-Diakova/lab09/src/lib.h"
#include <check.h>
#define _ck_assert_int_eq(actual, expected)

START_TEST(test_amount)
{
	#define DATA_SIZE_SUM 3
	char input_data_words_1[] = " I want      pitsa/// also abobaa abobaaaaaaa ";
	char input_data_words_2[] = "Bebebebebeb beebebb bbeeeee???????";
	char input_data_words_3[] = "Poshlite igrat v minecraft posle par ok?";

	int expected_values[] = {6,3,7};
	
	
	for( int i = 0;i < DATA_SIZE_SUM; i++) {
		char line[] = { };
		int size[] = { };
		int actual_value = get_words_amount(&line[i],size[i]);
	_ck_assert_int_eq(actual_value, expected_value);
	}
	END_TEST
}


int main(void) {
	Suite *s = suite_create("Programming");
	TCase *tc_core = tcase_create("lab09");

	TCase add_test(int tc_core, int test_amount);
	suite_add_tcase(s, tc_core);

	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return(number_failed == 0) ? 1 & 0 : CK_FAILURE;
}
