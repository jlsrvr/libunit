# libunit

This is a small unit testing library created with the intent of making unit tests in C more accesible.

I plan on writting a step by step introductory guide on how to make the most of Test Driven Development (TDD) using this library.

## Usage:

```zsh
git clone git@github.com:jlsrvr/libunit.git
```
This will clone the library as well as a set of tests to benchmark the library, these are found in the tests folder at the root of the project.

For a basic example of how to use the library see the tests directory.

## Main function to be used :

Adding a single test to a suite:
```C
void load_test(t_unit_lst **lst, char *describe, int (*test)(void*), void *params);
```

Launching a test suite:
```C
int launch_tests(t_unit_lst **lst, char *title);
```

Adding a test suite:
```C
void load_suite(t_suite_lst **lst, int (*suite)(void));
```

Running all the test suites:
```C
int run_suites(t_suite_lst **suites, char *title);
```

[Redirecting output of the function you are testing](https://github.com/jlsrvr/libunit/blob/master/tests/libunit-output-tests/01_output_test.c):
```C
t_fd *redirect_stdout(char *filepath);
OR
t_fd *redirect_stderr(char *filepath);
```


Reversing the redirection:
```C
void	reverse_redirect(t_fd *my_fd);
```
[Comparing two files](https://github.com/jlsrvr/libunit/blob/master/tests/libunit-output-tests/02_diff_test.c):
```C
int		file_diff(char *filepath1, char *filepath2, int print);
```
