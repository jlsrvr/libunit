#include "libunit.h"

int file_diff(char *filepath1, char *filepath2)
{
	FILE *fptr1;
	FILE *fptr2;
	char one;
	char two;

	fptr1 = fopen(filepath1, "r");
	if (!fptr1)
		return (1);
	fptr2 = fopen(filepath2, "r");
	if (!fptr2)
	{
		fclose(fptr1);
		return (1);
	}
	do
	{
		one = fgetc(fptr1);
		two = fgetc(fptr2);
		if (one != two)
			return (1);
	} while (one != EOF && two != EOF);
	if (one == EOF && two == EOF)
		return (0);
	return (1);
}
