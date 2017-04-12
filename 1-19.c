#include <stdio.h>
#define MAXLINE 1000

void reverse(char line[], int len)
{
	int i, c, last;

	last = len - 1;
	i = 0;
	
	while (i < last) {
		c = line[i];	
		line[i] = line[last];
		line[last] = c;
		++i;
		--last;
	}
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

int main(int argc, char **argv)
{
	int len;
	char line[MAXLINE];

	len = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		reverse(line, len - 1);
		printf("%s", line);
	}
}

