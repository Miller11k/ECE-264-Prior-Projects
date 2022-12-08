# You MUST modify this file
CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
LIBS = -lm
EXEC = hw4
TESTFLAGS = -DTEST_INTEGRATE -DRUN_INTEGRATE
GCC = gcc $(CFLAGS) $(TESTFLAGS)


# builds hw4 using the integrate1, and all five functions
# creates 5 different executables, because of the dependences

$(EXEC): hw4.c integrator-hw4.c func1.c func2.c func3.c func4.c func5.c hw4.h
	$(GCC) hw4.c integrator-hw4.c func1.c func2.c func3.c func4.c func5.c -o $(EXEC) $(LIBS)

HW: $(EXEC)
	echo "Running 1st Test"
	./$(EXEC) testcases/test1 testcases/output1
	echo "Running 2nd Test"
	./$(EXEC) testcases/test2 testcases/output2
	echo "Running 3rd Test"
	./$(EXEC) testcases/test3 testcases/output3
	echo "Running 4th Test"
	./$(EXEC) testcases/test4 testcases/output4
clean:
	rm -f *.o
	rm -f testgen 
	rm -f *.gcda *.gcno gmon.out *gcov
	rm -f hw4 hw4.prof
