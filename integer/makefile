OBJS = integer.o
OPTS = -Wall -Wextra

all: $(OBJS)
	gcc $(OPTS) $(OBJS) test.c -o exec

integer.o: integer.c integer.h
	gcc $(OPTS) -c integer.c

clean:
	rm *.o exec
