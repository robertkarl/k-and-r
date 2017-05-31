CFLAGS = -Wunused-variable -Wno-implicit-int -Wno-return-type -g -pedantic -ansi -Werror

all: limits 2-02 2-03 2-04-squeeze any setbits

limits: 2-01-limits.c
	cc $(CFLAGS) 2-01-limits.c -o limits

2-02: 2-02.c
	cc $(CFLAGS) 2-02.c -o 2-02

2-03: 2-03.c
	cc $(CFLAGS) 2-03.c -o 2-03

2-04-squeeze: 2-04-squeeze.c
	cc $(CFLAGS) 2-04-squeeze.c -o 2-04-squeeze

any: 2-05.c
	cc $(CFLAGS) 2-05.c -o any

setbits: 2-06.c
	cc $(CFLAGS) 2-06.c -o setbits

clean:
	rm -f limits 2-02 2-03 2-04-squeeze any setbits

.PHONY:
	clean

