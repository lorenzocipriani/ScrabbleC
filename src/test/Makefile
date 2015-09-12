#makefile temporaneo, compilare gli obj nelle cartelle superiori (pathsubst)
CC=gcc
CFLAGS=-g -Wall
LDFLAGS=

all: test_dictionary

test_dictionary:
	$(CC) $(CFLAGS) -lm ../main/dictionary/dictionary.c timer.c test_dictionary.c -o $@

clean:
	rm test_dictionary
