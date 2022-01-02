#include <iostream>
#include <stdio.h>

int main()
{
	int digit, count;
	long factor;

	printf("Vvedite celoe cheslo");
	scanf_s("%d", &digit);
	factor = 1;
	for (count = 1; count <= digit; count++)
		factor *= count;
	printf("Faktorial chisla %d raven %d", digit, factor);
	return 0;
}