
CFLAGS = -Wunused-variable -Wno-implicit-int -Wno-return-type -g -pedantic -ansi -Werror

all: 3-2 3-03 3-04 itob

3-2: 3-2.c
	cc $(CFLAGS) 3-2.c -o 3-2

3-03: 3-03.c
	cc $(CFLAGS) 3-03.c -o 3-03

3-04: 3-04.c reverse.c
	cc $(CFLAGS) reverse.c 3-04.c -o 3-04

itob: 3-05-itob.c reverse.c
	cc $(CFLAGS) 3-05-itob.c reverse.c -o itob

clean:
	rm -f 3-2 3-03 3-04 itob

