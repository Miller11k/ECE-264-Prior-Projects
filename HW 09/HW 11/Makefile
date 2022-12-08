CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
LIBS = -lm
EXEC = hw11
SRCS = maze.c path.c solver.c mazehelper.c hw11.c list.c
OBJS = $(SRCS:%.c=%.o)
GCC = gcc $(CFLAGS)
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose --leak-check=full

$(EXEC): $(OBJS)
	$(GCC) $(OBJS) -o $(EXEC) 
test: maze1 maze2 maze3
maze1: $(EXEC)
	./$(EXEC)  testcases/maze1 output_m1
	diff -w output_m1 expected/expected1
maze2: $(EXEC)
	./$(EXEC) testcases/maze2 output_m2
	diff -w output_m2 expected/expected2
maze3: $(EXEC)
	./$(EXEC) testcases/maze3 output_m3
	diff -w output_m3 expected/expected3
.c.o:
	$(GCC) $(CFLAGS) -c $*.c
memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) testcases/maze1 output_m1
	$(VALGRIND) --log-file=log2 ./$(EXEC) testcases/maze2 output_m2
	$(VALGRIND) --log-file=log3 ./$(EXEC) testcases/maze3 output_m3

clean:
	rm -f output* log* *.o
	rm -f hw11