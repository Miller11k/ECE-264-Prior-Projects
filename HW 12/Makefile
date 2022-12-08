CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
LIBS = -lm
EXEC = hw12
TESTFLAGS = -DTEST_BUILDTREE
SRCS = main.c tree.c
GCC = gcc $(CFLAGS) $(TESTFLAGS)
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose --leak-check=full

$(EXEC): $(SRCS)
	$(GCC) $(SRCS) -o $(EXEC) 
test: pre1 pre2 pre3 pre4 pre5 pre6
pre1: $(EXEC)
	./$(EXEC) testcases/test1in testcases/test1post output1
	diff -w output1 expected/expected1
pre2: $(EXEC)
	./$(EXEC) testcases/test2in testcases/test2post output2
	diff -w output2 expected/expected2
pre3: $(EXEC)
	./$(EXEC) testcases/test3in testcases/test3post output3
	diff -w output3 expected/expected3
pre4: $(EXEC)
	./$(EXEC) testcases/test4in testcases/test4post output4
	diff -w output4 expected/expected4
pre5: $(EXEC)
	./$(EXEC) testcases/test5in testcases/test5post output5
	diff -w output5 expected/expected5
pre6: $(EXEC)
	./$(EXEC) testcases/test6in testcases/test6post output6
	diff -w output6 expected/expected6
.c.o:
	$(GCC) $(CFLAGS) -c $*.c
memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) testcases/test1in testcases/test1post output1
	$(VALGRIND) --log-file=log2 ./$(EXEC) testcases/test2in testcases/test2post output2
	$(VALGRIND) --log-file=log3 ./$(EXEC) testcases/test3in testcases/test3post output3
	$(VALGRIND) --log-file=log4 ./$(EXEC) testcases/test4in testcases/test4post output4
	$(VALGRIND) --log-file=log5 ./$(EXEC) testcases/test5in testcases/test5post output5
	$(VALGRIND) --log-file=log6 ./$(EXEC) testcases/test6in testcases/test6post output6

clean:
	rm -f output* log* *.o
	rm -f hw12