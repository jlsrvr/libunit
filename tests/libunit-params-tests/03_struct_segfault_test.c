#include "tests.h"

int struct_segfault_test(void *p)
{
	t_test *params = (t_test*)p;
	if (params->one && params->three[1] == '1')
		return (0);
	return (1);
}
