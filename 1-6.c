#include <stdio.h>

main() {
	int c;
	int cmp;
	/* for each char in the input including EOF:
		read it and compare with EOF;
		
	*/
	while (!(cmp = ((c = getchar()) != EOF)) || cmp == 1) {
		printf("input char %d. when compared with EOF:%d\n", 
			c, c != EOF);
		if (c == EOF)
			break;
	}
}
