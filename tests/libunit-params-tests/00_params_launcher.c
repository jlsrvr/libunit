#include "tests.h"

int		params_launcher(void)
{
	t_unit_lst	*testlist;
	char *title;

	testlist = NULL;
	title = "Params Tests";
	int first;
	first = 1;
	load_test(&testlist, "Integer: pass", &one_params_test, &first);
	int second;
	second = 0;
	load_test(&testlist, "Integer: fail", &one_params_test, &second);
	load_test(&testlist, "Struct: pass", &struct_params_test, &(t_test){1, '1', NULL});
	load_test(&testlist, "Struct: fail", &struct_params_test, &(t_test){0, '1', NULL});
	load_test(&testlist, "Struct: fail", &struct_params_test, &(t_test){1, '4', NULL});
	load_test(&testlist, "Struct: segfault", &struct_segfault_test, &(t_test){1, '4', NULL});
	load_test(&testlist, "Struct: string", &struct_segfault_test, &(t_test){1, '1', "111"});
	return (launch_tests(&testlist, title));
}

