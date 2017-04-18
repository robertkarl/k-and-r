/* fold long input lines into shorter lines after the last non-blank 
character that occurs before the n-th column of input.

* If the input contains lines longer than MAXLINE characters, behavior is 
	undefined (further input may be ignored)

* If the first FOLDN characters of a line don't contain a blank or a tab, a
	newline will be inserted at character FOLDN - 1 and the rest wrapped.

*/

#define MAXLINE 1000
#define FOLDN 81

#include <stdio.h>
#include <string.h>

int cansplit(char s)
{
	return s == '\t' || s == ' ';
}

void splitline(char line[], int len)
{
	int i;
	int start = 0;

 	/* 82 for example, if line length is 80. 80 + newline + null byte */
	char toprint[FOLDN + 1];

	i = FOLDN - 1;
	while (start < len) {
		/* a "full line" has length FOLDN + 1 including the newline      */
		if (len - start <= FOLDN) {
			printf("%s", line + start);
			start = len;
		}
		else {
			while (i > 0 && !cansplit(line[i])) {
				--i;
			}
			if (i == 0)
				i = FOLDN - 1;
			strncpy(toprint, line + start, i);
			toprint[i] = '\n';
			toprint[i + 1] = '\0';
			printf("%s", toprint);
			start = start + i;
		}
	}
}

main()
{
	char line[MAXLINE];
	int len, i;

	while ((len = get_line(line, MAXLINE)) > 0) {
		splitline(line, len);
	}
}

