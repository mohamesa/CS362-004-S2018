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

int main() {
	srand((unsigned)time(NULL));
	struct gameState G, state;
	int numPlayers = 0;
	int thisPlayer = 0;
	int handpos = 0;
	int choice1 = 0, choice2 = 0, choice3 = 0;  // smithy_card do not use this, but must be added in the function cardEffect
	int bouns = 0;
	int shuffledCards = 0;
	int seed = 0;
	int n;
	int cardCount, cardCount1, cardCount2 = 0;

	int k[10] = { smithy ,adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute};

	printf("----Random test for Smithy_card----");

	for (n = 0; n < 2000; n++) {
		numPlayers = (rand() % 3) + 2; // pick players from 2, 3, or 4
		seed = rand(); // random seed
		thisPlayer = rand() % (numPlayers + 1);
		// initialize  the game state
		initializeGame(thisPlayer, k, seed, &G);

		state.deckCount[thisPlayer] = rand() % MAX_DECK;
		state.discardCount[thisPlayer] = rand() % MAX_DECK;
		state.handCount[thisPlayer] = rand() % MAX_HAND;
		state.hand[thisPlayer][0] = smithy;
		state.numPlayers = thisPlayer;
		state.whoseTurn = thisPlayer;
		state.numActions = rand() % 10;

		// copy the game state
		memcpy(&G, &state, sizeof(struct gameState));

		cardEffect(smithy, choice1, choice2, choice3, &state, handpos, &bouns);

		printf("\n Player receives 3 card\n");
		printf("hand count = %d, expected = %d\n", state.handCount[thisPlayer], G.handCount[thisPlayer] + 3 - 1);
		cardCount += assertTrue(state.handCount[thisPlayer] == G.handCount[thisPlayer] + 3 - 1);
		
		printf("\n Player gains 1 card from the discarded piles\n");
		printf("deck count = %d, expected = %d\n", state.deckCount[thisPlayer], G.deckCount[thisPlayer] - 1 + shuffledCards);
		cardCount1 +=assertTrue(state.deckCount[thisPlayer] == G.deckCount[thisPlayer] - 3 + shuffledCards);

		printf("\n Player number of Action  card\n");
		printf("numAction= %d, expected = %d\n", state.numActions, (G.numActions));
		cardCount2 +=assertTrue(state.numActions == (G.numActions));
		
		printf("Total passed test of Smithy card: %d.\n", passed);
		printf("Total failed of Smithy card: %d \n", failed);
	}
	return 0;
}