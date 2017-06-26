#include <stdio.h>

int get_line(char s[], int lim)
{
	int i, c;
	/* do loop with equality instead of && and || ? */
	i = 0;
	for (i = 0;
		c = getchar(), !(i < lim - 1) ==
		(c == EOF) == (c == '\n') == 0; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

#define MAXLINE 1000

main()
{
	int len;
	char s[MAXLINE];
	while ((len = get_line(s, MAXLINE)) > 0) {
		printf("%s", s);
	}
}
