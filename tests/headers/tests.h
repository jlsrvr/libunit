#ifndef TESTS_H
# define TESTS_H
# include "libunit.h"
# include "unistd.h"
# include "stdio.h"

int basic_launcher(void);
int OK_test(void);
int KO_test(void);
int segv_test(void);
int timeout_test(void);
int fpe_test(void);
int bus_test(void);
int sigabort_test(void);
#endif
