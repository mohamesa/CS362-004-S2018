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
	int choice1 = 0, choice2 = 0, choice3 = 0;  // great_hall do not use this, but must be added in the function cardEffect
	int bouns = 0;
	int newCards = 0;
	int xtraCoins = 0;
	int discarded = 1;
	int numActions = 0;
	int shuffledCards = 0;

	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	// initialize  the game state
	initializeGame(numPlayers, k, seed, &G);

	printf("----Testing great_hall_card----");

	// copy the game state 
	memcpy(&testG, &G, sizeof(struct gameState));

	cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bouns);

	newCards = 1;
	xtraCoins = 0;
	numActions = 1;
	
	printf("\n Player0 receives 1 card\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);

	printf("\n Deck has less Cards\n");
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);

	printf("\n Number of card discarded\n");
	printf("coins = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount +discarded);
	assertTrue(testG.playedCardCount, G.playedCardCount+ discarded);
	 
	printf("\n Coin count\n");
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	assertTrue(testG.coins, G.coins + xtraCoins);

	printf("\n Player0 number of Action  card\n");
	printf("numAction= %d, expected = %d\n", testG.numActions, G.numActions + numActions);
	assertTrue(testG.numActions, G.numActions + numActions);

	printf("\n Number of buys\n");
	printf("numBuys = %d, expected = %d\n", testG.numBuys, G.numBuys);
	assertTrue(testG.numBuys, G.numBuys);

	printf("\n change of estate piles\n");
	printf("suplyCountt = %d, expected = %d\n", testG.supplyCount[estate], G.supplyCount[estate]);
	assertTrue(testG.supplyCount[estate], G.supplyCount[estate]);

	printf("\n change of Duchy piles\n");
	printf("suplyCountt = %d, expected = %d\n", testG.supplyCount[duchy], G.supplyCount[duchy]);
	assertTrue(testG.supplyCount[duchy], G.supplyCount[duchy]);

	printf("\n change of Province piles\n");
	printf("suplyCountt = %d, expected = %d\n", testG.supplyCount[province], G.supplyCount[province]);
	assertTrue(testG.supplyCount[province], G.supplyCount[province]);

	if (!failed) {
		printf("\n Test Successfully Completed\n");
	}
	else {
		printf("\n Test Failed\n");
	}
	printf("\n");
	return 0;
}
