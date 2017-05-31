#include <limits.h>
#include <stdio.h>

main()
{
	/*short s;
	unsigned short us;
	int i;
	unsigned int ui;
	long l;
	unsigned long ul;
	char c;
	unsigned char uc;
	*/
	
	printf("char: %d  %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("char: %d  %d\n", 0, UCHAR_MAX);

	printf("short: %d  %d\n", SHRT_MIN, SHRT_MAX);
	printf("ushort: %u  %u\n", 0, USHRT_MAX);

	printf("int: %d %d\n", INT_MIN, INT_MAX);
	printf("uint: %u %u\n", 0, UINT_MAX);

	printf("long: %ld %ld\n", LONG_MIN, LONG_MAX);
	printf("ulong: %lu %lu\n", (unsigned long)0, ULONG_MAX);

}
