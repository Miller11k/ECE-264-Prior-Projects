GCC=gcc
CFLAGS=-std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
EXEC = sort
TESTFLAGS = -DASCENDING

# Target for building the main executable.
all: main.c sort.c
	$(GCC) $(CFLAGS) -o $(EXEC) main.c sort.c

# Target for building the main executable with ASCENDING flag enabled.
ascending: main.c sort.c
	$(GCC) $(CFLAGS) $(TESTFLAGS) -o $(EXEC) main.c sort.c
	
# Target for running the testcases on the main executable.
test: all
	./$(EXEC) testcases/inp1
	./$(EXEC) testcases/inp2
	./$(EXEC) testcases/inp3	
	
# Target for running the testcases on the main executable with ASCENDING flag enabled.
test-ascending: ascending
	./$(EXEC) testcases/inp1
	./$(EXEC) testcases/inp2
	./$(EXEC) testcases/inp3	
	
# Target for cleaning up object files and the executable.
clean:
	rm -f $(EXEC)
	rm -f *.o
