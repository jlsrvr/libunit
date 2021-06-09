#ifndef TESTS_H
# define TESTS_H
# include "libunit.h"
# include "unistd.h"
# include "stdio.h"

int basic_launcher(void);
int OK_test(void *params);
int KO_test(void *params);
int segv_test(void *params);
int timeout_test(void *params);
int fpe_test(void *params);
int bus_test(void *params);
int sigabort_test(void *params);

int params_launcher(void);
int one_params_test(void *value);
#endif
