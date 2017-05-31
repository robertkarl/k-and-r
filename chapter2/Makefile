CFLAGS = -Wunused-variable -Wno-implicit-int -Wno-return-type -g -pedantic -ansi -Werror

limits: 2-01-limits.c
	cc $(CFLAGS) 2-01-limits.c -o limits

2-02: 2-02.c
	cc $(CFLAGS) 2-02.c -o 2-02

2-03: 2-03.c
	cc $(CFLAGS) 2-03.c -o 2-03

2-04-squeeze: 2-04-squeeze.c
	cc $(CFLAGS) 2-04-squeeze.c -o 2-04-squeeze

clean:
	rm -f limits 2-02 2-03 2-04-squeeze

.PHONY:
	clean
