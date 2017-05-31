CFLAGS = -Wunused-variable -Wno-implicit-int -Wno-return-type -g -pedantic -ansi -Werror

all: detab entab fold decomment checksyntax 5-18-decl chapter1 chapter2

detab: 1-20-detab.c
	cc $(CFLAGS) 1-20-detab.c get_line.c -o detab

entab: 1-21-entab.c get_line.c
	cc $(CFLAGS) 1-21-entab.c get_line.c -o entab

fold: 1-22-fold.c get_line.c
	cc $(CFLAGS) get_line.c 1-22-fold.c -o fold

decomment: 1-23-decomment.c get_line.c
	cc $(CFLAGS) get_line.c 1-23-decomment.c -o decomment

checksyntax: 1-24-checksyntax.c get_line.c
	cc $(CFLAGS) 1-24-checksyntax.c get_line.c -o checksyntax

chapter1:
	cd chapter1 && $(MAKE)

chapter2:
	cd chapter2 && $(MAKE)

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

testchecksyntax: checksyntax
	./checksyntax < 1-24-checksyntax.c
	./checksyntax < test.syntax.1.in
	! ./checksyntax < test.syntax.2.in
	! ./checksyntax < test.syntax.2.in

clean:
	rm -f entab detab fold decomment checksyntax
	rm -f 5-18-decl
	rm -f testfold
	cd chapter1 && $(MAKE) clean
	cd chapter2 && $(MAKE) clean

.PHONY: chapter1 chapter2 clean testchecksyntax
