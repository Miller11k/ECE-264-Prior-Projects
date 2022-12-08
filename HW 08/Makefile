CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
LIBS = -lm
EXEC = hw8
SRCS = main.c shuffle.c
OBJS = $(SRCS:%.c=%.o)
GCC = gcc $(CFLAGS)
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose



$(EXEC): $(OBJS)
	$(GCC) $(OBJS) -o $(EXEC) 
test: HW_3C1 HW_3C2 HW_4C2 HW_6C2
HW_3C1: $(EXEC)
	./$(EXEC) 3 1 | sort > output_3_1
	diff -w output_3_1 expected/expected_3_1
HW_3C2: $(EXEC)
	./$(EXEC) 3 2 | sort > output_3_2
	diff -w output_3_2 expected/expected_3_2
HW_4C2: $(EXEC)
	./$(EXEC) 4 2 | sort > output_4_2
	diff -w output_4_2 expected/expected_4_2
HW_6C2: $(EXEC)
	./$(EXEC) 6 2 | sort > output_6_2
	diff -w output_6_2 expected/expected_6_2
.c.o:
	$(GCC) $(CFLAGS) -c $*.c
memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) 3 1 | sort > output_3_1
	$(VALGRIND) --log-file=log2 ./$(EXEC) 3 1 | sort > output_3_2
	$(VALGRIND) --log-file=log3 ./$(EXEC) 3 1 | sort > output_4_2
	$(VALGRIND) --log-file=log4 ./$(EXEC) 3 1 | sort > output_6_2


clean:
	rm -f *.o
	rm -f hw8
	rm -f output* log*