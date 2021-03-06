#include "tests.h"

static void file_writer(void)
{
	char *str = "Lorem ipsum \ndolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore \tet dolore magna aliqua. Ut enim ad minim veniam,\n quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis \naute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. \nExcepteur sint oat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\nthis is should not appear\nthis line is different not the next\n";
	char *str2 = "Lorem ipsum \ndolor sit , consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veiniam,\n quis nostrud exercitation ullamco laboris nisi ut  ex ea commodo consequat. Duis3 \naute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.\nExcepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\nthis is should not appear\nthis line is different not the next";
	FILE *ptr = fopen("outputs/diff_output_test_file1.txt", "w");
	fprintf(ptr, "%s", str);
	fclose(ptr);
	ptr = fopen("outputs/diff_output_test_file2.txt", "w");
	fprintf(ptr, "%s", str2);
	fclose(ptr);
}

int diff_display_fail_test(void *p)
{
	(void)p;

	file_writer();
	return (file_diff("outputs/diff_output_test_file1.txt", "outputs/diff_output_test_file2.txt", 1));
}

int diff_display_pass_test(void *p)
{
	(void)p;

	file_writer();
	return (file_diff("outputs/diff_output_test_file2.txt", "outputs/diff_output_test_file2.txt", 1));
}
