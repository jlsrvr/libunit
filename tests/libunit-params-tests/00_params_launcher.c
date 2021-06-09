#include "tests.h"

int		params_launcher(void)
{
	t_unit_lst	*testlist;
	char *title;

	testlist = NULL;
	title = "Params Tests";
	int first;
	first = 1;
	load_test(&testlist, "Should pass", &one_params_test, &first);
	int second;
	second = 0;
	load_test(&testlist, "Should fail", &one_params_test, &second);
	return (launch_tests(&testlist, title));
}

