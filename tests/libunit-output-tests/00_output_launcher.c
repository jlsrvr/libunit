#include "tests.h"

int		output_launcher(void)
{
	t_unit_lst	*testlist;
	char *title;

	testlist = NULL;
	title = "Output catching tests";
	load_test(&testlist, "Pass no output", &pass_output_test, NULL);
	load_test(&testlist, "Pass diff", &diff_test, "Pass");
	load_test(&testlist, "Fail diff", &diff_test, "Fail");
	return (launch_tests(&testlist, title));
}

