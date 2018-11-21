OBJS = dll.o
OPTS = -Wall -Wextra

all: $(OBJS)
	gcc $(OPTS) $(OBJS) test.c -o exec

dll.o: dll.c dll.h
	gcc $(OPTS) -c dll.c