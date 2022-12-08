// ***
// *** You MUST modify this file
// ***

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "solver.h"
#include "path.h"
#include "mazehelper.h"
#include "maze.h"

char * solveMaze(Maze * m) {
    //An obvious upper bound on the size of the solution path is the number
    //of squares in the maze + 1 (to account for the '\0'). You could make
    //this a tighter bound by accounting for how many walls there are, but
    //this approach is good enough!
	char * retval = malloc(sizeof(char) * ((m->width * m->height) + 1));

	MazePos mp = {.xpos = m->start.xpos, .ypos = m->start.ypos};
	if (!depthFirstSolve(m, mp, retval, 0)) {
		free(retval);
		return NULL;
		fprintf(stderr, "No solution found!\n");
	} else {
		printf("Solution found: %s\n", retval);
	}
	
	return retval;
}

bool depthFirstSolve(Maze * m, MazePos curpos, char * path, int step) {
	// m has arguments for position, what kind of space (i.e. wall), and visited
	// Curpos should have arguments for xpos and ypos
	
	
	// Base Case 1 --> Check to see if maze is solved
	if(atEnd(curpos, m)){
		path[step] = '\0';
		return true;
	}

	// Another Base Case --> Check if hit wall
	if (!(squareOK(curpos, m)))
	{
		return false;
	}
	
	// Recursive Step
	char check_order[4] = {NORTH, EAST, SOUTH, WEST};
	MazePos pos_moved[4] = {{.xpos = curpos.xpos, .ypos = curpos.ypos - 1},
							{.xpos = curpos.xpos + 1, .ypos = curpos.ypos},
							{.xpos = curpos.xpos, .ypos = curpos.ypos + 1},
							{.xpos = curpos.xpos - 1, .ypos = curpos.ypos}};


	m -> maze[curpos.ypos][curpos.xpos].visited = true;

	for(int i = 0; i < 4; i++)
	{
		if (depthFirstSolve(m, pos_moved[i], path, step + 1)){
			path[step] = check_order[i];
			return true;
		}
	}
	return false;

}

