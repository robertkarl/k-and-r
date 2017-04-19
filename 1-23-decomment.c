/* Remove all comments from a C program
Notes:

* C comments don't nest

* Don't be fooled by character strings containing asterisk slash
  end of a  comment

* Don't be fooled by character constants like '"' which aren't string
  beginnings

*/
/* comments can also appear like *//* this. */
#include <stdio.h>

#define MAXLINE 1000

int is_char_pair(char line[], int i, int len, char first, char second)
{
	return i + 1 < len && line[i] == first && line[i + 1] == second;
}

int is_comment_start(char line[], int i, int len)
{
	return is_char_pair(line, i, len, '/', '*');
}

int is_comment_end(char line[], int i, int len)
{
	return is_char_pair(line, i, len, '*', '/');
}

int is_escaped_quote(char line[], int i, int len)
{
	return is_char_pair(line, i, len, '\\', '"');
}

int is_string_start(char line[], int i, int len)
{
	if (line[i] == '"') {
		if (i > 0 && i < len - 1) {
			if (line[i - 1] == '\'' && line[i + 1] == '\'')
				return 0;
		}
		return 1;
	}
	return 0;
}

main()
{
	int len;
	int i;
	int in_string = 0;
	int in_comment = 0;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) != 0) {
		i = 0;
		while (i < len) {
			if (!in_string) {
				if (in_comment && is_comment_end(line, i, len)) {
					in_comment = 0;
					i = i + 2;
				}
				if (is_comment_start(line, i, len))
					in_comment = 1;
			}
			else {
				if (line[i] == '"' && i > 0 && line[i] != '\\')
					in_string = 0;
			}
			if (!in_comment)
				putchar(line[i]);
			++i;
		}
	}
}
