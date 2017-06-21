#include <stdio.h>

/* itob
 * Convert `n` to base `b`. Store result in 's'
 * b is one of : {16, 10, 8, 2}
 * s is a string with enough space
 */
void itob(int n, char s[], unsigned b);

#define WORDSIZE 32

void reverse(char s[]);

char convertword(unsigned n, unsigned b)
{
	n = n % b;
	switch(b) {
	case 16:
		if (n >= 10) return 'a' + n - 10;
	case 10:
	case 8:
	case 2:
		return '0' + n;
	default:
		return '0';
	}
}

void itob(int n, char s[], unsigned b)
{
	int i, sign;
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = convertword(n, b);
	} while ((n /= b) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

main()
{
	int args[100] = {-15, 16, 
		15, 16,
		0x10F, 16,
		0x1ff, 8,
		1 << (WORDSIZE - 2), 16,
		1 << (WORDSIZE - 1), 16,
		1 << (WORDSIZE - 1), 2,
	0};
	int *curr = args;
	char s[100];
	
	while (*curr) {
		int n = *curr++;
		int base = *curr++;
		itob(n, s, base);
		printf("%d in base %d is %s\n", n, base, s);
	}

}

