#include <stdio.h>

int setbits(int x, int p, int n, int y)
{
	int to_overwrite_mask = ~(~0 << n) << (p + 1 - n);
	/* clear the bitfield to be overwritten */
	int tmp = x & ~to_overwrite_mask;
	int bits_to_insert = (y & (~(~0 << n))) << (p + 1 - n);
	return tmp | bits_to_insert;
}

main()
{
	int x = 0177; /* rightmost 7 bits set to 1 */
	int y = 24; /* last three bits are zero */
	printf("x is %d\n", x);
	printf("after setbits: %d\n", setbits(x, 4, 3, y));
}

