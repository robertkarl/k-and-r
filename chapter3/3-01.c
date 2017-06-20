#include <stdio.h>

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int binsearch_alt(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	mid = (low + high) / 2
	high = n - 1;
	while (low <= high) {
		if (x < v[mid])
			high = mid - 1;
		else 
			low = mid;
		mid = (low+high) / 2;
	}
	if (v[mid] == x)
		return mid;
	return -1;
}


int main()
{
	int v[] = {0,1,2,3};
	printf("%d\n", binsearch_alt(2, v, 4));
}

