# using my template Makefile from ECE 264
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

SRCS = main.c # a1.c
OBJS = $(SRCS:%.c=%.o)

a1: $(OBJS)
	$(GCC) $(OBJS) -o a1

.c.o:
	$(GCC) -c $*.c

testmemory: a1
	$(VAL) ./a1 inputs/input3 output3
#testing only input3 and output3

# testall: test1 test2 test3 test4

# test1: a1
# 	./a1 inputs/input1 output1
# 	diff output1 expected/expected1

# test2: a1
# 	./a1 inputs/input2 output2
# 	diff output2 expected/expected2

# test3: a1
# 	./a1 inputs/input3 output3
# 	diff output3 expected/expected3

# test4: a1
# 	./a1 inputs/input4 output4
# 	diff output4 expected/expected4

clean: # remove all machine generated files
	rm -f a1 *.o output? *~