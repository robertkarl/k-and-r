/* Detab */
#include <stdio.h>

#define MAXLEN 1000

int get_line(char line[], int lim);

main() {
 	int i, spaces, j, len;
	int pos; /* pos of the output line */
	int sw = 4;
	char line[MAXLEN];

	while ((len = get_line(line, MAXLEN)) != 0) {
		pos = 0;
		for (i = 0; i < len; ++i) {
			if (line[i] == '\t') {
				spaces = sw - (pos % sw);
				for (j = 0; j < spaces; ++j)
					putchar(' ');
				pos = pos + spaces;
			}
			else {
				putchar(line[i]);
				++pos;
			}
		}
	}
}

