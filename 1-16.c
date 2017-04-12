#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
	int len, max, curr;
	char start[MAXLINE], line[MAXLINE], longest[MAXLINE];
	
	max = curr = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		if (curr == 0)
			copy(start, line);
		curr += len;
		if (line[len - 1] == '\n') {
			if (curr > max) {
				max = curr;
				copy(longest, start);
			}
			curr = 0;
		}
	}
	if (max > 0) {
		printf("longest line had length %d\n", max);
		printf("%s", longest);
	}
	return 0;
}

int get_line(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[]) {
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

