#include <stdio.h>
#include <string.h>
#include <ctype.h>

int hexval(char s)
{
	if (isdigit(s))
		return s - '0';
	s = tolower(s);
	return 10 + (s - 'a');
}

int htoi(char s[])
{
	int len = strlen(s);
	int i;
	int val = 0;
	if (len >= 2 && s[0] == '0') {
		if (tolower(s[1]) == 'x') {
			s = s + 2;
			len -= 2;
		}
	}
	for (i = len - 1; i >= 0; --i) {
		val = val << 4;
		val |= hexval(s[i]);
	}
	return val;
}

main()
{
	char s[] = "0xa123";
	char t[] = "a123";
	printf("%s %d\n", s, htoi(s));
	printf("%s %d\n", t, htoi(t));

}
