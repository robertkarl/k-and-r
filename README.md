# Robert Karl's K&R solutions 
(2nd edition, 51st printing, August 2013)

### Project goals
- Solve problems efficiently in pure C.
- Write portable solutions so the code can be tested almost anywhere.
	- Write in ANSI C (C89). 
	- Use POSIX makefiles, avoiding GNU Make extensions that may not be available.
- Be pedantic; turn on essentially all warnings `-Wunused-variable -Wno-implicit-int -Wno-return-type -pedantic -ansi -Werror`
- Use good K&R style (for a given problem, use only techniques that have already been covered)

### Usage
```sh
git clone https://github.com/robertkarl/k-and-r-exercises.git
cd k-and-r-exercises
make # recursively make all exercises. optionally use `pmake` (POSIX make)
```
