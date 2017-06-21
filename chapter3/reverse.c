void reverse(char s[])
{
	char *t = s;
	char tmp;
	while (*t)
		++t;
	--t;
	while (s < t) {
		tmp = *s;
		*s++ = *t;
		*t-- = tmp;	
	}
}
