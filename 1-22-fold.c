/* fold long input lines into shorter lines after the last non-blank 
character that occurs before the n-th column of input.

* opening whitespace is left alone

* A split always occurs on a blank, the blank is converted to a newline

* If the input contains lines longer than MAXLINE characters, behavior is 
	undefined (further input may be ignored)

* If the first FOLDN characters of a line don't contain a blank or a tab, a
	newline will be inserted at character FOLDN - 1 and the rest wrapped.

*/

#define MAXLINE 1000
#define FOLDN 80

#include <stdio.h>
#include <string.h>

int cansplit(char s)
{
	return s == '\t' || s == ' ';
}

int findsplit(char line[], int i, int max_nchars)
{
	while (i > 0 && !cansplit(line[i])) {
		--i;
	}
	while (i > 0 && line[i - 1] == ' ')
		--i;
	if (i == 0)
		return FOLDN;
	return i;
}

void splitline(char line[], int len)
{
	int i;
	int start = 0;

 	/* include space for newline and null byte */
	char toprint[FOLDN + 2];

	i = FOLDN - 1;
	while (start < len) {
		/* a "full line" has length FOLDN + 1 including the newline      */
		if (len - start <= FOLDN + 1) {
			printf("%s", line + start);
			start = len;
		}
		else {
			i = findsplit(line, start + FOLDN, FOLDN);
			strncpy(toprint, line + start, i - start);
			toprint[i - start] = '\n';
			toprint[i - start + 1] = '\0';
			printf("%s", toprint);
			start = i;
			if (line[start] == ' ')
				++start;
		}
	}
}

main()
{
	char line[MAXLINE];
	int len;

	while ((len = get_line(line, MAXLINE)) > 0) {
		splitline(line, len);
	}
}

