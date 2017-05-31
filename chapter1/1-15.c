#include <stdio.h>

float to_celsius(int fahr)
{
	return (5.0 / 9.0) * (fahr - 32.0);
} 

main()
{
	float fahr;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	printf("  F      C\n");
	while (fahr <= upper) {
		printf("%3.0f %6.1f\n", fahr, to_celsius(fahr));
		fahr = fahr + step;
	}
}
