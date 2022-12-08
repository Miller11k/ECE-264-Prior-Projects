// ***
// *** You MUST modify this file
// ***

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// do NOT modify this function
static void printDeck(CardDeck deck)
{
  int ind;
  for (ind = 0; ind < deck.size; ind ++)
    {
      printf("%c ", deck.cards[ind]);
    }
  printf("\n");
}

#ifdef TEST_DIVIDE
// leftDeck and rightDeck are arrays of CardDeck
// This function creates pairs of left and right decks
// Each pair divides the original deck into two non-overlapping decks and
// together they form the original deck.
//
// You can think of the left deck held by the left hand taking some
// cards (at least one) from the top of the original deck.
//
// The right deck is held by the right hand taking some (at least one)
// cards from the bottom of the original deck.
void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
  int numCards;
  int numLeftCard;
  int numRightCard;
  int i;

  numCards = origDeck.size; // Find Number of Cards
  
  for(i = 0; i < numCards - 1; i++){
    numLeftCard = i + 1;
    numRightCard = numCards - numLeftCard;
    memcpy(leftDeck[i].cards,origDeck.cards,numLeftCard * sizeof(origDeck.cards[0]));
    memcpy(rightDeck[i].cards,&origDeck.cards[numLeftCard],numRightCard * sizeof(origDeck.cards[0]));
    leftDeck[i].size = numLeftCard;
    rightDeck[i].size = numRightCard;
  }

  return;
}
#endif

#ifdef TEST_INTERLEAVE

// Interleave two decks to generate all possible results.
//
// If the leftDeck is {'A'} and the right deck is {'2', '3'}, this
// function prints
// A 2 3
// 2 A 3
// 2 3 A
//
// If the leftDeck is {'A', '2'} and the right deck is {'3', '4'}, this
// function prints 
// 3 4 A 2
// 3 A 4 2
// A 3 4 2 
// 3 A 2 4 
// A 3 2 4 
// A 2 3 4 
//
// Please notice the space does not matter because grading will use
// diff -w
//
// How to generate all possible interleaves?

// Understand that a card at a particular position can come from
// either left or right (two options). The following uses left for
// explanation but it is equally applicable to the right.
//
// After taking one card from the left deck, the left deck has one
// fewer card. Now, the problem is the same as the earlier problem
// (thus, this problem can be solved by using recursion), excecpt one
// left card has been taken. Again, the next card can come from left
// or right.
//
// This process continues until either the left deck or the right deck
// runs out of cards. The remaining cards are added to the result.
// 
// It is very likely that you want to create a "helper" function that
// can keep track of some more arguments.  If you create a helper
// function, please keep it inside #ifdef TEST_INTERLEAVE and #endif
// so that the function can be removed for grading other parts of the
// program.
void interleave(CardDeck leftDeck, CardDeck rightDeck)
{
  int var1 = leftDeck.size - 1;
  int var2 = rightDeck.size - 1;
  CardDeck combinedDeck;
  combinedDeck.size = leftDeck.size + rightDeck.size;

  helper(var1, var2, (var1 + var2) + 1, leftDeck, rightDeck, combinedDeck);
  return;
}

void helper(int leftDeckIndex, int rightDeckIndex, int combinedIndex, CardDeck leftDeck, CardDeck rightDeck, CardDeck combinedDeck)
{
  if((leftDeckIndex == -1)){
    
    for(int i = 0; i <= rightDeckIndex; i++){
      combinedDeck.cards[i] = rightDeck.cards[i];
    }
    printDeck(combinedDeck);
    return;
  }
  if((rightDeckIndex == -1)){
    
    for(int i = 0; i <= leftDeckIndex; i++){
      combinedDeck.cards[i] = leftDeck.cards[i];
    }
    printDeck(combinedDeck);
    return;
  }
  combinedDeck.cards[combinedIndex] = leftDeck.cards[leftDeckIndex];
  helper(leftDeckIndex - 1, rightDeckIndex, combinedIndex - 1, leftDeck, rightDeck, combinedDeck);
  
  combinedDeck.cards[combinedIndex] = rightDeck.cards[rightDeckIndex];
  helper(leftDeckIndex, rightDeckIndex - 1, combinedIndex - 1, leftDeck, rightDeck, combinedDeck);
}
#endif

#ifdef TEST_SHUFFLE
// The shuffle function has the following steps:

// 1. calculate the number of possible left and right decks. It is
// the number of cards - 1 because the left deck may have 1, 2,...,
// #cards - 1 cards.
//
// 2. allocate memory to store these possible pairs of left and right
// decks.
//
// 3. send each pair to the interleave function
//
// 4. release allocated memory
//
void shuffle(CardDeck origDeck)
{
  int numPossibilities = origDeck.size - 1;
  CardDeck *weave_left;
  CardDeck *weave_right;
  weave_left = malloc(numPossibilities * sizeof(CardDeck));
  if (weave_left == NULL)
  {
    free (weave_left);
    return;
  }

  weave_right = malloc(numPossibilities * sizeof(CardDeck));
  if (weave_right == NULL)
  {
    free (weave_right);
    free (weave_left);
    return;
  }

  divide(origDeck, weave_left, weave_right);
  for(int i = 0; i < numPossibilities; i++)
  {
    interleave(weave_left[i], weave_right[i]);
  }

  free (weave_left);
  free (weave_right);
  return;

}
#endif
