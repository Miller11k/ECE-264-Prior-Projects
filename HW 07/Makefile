CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
LIBS = -lm
EXEC = hw7
SRCS = main.c shuffle.c
TESTFLAGS = -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE
OBJS = $(SRCS:%.c=%.o)
GCC = gcc $(CFLAGS) $(TESTFLAGS)
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose



$(EXEC): $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o $(EXEC) 
test: HW_4C HW_8C HW_11C
HW_4C: $(EXEC)
	./$(EXEC) 4 | sort > output4
	diff -w output4 expected/expected4
HW_8C: $(EXEC)
	./$(EXEC) 8 | sort > output8
	diff -w output8 expected/expected8
HW_11C: $(EXEC)
	./$(EXEC) 11 | sort > output11
	diff -w output11 expected/expected11
.c.o:
	$(GCC) $(CFLAGS) $(TESTFLAGS) -c $*.c
memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) 4 | sort > output4
	$(VALGRIND) --log-file=log2 ./$(EXEC) 8 | sort > output8
	$(VALGRIND) --log-file=log3 ./$(EXEC) 11 | sort > output11


clean:
	rm -f *.o
	rm -f hw7 hw7.prof
	rm -f shuffle.h.gch
	rm -f output4
	rm -f output8
	rm -f output11
