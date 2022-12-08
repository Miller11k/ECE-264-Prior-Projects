CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
LIBS = -lm
EXEC = hw10
SRCS = hw10.c main.c
OBJS = $(SRCS:%.c=%.o)
GCC = gcc $(CFLAGS)
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose



$(EXEC): $(OBJS)
	$(GCC) $(OBJS) -o $(EXEC) 
testall: test1 test2 test3 

test1: all
	./$(EXEC) 6 3 > output1
	diff -w output1 testcases/expected1

test2: all
	./$(EXEC) 4 6 > output2
	diff -w output2 testcases/expected2

test3: all
	./$(EXEC) 25 7 > output3
	diff -w output3 testcases/expected3

clean:
	rm -f $(EXEC)
	rm -f *.o
.c.o:
	$(GCC) $(CFLAGS) -c $*.c
memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) testcases/expected1 output1
	$(VALGRIND) --log-file=log2 ./$(EXEC) testcases/expected2 output2
	$(VALGRIND) --log-file=log3 ./$(EXEC) testcases/expected3 output3


clean:
	rm -f *.o
	rm -f hw10
	rm -f output* log*