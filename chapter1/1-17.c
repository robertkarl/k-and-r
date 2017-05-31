#include <stdio.h>
#define MAXLINE 1000
#define PRINTSIZE 80

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

int get_line(char s[], int lim)
{
	int i, c;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

main()
{
	int len, curr;
	char line[MAXLINE], start[MAXLINE];

	curr = len = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		if (curr == 0) {
			copy(start, line);
		}
		curr += len;
		if (line[len - 1] == '\n') {
			if (curr > PRINTSIZE)
				printf("%s", start);
			curr = 0;
		}
		if (len == MAXLINE - 1) {
			start[MAXLINE - 2] = '\n';
			start[MAXLINE - 1] = '\0';
		}
	}
}

