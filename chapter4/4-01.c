#include <stdio.h>

/* Rightmost index of t in s */
int strrindex(char s[], char t[])
{

	int i, j, k;
	int found = -1;
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			found = i;
	}
	return found;
}

main()
{
	char s[] = "Ah Love! could you and I with Fate conspire";
	char t[] = "ou";
	int res = strrindex(s, t);
	if (res >= 0)
		printf("found '%s' at index %d\n", t, strrindex(s, t));
}
