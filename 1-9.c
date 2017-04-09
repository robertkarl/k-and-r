#include <stdio.h>

main() {
	int nblanks;
	int c;

	nblanks = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++nblanks;
		}
		else
		{
			if (nblanks) {
				nblanks = 0;
				putchar(' ');
			}
			putchar(c);
		}
	}
}
