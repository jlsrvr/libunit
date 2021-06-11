#include "tests.h"

int		output_launcher(void)
{
	t_unit_lst	*testlist;
	char *title;

	testlist = NULL;
	title = "Output catching tests";
	load_test(&testlist, "Catching output", &pass_output_test, NULL);
	load_test(&testlist, "Diff of two identical files", &diff_test, "Pass");
	load_test(&testlist, "Diff of two different files", &diff_test, "Fail");
	load_test(&testlist, "Display the diff between two files", &diff_display_fail_test, NULL);
	load_test(&testlist, "Display diff of two identical files", &diff_display_pass_test, NULL);
	return (launch_tests(&testlist, title));
}

