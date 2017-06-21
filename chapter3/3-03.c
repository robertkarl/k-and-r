#include <stdio.h>

int isletter(char c)
{
	if (c >= 'a' && c <= 'z')
		return 1;
	else if (c >= 'A' && c <= 'Z')
		return 1;
	return 0;
}

/* Expand shorthand like a-z in argument s into abcd...xyz in t.
 * Assume t has enough space and s exists.
 */
void expand(char s[], char t[])
{
	char j;
	char *curr = s;
	while (*curr != '\0') {
		if (*curr == '-' && curr > s && *(curr + 1) > *(curr - 1)) {
			for (j = *(curr - 1) + 1; j <= *(curr + 1); ++j)
				*t++ = j;
			curr = curr + 2;
		}
		else
			*t++ = *curr++;
	}
	*t = '\0';
}

main()
{
	char t[100];
	expand("a-b-z-", t);
	printf("%s\n", t);
}

