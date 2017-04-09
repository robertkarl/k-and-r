#include <stdio.h>

#define IN	1
#define OUT	0

#define MAX_LEN 20

main()
{
	int c, state, wlen, i, j;
	int hist[MAX_LEN];
	
	state = OUT;
	wlen = 0;
	for (i = 0; i < MAX_LEN; i++)
		hist[i] = 0;
		
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if (wlen && wlen < MAX_LEN)
				++hist[wlen];
			wlen = 0;
		}
		else {
			if (state == OUT)
				state = IN;
			++wlen;
		}
	}
	for (i = 0; i < MAX_LEN; i++) {
		for (j = 0; j < hist[i]; j++)
			printf("X");
		putchar('\n');
	}
}
