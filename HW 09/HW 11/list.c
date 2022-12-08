// ***
// *** You MUST modify this file
// ***

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

/** INTERFACE FUNCTIONS **/

PathLL * buildPaths() {
	//Allocate and initialize an empty Path linked list
	PathLL * retval = malloc(sizeof(PathLL));
	retval->head = NULL;
	return retval;
}

// Read the comments in list.h 
// to understand what you need to implement
// for each function

void freePaths(PathLL * p) {
	// Remove all paths in linked list, deallocate Path LL structure	
	while(helpFree(&(p -> head))){}
	free(p);
}

bool helpFree(PathNode ** p){
	if(*p == NULL){return false;}
	
	PathNode * check = *p;
	*p = check -> next;
	freeNode(check);
	return true;
}

PathNode * buildNode(char * path) {
	//Allocate a new PathNode with path as its data, return the address
	
	//WARNING: don't forget to use strcpy to copy path into the
	//new node. Don't just set them equal, otherwise if the input path changes
	//the node will have the wrong path.
	//builds a node containging the path

	// Allocate Size For Node
	PathNode * node = malloc(sizeof(PathNode));
	int allocateLength = strlen(path) + 1; // Length to allocate Value
	node -> path = malloc((allocateLength) * sizeof(char));
	
	// Copy Path To Node
	strcpy((node -> path), path);
	node -> next = NULL;  // Invalid write size of 8
	return node;
}

void freeNode(PathNode * p) {
	//Deallocate a pathNode
	free(p -> path);
	p -> next = NULL;
	free(p);
}

bool addNode(PathLL * paths, char * path) {
/*Add a path to the list of paths
  PathLL should be sorted by the following priority
  1. In ascending order of length (shortest path first), then
  2. By number of turns (see README), then
  3. Alphabetical order
 
  return true if the node is added successfully 
*/
	PathNode** p = findNextNode(&(paths -> head), path);
	if((*p != NULL) && (!strcmp((*p) -> path, path))){
		return false;
	}

	addAnotherNode(p, path);
	return true;
}

bool removeNode(PathLL * paths, char * path) {
	
	/*Remove a node from the list with the specified path
  return true if the node exists and is removed, false otherwise
*/
	PathNode ** p = findDeleteNode(&(paths -> head),path);
	return helpFree(p);

}

bool containsNode(PathLL * paths, char * path) {
	/* Return true if path exists in the list */

	return (*findDeleteNode(&(paths -> head),path)) != NULL;
}

void printPaths(PathLL * paths, FILE * fptr) {
	PathNode * curr = paths->head;
	int i = 0;
	while (curr != NULL) {
		fprintf(fptr, "Path %2d: %s\n", i, curr->path);
		i++;
		curr = curr->next;
	}
}

int compareLength(char * path1, char * path2){
	
	// Test Path Lengths
	int pathDiff = strlen(path1) - strlen(path2);
	int turnDiff = numTurns(path1) - numTurns(path2);

	return (pathDiff != 0) ? pathDiff :
	((turnDiff != 0) ? turnDiff : strcmp(path1, path2));
}

int numTurns(char * path){
	int countTurn = 0;
	int i = 0;
	char variable = path[0];

	while(path[i] != '\0'){ // Count turns from start to end
		if(variable != path[i]){++countTurn;} // If there is a turn, increase the turn count
	variable = path[i];
	++i;
	}
	return countTurn;
}

PathNode ** findNextNode(PathNode** p, char *path){
	while((*p != NULL) && ((compareLength((*p) -> path, path)) < 0)){
		p = &((*p) -> next);
	}
	return p;
}

void addAnotherNode(PathNode** p, char *path){
	PathNode *add = buildNode(path);
	add -> next = *p;
	*p = add;
}

PathNode ** findDeleteNode(PathNode** p, char *path){
	while((*p != NULL) && (!(strcmp((*p) -> path, path) == 0))){
		p = &((*p) -> next);
	}
	return p;
}