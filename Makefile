# using my template Makefile from ECE 264
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g -Og $(WARNING) $(ERROR)

SRCS = main.c # a4.c
OBJS = $(SRCS:%.c=%.o)

a4: $(OBJS)
	$(GCC) $(OBJS) -o a4

.c.o:
	$(GCC) -c $*.c

clean: # remove all machine generated files
	rm -f a4 *.o output? *~