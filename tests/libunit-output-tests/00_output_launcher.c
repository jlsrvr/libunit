#include "tests.h"

int		output_launcher(void)
{
	t_unit_lst	*testlist;
	char *title;

	testlist = NULL;
	title = "Output catching tests";
	load_test(&testlist, "Pass no output", &pass_output_test, NULL);
	return (launch_tests(&testlist, title));
}

