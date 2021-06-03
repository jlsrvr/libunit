#include "tests.h"

int		basic_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	printf("Basic Tests: ");
	load_test(&testlist, "OK", &OK_test);
	load_test(&testlist, "KO", &KO_test);
	load_test(&testlist, "Segfault", &segv_test);
	load_test(&testlist, "Timeout", &timeout_test);
	load_test(&testlist, "Floating Point Error", &fpe_test);
	load_test(&testlist, "Bus Error", &bus_test);
	load_test(&testlist, "SigAbort", &sigabort_test);
	return (launch_tests(&testlist));
}
