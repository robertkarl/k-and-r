/* Check a C program for valid syntax
*/
#include <stdio.h>

#define MAXLINE 1000

/* State variables; updated as input is parsed */
int in_comment = 0;
int in_string = 0;
int in_literal = 0;

int is_char_pair(const char line[], int i, int len, char first, char second)
{
	int indices_ok = (i >= 0 && i + 1 < len);
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

int is_string_end(const char line[], int i, int len)
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

/* char literals like 'a' or '\t'
Consume function should return 1 past the string consumed
*/
int consume_literal(const char line[], int len, int i)
{
	extern int in_literal;
	if (i >= len || line[i] != '\'') {
		return i;
	}
	in_literal = 1;
	++i;
	if (i < len && line[i] == '\\') {
		i = i + 2;
	}
	else {
		++i;
	}
	if (i < len && line[i] == '\'')
		in_literal = 0;
	return i + 1;
}

int consume_string(const char line[], int len, int i)
{
	extern int in_string;
	if ((i >= 0 && i < len) && line[i] == '"') {
		in_string = 1;
		++i;
	}
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
	int line_no = 1;
	extern int in_string;
	char line[MAXLINE];

	int bracedepth = 0;
	int parens_depth = 0;
	int istart;

	while ((len = get_line(line, MAXLINE)) != 0) {
		i = 0;
		while (i < len) {
			if (in_string) {
				printf("no multiline strings: line %d\n",
					line_no);
				return -1;
			}
			istart = i;
			i = consume_literal(line, len, i);
			if (in_literal) {
				printf("malformed literal: line %d\n", line_no);
				return -1;
			}
			i = consume_comment(line, len, i);
			i = consume_string(line, len, i);
			/* ^^ do the above until i stops changing */
			if (istart == i) {
				if (!in_comment) {
					if (line[i] == '{')
						++bracedepth;
					else if (line[i] == '}')
						--bracedepth;
					++i;
				}
			}
		}
		++line_no;
	}
	if (bracedepth) {
		printf("unbalanced braces\n");
		return -1;
	}
	if (parens_depth) {
		printf("unbalanced parentheses\n");
		return -1;
	}
	if (in_comment) {
		printf("Expected end of comment\n");
		return -1;
	}
	if (in_string) {
		printf("Expected end of string\n");
		return -1;
	}
	return 0;
}

