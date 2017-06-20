#include <stdio.h>

void unescape(char s[], char t[])
{
	while (*s != '\0') {
		if (*s == '\\') {
			s++;
			switch (*s) {
			case 'n':
				*t++ = '\n';
				break;
			case 'b':
				*t++ = '\b';
				break;
			case 't':
				*t++ = '\t';
				break;
			case 'a':
				*t++ = '\a';
				break;
			default:
				*t++ = '\\';
				*t++ = *s;
				break;
			}
		}
		else {
			*t++ = *s;
		}
		++s;
	}
	*t = '\0';
}

void escape(char s[], char t[])
{
	while (*s != '\0') {
		switch (*s) {
		case '\b':
			*t++ = '\\';
			*t++ = 'b';
			break;
		case '\a':
			*t++ = '\\';
			*t++ = 'a';
			break;
		case '\t':
			*t++ = '\\';
			*t++ = 't';
			break;
		case '\n':
			*t++ = '\\';
			*t++ = 'n';
			break;
		default:
			*t++ = *s;
			break;
		}
		++s;
	}
	*t = '\0';
}

main()
{
	char u[100];
	char t[100];
	escape("\tshort string with tabs \nand newlines\n", t);
	printf("%s", t);
	printf("\n\n");
	unescape(t, u);
	printf("%s", u);
	unescape("a string with a bell\a\n", u);
	printf("%s", u);
}
