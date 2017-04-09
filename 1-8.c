#include <stdio.h>

main() {
	double ws;
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\n' || c == ' ' || c == '\t')
			ws += 1;
	}
	printf("%.0f\n", ws);

}
