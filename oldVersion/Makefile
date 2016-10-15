# variables
CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=libkarel64-lin.a -lcurses
OUTPUT=$@.run

# if not running, try to use libkarel64-lin.a

# targets
%:
	$(CC) $(CFLAGS) $@.c $(LDLIBS) -o $(OUTPUT)


