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

int is_blank(char line[])
{
	int i;
	i = 0;
	while (line[i] != '\n') {
		if (line[i] != ' ')
			return 0;
		++i;
	}
	return 1;
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

void strip_line(char s[], int len)
{
	int i;
	for (i = len - 2; i >= 0; --i) {
		if (s[i] != '\t' || s[i] != ' ') {
			s[i + 1] = '\n';
			s[i + 2] = '\0';
			return;
		}
	}
}

main()
{
	int i, len, curr, end;
	char line[MAXLINE], start[MAXLINE];

	curr = len = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		if (!is_blank(line)) {
			strip_line(line, len);
			printf("%s", line);
		}
	}
}

