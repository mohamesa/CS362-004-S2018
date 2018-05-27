#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int passed = 0;
int failed = 0;
int assertTrue(int status) {
	if (status) {
		printf("->Test Passed\n");
		passed++;
		return SUCCESS;
	}
	else {
		printf("->Test did not Pass\n");
		failed++;
		return FAILURE;
	}
}

// counts treasure 
int countDeckTreasure(struct gameState *state) {
	int cardIndex = 0;

	int i;
	for (i = 0; i < state->deckCount[state->whoseTurn]; i++) {
		if (state->deck[state->whoseTurn][i] == copper
			|| state->deck[state->whoseTurn][i] == silver
			|| state->deck[state->whoseTurn][i] == gold)
		{
			cardIndex++;
		}
	}

	return cardIndex;
}

int numberofCardsToDraw(int before)
{
	if (before > 2)
	{
		return 2;
	}
	else
	{
		return before;
	}
}


int main() {
	srand((unsigned)time(NULL));
	int n;
	for (n = 0; n < 2000; n++) {
		struct gameState G;

		int numPlayers = rand() % 3 + 2; // 2-4 palyers
		int thisPlayer = numPlayers;
		int seed = rand(); //random seed
		int choice1 = 0, choice2 = 0, choice3 = 0;
		int handPos = 0;
		int bonus = 0;
		int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy };

		// initialize  the game state
		initializeGame(thisPlayer, k, seed, &G);

		G.handCount[thisPlayer] = rand()* MAX_HAND;
		int handCountbefore = numHandCards(&G);
		int deckTreasureBefore = countDeckTreasure(&G);

		printf("Random test For Adventurer_card.\n");

		cardEffect(adventurer, choice1, choice2, choice3, &G, handPos, &bonus);

		int handCountAfter = numHandCards(&G);

		printf("hand count = %d, expected = %d\n", (handCountAfter - handCountbefore), numberofCardsToDraw(deckTreasureBefore));
		assertTrue((handCountAfter - handCountbefore) == numberofCardsToDraw(deckTreasureBefore));

	}
	printf("Total passed test of Adevnturer card: %d.\n", passed);
	printf("Total failed of Adevnturer card: %d \n", failed);

	return 0;
}