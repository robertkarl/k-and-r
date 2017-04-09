#include <stdio.h>

main()
{
	float fahr, celsius;
	int lower, upper, step;

	fahr = lower;
	printf("  F      C\n");
	for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
