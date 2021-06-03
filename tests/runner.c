#include "tests.h"

int main(void)
{
	int pass;
	printf("******************************************\n");
	printf("***       Unit Tests for libunit       ***\n");
	printf("******************************************\n");

	pass = basic_launcher();
	if (pass)
	{
		printf("all good");
		return (1);
	}
	printf("No good");
	return (0);
}
