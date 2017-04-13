CFLAGS = -I. -Wno-return-type -g -pedantic -ansi -Werror

all: detab

detab: 1-20-detab.c
	cc $(CFLAGS) 1-20-detab.c  get_line.c -o detab

