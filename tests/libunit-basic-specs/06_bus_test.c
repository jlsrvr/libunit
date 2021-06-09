#include "tests.h"

void raise_bus_error(char *dest)
{
	dest = "bus error";
	dest[0] = 'J';
}

int bus_test(void *params)
{
	(void)params;
	char foo[2];
	raise_bus_error(foo);
	return (0);
}
