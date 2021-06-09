#include "tests.h"

int		basic_launcher(void)
{
	t_unit_lst	*testlist;
	char *title;

	testlist = NULL;
	title = "Basic Tests";
	load_test(&testlist, "OK", &OK_test, NULL);
	load_test(&testlist, "KO", &KO_test, NULL);
	load_test(&testlist, "Segfault", &segv_test, NULL);
	load_test(&testlist, "Timeout", &timeout_test, NULL);
	load_test(&testlist, "Floating Point Error", &fpe_test, NULL);
	load_test(&testlist, "Bus Error", &bus_test, NULL);
	load_test(&testlist, "SigAbort", &sigabort_test, NULL);
	return (launch_tests(&testlist, title));
}
