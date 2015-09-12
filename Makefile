#!/usr/bin/make -f

SHELL = /bin/sh

####    CONFIGURATION    ####

srcdir = ./src/main
objdir = ./build
exedir = ./bin

CC = gcc
YACC = bison -y

#DEFS = 

LIBS = -lm

DEBUG = -g
CFLAGS = -Wall -std=c11 $(DEBUG)
LFLAGS = -Wall $(DEBUG)
#LDFLAGS = -g

prefix = /usr/local

bindir = $(prefix)/bin

####    SOURCES & RULES    ####

SCRABBLE_OBJS := $(patsubst %.c,%.o,$(wildcard $(srcdir)/scrabbleC/*.c))
GAMEBOARD_OBJS := $(patsubst %.c,%.o,$(wildcard $(srcdir)/gameboard/*.c))
PLAYER1_OBJS := $(patsubst %.c,%.o,$(wildcard $(srcdir)/player1/*.c))
PLAYER2_OBJS := $(patsubst %.c,%.o,$(wildcard $(srcdir)/player2/*.c))
DICTIONARY_OBJS := $(patsubst %.c,%.o,$(wildcard $(srcdir)/dictionary/*.c))

.PHONY: all
all : scrabbleC gameboard player1 player2 dictionary

#scrabbleC : $(srcdir)/scrabbleC/*.c
#	$(CC) $(CFLAGS) -c $< -o $(objdir)/$@/$@.o 
#	$(CC) $(CFLAGS) -o $(exedir)/$@  $(objdir)/$@/*.o
	
scrabbleC : $(SCRABBLE_OBJS)
	cc -o $(exedir)/$@ $(SCRABBLE_OBJS)

gameboard : $(GAMEBOARD_OBJS)
	cc -o $(exedir)/$@ $(GAMEBOARD_OBJS)
	
player1 : $(PLAYER1_OBJS)
	cc -o $(exedir)/$@ $(PLAYER1_OBJS)
	
player2 : $(PLAYER2_OBJS)
	cc -o $(exedir)/$@ $(PLAYER2_OBJS)
	
dictionary : $(DICTIONARY_OBJS)
	cc -o $(exedir)/$@ $(DICTIONARY_OBJS)
	
.PHONY: install
install :


.PHONY: uninstall
uninstall :

.PHONY: clean
clean :
	rm -f $(srcdir)/dictionary/*.o
	rm -f $(srcdir)/gameboard/*.o
	rm -f $(srcdir)/player1/*.o
	rm -f $(srcdir)/player2/*.o
	rm -f $(srcdir)/scrabbleC/*.o
	rm -f $(exedir)/*

.PHONY: distclean
distclean :


.PHONY: dist
dist :


.PHONY: check
check:


