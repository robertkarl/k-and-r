CFLAGS = -Wunused-variable -Wno-implicit-int -Wno-return-type -g -pedantic -ansi -Werror

all: entab fold decomment 5-18-decl chapter1 chapter2

entab: 1-21-entab.c get_line.c
	cc $(CFLAGS) 1-21-entab.c get_line.c -o entab

fold: 1-22-fold.c get_line.c
	cc $(CFLAGS) get_line.c 1-22-fold.c -o fold

decomment: 1-23-decomment.c get_line.c
	cc $(CFLAGS) get_line.c 1-23-decomment.c -o decomment

chapter1:
	cd chapter1 && $(MAKE)

chapter2:
	cd chapter2 && $(MAKE)

chapter3:
	cd chapter3 && $(MAKE)

5-18-decl: 5-18-decl.c
	cc $(CFLAGS) 5-18-decl.c -o 5-18-decl

testfold: fold
	./fold < test.fold.1.in > test.fold.1.out
	diff test.fold.1.out test.fold.1.out.expected
	./fold < test.fold.2.in > test.fold.2.out
	diff test.fold.2.out test.fold.2.out.expected
	./fold < test.fold.3.in > test.fold.3.out
	diff test.fold.3.out test.fold.3.out.expected
	./fold < test.fold.4.in > test.fold.4.out
	diff test.fold.4.out test.fold.4.out.expected
	touch testfold

clean:
	rm -f entab fold decomment
	rm -f 5-18-decl
	rm -f testfold
	cd chapter1 && $(MAKE) clean
	cd chapter2 && $(MAKE) clean
	cd chapter3 && $(MAKE) clean

.PHONY: chapter1 chapter2 clean
