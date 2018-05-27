#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "testHelper.h"
   
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
	struct gameState testG, G;
	int numPlayers = 2;
	int supplyPilesNum = 25;

	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	// initialize  the game state
	initializeGame(numPlayers, k, seed, &G);

	int i;
	for (i = 0; i < supplyPilesNum; i++)
		G.supplyCount[i] = 1;
		isGameOver(&G);

	printf("----Testing isGameOver----");
	
	// copy the game state 
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("\n Game not over \n");
	printf(" supply count = %d, expected = %d\n", isGameOver(&G), 0);
	assertTrue(isGameOver(&G),  0);
	
	printf("\n Game is Over \n");
	G.supplyCount[province] = 0;
	printf(" supply count = %d, expected = %d\n", isGameOver(&G), 1);
	assertTrue(isGameOver(&G), 1);

	printf("\n Game is Over \n");
	G.supplyCount[province] = 1;
	G.supplyCount[gold] = 0;
	G.supplyCount[mine] = 0;
	G.supplyCount[village] = 0;
	printf(" supply count = %d, expected = %d\n", isGameOver(&G), 1);
	assertTrue(isGameOver(&G), 1);
	
	printf("\n Game is Over \n");
	G.supplyCount[province] = 1;
	G.supplyCount[smithy] = 0;
	G.supplyCount[treasure_map] = 0;
	G.supplyCount[great_hall] = 0;
	printf(" supply count = %d, expected = %d\n", isGameOver(&G), 1);
	assertTrue(isGameOver(&G), 1);

if (!failed) {
		printf("\n Test Successfully Completed\n");
	}
	else {
		printf("\n Test Failed\n");
	}
	printf("\n");

	return 0;
}
