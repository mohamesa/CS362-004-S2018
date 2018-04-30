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
	int choice1 = 0, choice2 = 0, choice3 = 0;  // adventurer do not use this, but must be added in the function cardEffect
	int bouns = 0;
	int newCards = 0;
	int shuffledCards = 0;
	int treasureCount2 = 0;
	int treasureCount1 = 0;

	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	// initialize  the game state
	initializeGame(numPlayers, k, seed, &G);

	printf("----Testing adventurer_card----");

	// copy the game state 
	memcpy(&testG, &G, sizeof(struct gameState));

	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bouns);

	newCards = 2;
	int xtraCoins = 0;
	

	printf("\n Player0 receives 2 cards\n");
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards );
	assertTrue(testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards);

	printf("\n Player0 gains 2 cards from the discarded piles\n");
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	assertTrue(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);

	printf("\n Player0 got playedCardCount\n");
	printf("coins = %d, expected = %d\n", testG.playedCardCount, G.playedCardCount);
	assertTrue(testG.playedCardCount, G.playedCardCount);

	printf("\n Player0 Coin count\n");
	printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	assertTrue(testG.coins, G.coins + xtraCoins);


	printf("\n Player0 number of Action  card\n");
	printf("numAction = %d, expected = %d\n", testG.numActions, G.numActions);
	assertTrue(testG.numActions, G.numActions);

	// check treasure count after
	
	int cardIndex = 0;
	while (cardIndex < G.handCount[thisPlayer])
	{
		int card = G.hand[thisPlayer][cardIndex];
		if (card == copper || card == silver || card == gold) {
			treasureCount2++;
		}
		cardIndex++;
	};

	// check treasure count before 
	int cardIndex1 = 0;
	while (cardIndex1 < testG.handCount[thisPlayer])
	{
		int card = testG.hand[thisPlayer][cardIndex];
		if (card == copper || card == silver || card == gold) {
			treasureCount1++;
		}
		cardIndex1++;
	};

	
	printf("\nPlayer0 gains 2 treasure cards\n");
	assertTrue(treasureCount1 + 2, treasureCount2);

	if (!failed) {
		printf("\n Test Successfully Completed\n");
	}
	else {
		printf("\n Test Failed\n");
	}
	printf("\n");
	return 0;
}
