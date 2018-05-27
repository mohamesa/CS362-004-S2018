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
	failed ++;
	}
}

int main() {
	int seed = 100;
	struct gameState  G;
	int numPlayers = 2;
	int thisPlayer = 0;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };

	// initialize  the game state
	initializeGame(numPlayers, k, seed, &G);
	
	printf("----Testing updateCoins----\n");

	printf("\n Adding +1 copper in the treasuer card \n");
	int copperrOne = G.coins;
	gainCard(copper, &G, 2, thisPlayer);
	updateCoins(thisPlayer, &G, 0);

	printf("\n hand count = %d, expected = %d\n", G.coins, copperrOne + 1);
	assertTrue(G.coins, copperrOne + 1);
	
	printf("\n Adding +2 sliver in the treasuer card \n");
	int sliverTwo = G.coins;
	gainCard(silver, &G, 2, thisPlayer);
	updateCoins(thisPlayer, &G, 0);

	printf("hand count = %d, expected = %d\n", G.coins, sliverTwo + 2);
	assertTrue(G.coins, sliverTwo + 2);


	printf("\n Adding +3 gold in the treasuer card \n");
	int goldThree = G.coins;
	gainCard(gold, &G, 2, thisPlayer);
	updateCoins(thisPlayer, &G, 0);

	printf("hand count = %d, expected = %d\n", G.coins , goldThree + 3);
	assertTrue(G.coins , goldThree + 3);
	
	printf("\n Adding +1 copper and + 4 bonus in the treasuer card \n");
	int beforeBonus = G.coins;
	int bonus = 4;
	gainCard(copper, &G, 2, thisPlayer);
	updateCoins(thisPlayer, &G, bonus);

	printf("hand count = %d, expected = %d\n", G.coins, beforeBonus + 1 + bonus);
	assertTrue(G.coins, beforeBonus + 1 +bonus);

	initializeGame(numPlayers, k, seed, &G);

	printf("\n Adding +3 gold and + 4 bonus in the treasuer card \n");
	int pre_bonus = G.coins;
	int with_bouns = 4;
	gainCard(gold, &G, 2, thisPlayer);
	updateCoins(thisPlayer, &G, with_bouns);

	printf("hand count = %d, expected = %d\n", G.coins, pre_bonus + 3 + with_bouns);
	assertTrue(G.coins, pre_bonus + 3 + with_bouns);
	
	initializeGame(numPlayers, k, seed, &G);
	printf("\n Adding +2 s and + 4 bonus in the treasuer card \n");
	int preBonus = G.coins;
	int withBouns = 3;
	gainCard(silver, &G, 2, thisPlayer);
	updateCoins(thisPlayer, &G, withBouns);

	printf("hand count = %d, expected = %d\n", G.coins, preBonus + 2 + withBouns);
	assertTrue(G.coins, preBonus + 2 + withBouns);

	if (!failed) {
		printf("\n Test Successfully Completed\n"); 
	}
	else {
		printf("\n Test Failed\n");
	}
	printf("\n");
	return 0;
}
