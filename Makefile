CFLAGS = -I. -Wno-implicit-int -Wno-return-type -g -pedantic -ansi -Werror

all: detab entab fold

detab: 1-20-detab.c
	cc $(CFLAGS) 1-20-detab.c get_line.c -o detab

entab: 1-21-entab.c get_line.c
	cc $(CFLAGS) 1-21-entab.c get_line.c -o entab

fold: 1-22-fold.c get_line.c
	cc $(CFLAGS) get_line.c 1-22-fold.c -o fold

clean:
	rm -f entab detab

