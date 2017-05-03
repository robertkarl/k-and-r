#include <stdio.h>
#include <string.h>

int inword(char s[], int c)
{
	int i;
	int len = strlen(s);
	for (i = 0; i < len; ++i) {
		if (s[i] == c)
			return 1;
	}
	return 0;
}

void squeeze(char s[], char t[])
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++) {
		if (!inword(t, s[i])) {
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}

main()
{
	char a[] = "the quick brown fox jumped whatever";
	char b[100];
	strcpy(b, a);
	squeeze(a, "abc");
	printf("%s, squeezed = %s\n", b, a);

}
