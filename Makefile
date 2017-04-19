CFLAGS = -I. -Wno-implicit-int -Wno-return-type -g -pedantic -ansi -Werror

all: detab entab fold

detab: 1-20-detab.c
	cc $(CFLAGS) 1-20-detab.c get_line.c -o detab

entab: 1-21-entab.c get_line.c
	cc $(CFLAGS) 1-21-entab.c get_line.c -o entab

fold: 1-22-fold.c get_line.c
	cc $(CFLAGS) get_line.c 1-22-fold.c -o fold

testfold: fold
	./fold < test.fold.1.in > test.fold.1.out
	diff test.fold.1.out test.fold.1.out.expected
	./fold < test.fold.2.in > test.fold.2.out
	diff test.fold.2.out test.fold.2.out.expected
	./fold < test.fold.3.in > test.fold.3.out
	diff test.fold.3.out test.fold.3.out.expected
	./fold < test.fold.4.in > test.fold.4.out
	diff test.fold.4.out test.fold.4.out.expected

clean:
	rm -f entab detab

