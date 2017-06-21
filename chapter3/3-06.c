#include <stdio.h>

#define WORDSIZE 32

void reverse(char s[]);

void itoa(int n, char s[], int minwidth)
{
	int i, signbitset;
	unsigned input = (unsigned)n;
	unsigned signmask = 1 << (WORDSIZE - 1);
	int nchars = 0;

	signbitset = input >> (WORDSIZE - 1);
	input = (~signmask) & input;
	if (signbitset)
		input = signmask - input; /* signmask == 2 **(wordsize -1) */
	i = 0;
	do {
		s[i++] = input % 10 + '0';
		nchars++;
	} while ((input /= 10) > 0);
	if (signbitset) {
		s[i++] = '-';
		nchars++;
	}
	while (nchars++ < minwidth)
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}

main()
{
	char s[100];
	itoa(-10, s, 10);
	printf("%s", s);
}
