tests: testme.c
		gcc -g -Wall -o testme testme.c

runtests: testme
		./testme

all: tests runtests

clean:
		rm -f testme
