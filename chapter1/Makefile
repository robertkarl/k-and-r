CFLAGS = -Wunused-variable -Wno-implicit-int -Wno-return-type -g -pedantic -ansi -Werror

all: 1-01

detab: 1-20-detab.c
	cc $(CFLAGS) 1-20-detab.c ../get_line.c -o detab

1-01: 1-01.c
	cc $(CFLAGS) 1-01.c -o 1-01
clean:
	rm -f 1-01 detab
