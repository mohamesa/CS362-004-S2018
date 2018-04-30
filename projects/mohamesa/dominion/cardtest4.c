#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int failed = 0;

void assertTrue(int a, int b) {

	if (a == b) {
		printf("->Test Passed\n");
	}
	else {
		printf("->Test did not Pass\n");
		failed++;
	}
}


int main() {
	int seed = 100;
	struct gameState G, testG; 

	int numPlayers = 2;

	int thisPlayer = 0;

	int handpos = 0;
	int choice1 = 0, choice2 = 0, choice3 = 0;  // village_card do not use this, but must be added in the function cardEffect

	int bouns = 0;
	int newCards = 0;
	int numActions = 0;
	int discarded = 1;
	int shuffledCards = 0;

	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	// initialize  the game state
	initializeGame(numPlayers, k, seed, &G);

	printf("----Testing village_card----");

	// copy the game state 
	memcpy(&testG, &G, sizeof(struct gameState));

	cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bouns);

	newCards = 1;
	numActions = 2;

	printf("\n Player0 receives 1 card\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);

	printf("\n Player0 gains 1 card from the discarded piles\n");
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);

	printf("\n Player0 got playedCardCount\n");
	printf("coins = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount);
	assertTrue(testG.playedCardCount, G.playedCardCount);

	printf("\n Player0 gain 2 Action cards\n");
	printf("numAction = %d, expected = %d\n", testG.numActions, G.numActions + numActions);
	assertTrue(testG.numActions, G.numActions + numActions);


	if (!failed) {
		printf("\n Test Successfully Completed\n");
	}
	else {
		printf("\n Test Failed\n");
	}
	printf("\n");
	return 0;
}
