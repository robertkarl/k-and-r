/* Check a C program for valid syntax
*/
#include <stdio.h>

#define MAXLINE 1000

/* State variables; updated as input is parsed */
int in_comment = 0;
int in_string = 0;

int is_char_pair(char line[], int i, int len, char first, char second)
{
	int indices_ok = i >= 0 && i + 1 < len; 
	return indices_ok && line[i] == first && line[i + 1] == second;
}

int is_comment_start(char line[], int i, int len)
{
	return is_char_pair(line, i, len, '/', '*');
}

int is_comment_end(char line[], int i, int len)
{
	return is_char_pair(line, i, len, '*', '/');
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

int is_string_end(char line[], int i, int len)
{
	if (line[i] == '"')
		return !is_char_pair(line, i - 1, len, '\\', '"');
	return 0;
}

int is_whitespace(char c)
{
	return c == ' ' || c == '\t' || c == '\n';
}

int consume_comment(char line[], int len, int i)
{
	extern int in_comment;
	if (is_char_pair(line, i, len, '/', '*'))
		in_comment = 1;
	if (!in_comment)
		return i;
	while (i < len) {
		if (is_comment_end(line, i, len)) {
			in_comment = 0;
			return i + 2;
		}
		++i;
	}
	return i;
}

int consume_string(char line[], int len, int i)
{
	extern int in_string;

	if (!in_string)
		return i;
	while (i < len) {
		if (is_string_end(line, i, len)) {
			in_string = 0;
			return i + 1;
		}
		++i;
	}
	return i;
}

main()
{
	int len;
	int i = 0;
	int in_string = 0;
	char line[MAXLINE];

	int bracedepth = 0;
/* */
	while ((len = get_line(line, MAXLINE)) != 0) {
		if (in_string)
			return -1;
		i = 0;
		while (i < len) {
			i = consume_comment(line, len, i);
			i = consume_string(line, len, i);
			/* if we're not in a string, not in a comment,
			then keep consuming characters */
			if (!in_comment && !in_string) {
				if (line[i] == '{')
					++bracedepth;
				else if (line[i] == '}')
					--bracedepth;
				++i;
			}
		}
	}
	if (bracedepth || in_comment || in_string)
		return -1;
	return 0;
}

