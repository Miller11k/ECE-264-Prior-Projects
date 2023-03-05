CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS)
EXEC = eliminate

TESTFLAGS = -DTEST_ELIMINATE

# Target for building the main executable with test flag enabled.
all: main.c eliminate.c
	$(GCC) $(TESTFLAGS) -o $(EXEC) main.c eliminate.c
	
# Target for running all test cases.
testall: test1 test2 test3 

# Target for running test case 1.
test1: all
	./$(EXEC) 6 3 > output1		# run your program with n=6, k=3 and output to file output1          
	diff -w output1 testcases/expected1 
    # the -w option in diff command means ignoring all white spaces in the diff comparison

# Target for running test case 2.
test2: all
	./$(EXEC) 4 6 > output2		# run your program with n=4, k=6 and output to file output2
	diff -w output2 testcases/expected2

# Target for running test case 3.
test3: all
	./$(EXEC) 25 7 > output3	# run your program with n=25, k=7 and output to file output3
	diff -w output3 testcases/expected3

# Target for cleaning up object files and the executable.
clean:
	rm -f $(EXEC)
	rm -f *.o
