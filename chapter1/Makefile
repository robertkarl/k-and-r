CFLAGS = -Wunused-variable -Wno-implicit-int -Wno-return-type -g -pedantic -ansi -Werror

all: 1-01

test: testchecksyntax

detab: 1-20-detab.c
	cc $(CFLAGS) 1-20-detab.c ../get_line.c -o detab

1-01: 1-01.c
	cc $(CFLAGS) 1-01.c -o 1-01

checksyntax: 1-24-checksyntax.c ../get_line.c
	cc $(CFLAGS) 1-24-checksyntax.c ../get_line.c -o checksyntax

testchecksyntax: checksyntax
	./checksyntax < 1-24-checksyntax.c
	./checksyntax < tests/test.syntax.1.in
	! ./checksyntax < tests/test.syntax.2.in
	! ./checksyntax < tests/test.syntax.2.in

clean:
	rm -f 1-01 detab

.PHONY: test testchecksyntax clean

