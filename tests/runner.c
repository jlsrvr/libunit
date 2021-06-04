#include "tests.h"

int main(void)
{
	t_suite_lst *suites;

	suites = NULL;
	load_suite(&suites, &basic_launcher);
	return (run_suites(&suites, "Libunit"));
}
