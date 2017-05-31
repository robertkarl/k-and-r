#include <stdio.h>

#define IN	1
#define OUT	0

#define MAX_LEN 27 /* A-Z and whitespace */

main()
{
	int c, val, state, wlen, i, j, delim;
	int hist[MAX_LEN];
	
	state = OUT;
	wlen = 0;
	for (i = 0; i < MAX_LEN; i++)
		hist[i] = 0;
		
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t')
			++hist[MAX_LEN - 1];
		val = -1;
		if (c - 'A' < 26)
			val = c - 'A';
		else if (c - 'a' < 26)
			val = c - 'a';
		if (val >= 0)
			++hist[val];
	}

	for (i = 0; i < MAX_LEN; i++) {
		
		delim = 'a' + i;
		if (i >= MAX_LEN - 1)
			delim = ' ';
		printf("%c: ", delim);
		for (j = 0; j < hist[i]; j++)
			printf("X");
		putchar('\n');
	}
}
