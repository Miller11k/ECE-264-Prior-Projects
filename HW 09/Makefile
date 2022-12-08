CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
LIBS = -lm
EXEC = hw9
SRCS = maze.c path.c solver.c mazehelper.c hw9.c
OBJS = $(SRCS:%.c=%.o)
GCC = gcc $(CFLAGS)
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose



$(EXEC): $(OBJS)
	$(GCC) $(OBJS) -o $(EXEC) 
test: maze1 maze2 maze3 maze4 maze5
maze1: $(EXEC)
	./$(EXEC)  testcases/maze1 output_m1
maze2: $(EXEC)
	./$(EXEC) testcases/maze2 output_m2
maze3: $(EXEC)
	./$(EXEC) testcases/maze3 output_m3
maze4: $(EXEC)
	./$(EXEC) testcases/maze4 output_m4
maze5: $(EXEC)
	./$(EXEC) testcases/maze5 output_m5
.c.o:
	$(GCC) $(CFLAGS) -c $*.c
memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) testcases/maze1 output_m1
	$(VALGRIND) --log-file=log2 ./$(EXEC) testcases/maze2 output_m2
	$(VALGRIND) --log-file=log3 ./$(EXEC) testcases/maze3 output_m3
	$(VALGRIND) --log-file=log4 ./$(EXEC) testcases/maze4 output_m4
	$(VALGRIND) --log-file=log5 ./$(EXEC) testcases/maze5 output_m5


clean:
	rm -f *.o
	rm -f hw9
	rm -f output* log*