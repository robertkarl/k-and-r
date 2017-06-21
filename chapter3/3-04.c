#include <stdio.h>
#include <limits.h>
/*
 * itoa doesn't handle n = -2**(wordsize - 1). In binary `n` is 10....0
 *     To convert to positive, subtract 1 from the rightmost bits (zero). 
 *     The int overflows (we get all 1s). Flip bits and signed result is 0.
 * 
 * To prevent this: Cast int to unsigned.
 * Store and clear the sign bit.
 * Complement if the int was negative.
 * This resulting int may use all 32 bits (so we can store 2**(wordsize-1)).
 * Now perform itoa and prepend the negative sign if needed
 */

#define WORDSIZE 32

void itoa(int n, char s[])
{
	int i, signbitset;
	unsigned input = (unsigned)n;
	unsigned signmask = 1 << (WORDSIZE - 1);
	signbitset = input >> (WORDSIZE - 1);
	input = (~signmask) & input;
	if (signbitset)
		input = signmask - input; /* signmask == 2 **(wordsize -1) */
	i = 0;
	do {
		s[i++] = input % 10 + '0';
	} while ((input /= 10) > 0);
	if (signbitset)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

main()
{
	char s[100];
	int inputs[100] = {123, -123, 1, 0};
	int *curr = inputs;

	inputs[2] = 1 << 31;
	while (*curr) {
		itoa(*curr, s);
		printf("%d --> %s\n", *curr, s);
		curr++;
	}
}

