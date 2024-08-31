# using my template Makefile from ECE 264
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

SRCS = main.c # a1.c
OBJS = $(SRCS:%.c=%.o)

a1: $(OBJS)
	$(GCC) $(OBJS) -o a1

.c.o:
	$(GCC) -c $*.c

clean: # remove all machine generated files
	rm -f a1 *.o output? *~