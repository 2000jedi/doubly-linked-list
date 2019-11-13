CC = gcc
PROGRAMS = test
CFLAGS = -g -O3 -std=c99 -Wall -Werror

programs: $(PROGRAMS)

test: test.o linkedlist.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	-rm $(PROGRAMS) *.o
	-rm -r *.dSYM
	-rm test