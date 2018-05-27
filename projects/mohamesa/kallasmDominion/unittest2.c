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
	int toflag0 = 0;
	int toflag1 = 1;
	int toflag2 = 2;

	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	// initialize  the game state
	initializeGame(numPlayers, k, seed, &G);

	printf("----Testing gainCard----");

	// copy the game state 
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("\n Testing gainCard for gold\n");

	printf("\n Gold supply is empty\n"); 
	G.supplyCount[gold] = 0;
	assertTrue(gainCard(gold, &G, toflag0, thisPlayer), - 1);
	G.supplyCount[gold] = 30;

	printf("\n Card added to deck count\n");
	int deckCount = G.deckCount[0];
	gainCard(gold, &G, toflag1, thisPlayer);
	printf("Deck count = %d, expected = %d\n",  G.deckCount[0] ,deckCount + 1);
	assertTrue( G.deckCount[0] , deckCount + 1);
	
	printf("\n Card added to hand count\n");
	int handCount = G.handCount[0];
	gainCard(gold, &G, toflag2, thisPlayer);
	printf("hand count = %d, expected = %d\n",  G.handCount[0] ,handCount+ 1);
	assertTrue( G.handCount[0] , handCount + 1);

	printf("\n Card added to discard count \n");
	int discardCount = G.discardCount[0];
	gainCard(gold, &G, toflag0, thisPlayer);
	printf("hand count = %d, expected = %d\n", G.discardCount[0] , discardCount + 1);
	assertTrue( G.discardCount[0] , discardCount + 1);
	
	printf("\n Testing gainCard for silver\n");

	printf("\n Sliver supply is empty\n");
	G.supplyCount[silver] = 0;
	assertTrue(gainCard(silver, &G, toflag0, thisPlayer), -1);
	G.supplyCount[silver] = 40;

	printf("\n Card added to deck count\n");
	int deckCount1 = G.deckCount[0];
	gainCard(silver, &G, toflag1, thisPlayer);
	printf("Deck count = %d, expected = %d\n", G.deckCount[0], deckCount1 + 1);
	assertTrue(G.deckCount[0], deckCount1+ 1);

	printf("\n Card added to hand count\n");
	int handCount1 = G.handCount[0];
	gainCard(silver, &G, toflag2, thisPlayer);
	printf("hand count = %d, expected = %d\n",  G.handCount[0] , handCount1 + 1);
	assertTrue( G.handCount[0] , handCount1 + 1);

	printf("\n Card added to discard count \n");
	int discardCount1 = G.discardCount[0];
	gainCard(silver, &G, toflag0, thisPlayer);
	printf("hand count = %d, expected = %d\n", G.discardCount[0], discardCount1 + 1);
	assertTrue(G.discardCount[0], discardCount1 + 1);

	printf("\n Decrease supplycount of Silver \n");
	int silverSupplycount = G.supplyCount[silver];
	gainCard(silver, &G, toflag0, thisPlayer);
	printf("hand count = %d, expected = %d\n", G.supplyCount[silver], silverSupplycount - 1);
	assertTrue(G.supplyCount[silver], silverSupplycount - 1 );

	printf("\n Testing gainCard for copper\n");

	printf("\n Copper supply is empty\n"); 
	G.supplyCount[copper] = 0;
	assertTrue(gainCard(copper, &G, toflag0, thisPlayer), - 1);
	G.supplyCount[copper] = 46;

	printf("\n Card added to deck count\n");
	int deckCount2= G.deckCount[0];
	gainCard(copper, &G, toflag1, thisPlayer);
	printf("Deck count = %d, expected = %d\n",  G.deckCount[0] ,deckCount2+ 1);
	assertTrue( G.deckCount[0] , deckCount2 + 1);
	
	printf("\n Card added to hand count\n");
	int handCount2= G.handCount[0];
	gainCard(copper, &G, toflag2, thisPlayer);
	printf("hand count = %d, expected = %d\n",  G.handCount[0] , handCount2 + 1);
	assertTrue( G.handCount[0] , handCount2 + 1);

	printf("\n Card added to discard count \n");
	int discardCount2 = G.discardCount[0];
	gainCard(copper, &G, toflag0, thisPlayer);
	printf("hand count = %d, expected = %d\n", G.discardCount[0], discardCount2 + 1);
	assertTrue(G.discardCount[0], discardCount2 + 1);

	if (!failed) {
		printf("\n Test Successfully Completed\n");
	}
	else {
		printf("\n Test Failed\n");
	}
	printf("\n");
	return 0;
}




