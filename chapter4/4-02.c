#include <ctype.h>
#include <stdio.h>

int atoi(char s[])
{
	int val = 0;
	int sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')
		s++;
	
	while (*s != '\0') {
		val *= 10;
		val += *s - '0';
		s++;
	}
	return sign * val;
}

double atof(char s[])
{
	double val, power;
	int i, sign;
	int sci_not_exp;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	val = sign * val / power;

	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		sci_not_exp = atoi(s + i);
		while (sci_not_exp != 0) {
			val = (sci_not_exp > 0) ? val * 10 : val / 10;
			(sci_not_exp > 0) ? sci_not_exp-- : sci_not_exp++;
		}
		
	}
	return val;
}


main(int argc, char **argv)
{
	printf("%s --> %f\n", argv[1], atof(argv[1]));
}

