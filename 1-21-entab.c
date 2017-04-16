/* Replace strings of blanks by the minimum number of tabs and blanks
to achieve the same spacing

Give precedence to spaces when either would work.
*/

#include <stdio.h>

int get_line(char line[], int lim);

#define MAXLINE 1000

int are_blanks(char line[], int start, int end)
{
	int i;
	for (i = start; i < end; ++i)
		if (line[i] != ' ')
			return 0;
	return 1;
}

void entab_line(char line[], int len, int sw)
{
	int offset, i, boundary;

	offset = 0;
	i = 0;
	while (i < len) {
		offset = offset % sw;
		boundary = i + (sw - offset);
		if (boundary - i > 1 && are_blanks(line, i, boundary)) {
			putchar('\t');
			i = boundary;
			offset = 0;
		}
		else {
			putchar(line[i]);
			++i;
			++offset;
		}
	}
}

main()
{
	int len;
	int sw = 4; /* shift width, or tab width */
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) != 0) {
		entab_line(line, len, sw);
	}
}
