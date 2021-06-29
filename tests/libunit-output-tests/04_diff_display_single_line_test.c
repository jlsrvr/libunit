#include "tests.h"

static void file_writer(void)
{
	char *str = "One line\n";
	char *str2 = "One line";
	FILE *ptr = fopen("outputs/diff_output_test_file1.txt", "w");
	fprintf(ptr, "%s", str);
	fclose(ptr);
	ptr = fopen("outputs/diff_output_test_file2.txt", "w");
	fprintf(ptr, "%s", str2);
	fclose(ptr);
}

int diff_display_single_line_fail_test(void *p)
{
	(void)p;

	file_writer();
	return (file_diff("outputs/diff_output_test_file1.txt", "outputs/diff_output_test_file2.txt", 1));
}

int diff_display_single_line_pass_test(void *p)
{
	(void)p;

	file_writer();
	return (file_diff("outputs/diff_output_test_file2.txt", "outputs/diff_output_test_file2.txt", 1));
}
