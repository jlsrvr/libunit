#include "tests.h"

int		basic_launcher(void)
{
	t_unit_lst	*testlist;
	char *title;

	testlist = NULL;
	title = "Basic Tests";
	load_test(&testlist, "This should be OK", &OK_test, NULL);
	load_test(&testlist, "This should KO", &KO_test, NULL);
	load_test(&testlist, "This should Segfault", &segv_test, NULL);
	load_test(&testlist, "This should Timeout", &timeout_test, NULL);
	load_test(&testlist, "This should return Floating Point Error", &fpe_test, NULL);
	load_test(&testlist, "This should SigAbort", &sigabort_test, NULL);
	load_test(&testlist, "This should Bus Error", &bus_test, NULL);
	return (launch_tests(&testlist, title));
}
