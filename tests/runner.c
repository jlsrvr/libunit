#include "tests.h"

int main(void)
{
	t_suite_lst *suites;

	suites = NULL;
	load_suite(&suites, &basic_launcher);
	load_suite(&suites, &params_launcher);
	load_suite(&suites, &output_launcher);
	return (run_suites(&suites, "Libunit"));
}
