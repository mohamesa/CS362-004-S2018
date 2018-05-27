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

	printf("----Testing getCost----");

	printf("\n 5 crads in hand at the start of the game\n");

	printf("getcost = %d, expected = %d\n", getCost(mine), 5);
	assertTrue(getCost(mine), 5);

	printf("getcost = %d, expected = %d\n", getCost(adventurer), 6);
	assertTrue(getCost(adventurer), 6);

	printf("getcost = %d, expected = %d\n", getCost(smithy), 4);
	assertTrue(getCost(smithy), 4);

	printf("getcost = %d, expected = %d\n", getCost(village), 3);
	assertTrue(getCost(village), 3);

	printf("getcost = %d, expected = %d\n", getCost(great_hall), 3);
	assertTrue(getCost(great_hall), 3);

	printf("getcost = %d, expected = %d\n", getCost(minion), 5);
	assertTrue(getCost(minion), 5);

	printf("getcost = %d, expected = %d\n", getCost(feast), 4);
	assertTrue(getCost(feast), 4);

	printf("getcost = %d, expected = %d\n", getCost(gardens), 4);
	assertTrue(getCost(gardens), 4);

	printf("getcost = %d, expected = %d\n", getCost(silver), 3);
	assertTrue(getCost(silver), 3);

	printf("getcost = %d, expected = %d\n", getCost(feast), 4);
	assertTrue(getCost(feast), 4);

	printf("getcost = %d, expected = %d\n", getCost(council_room), 5);
	assertTrue(getCost(council_room), 5);

	printf("getcost = %d, expected = %d\n", getCost(steward), 3);
	assertTrue(getCost(steward), 3);

	printf("getcost = %d, expected = %d\n", getCost(sea_hag), 4);
	assertTrue(getCost(sea_hag), 4);
	
	printf("getcost = %d, expected = %d\n", getCost(salvager), 4);
	assertTrue(getCost(salvager), 4);

	printf("getcost = %d, expected = %d\n", getCost(curse), 0);
	assertTrue(getCost(curse), 0);

	printf("getcost = %d, expected = %d\n", getCost(estate), 2);
	assertTrue(getCost(estate), 2);

	printf("getcost = %d, expected = %d\n", getCost(duchy), 5);
	assertTrue(getCost(duchy), 5);

	printf("getcost = %d, expected = %d\n", getCost(province), 8);
	assertTrue(getCost(province), 8);

	printf("getcost = %d, expected = %d\n", getCost(copper), 0);
	assertTrue(getCost(copper), 0);

	printf("getcost = %d, expected = %d\n", getCost(gold), 6);
	assertTrue(getCost(gold), 6);

	printf("getcost = %d, expected = %d\n", getCost(remodel), 4);
	assertTrue(getCost(remodel), 4);

	printf("getcost = %d, expected = %d\n", getCost(baron), 4);
	assertTrue(getCost(baron), 4);

	printf("getcost = %d, expected = %d\n", getCost(ambassador),3);
	assertTrue(getCost(ambassador), 3);

	printf("getcost = %d, expected = %d\n", getCost(tribute), 5);
	assertTrue(getCost(tribute), 5);

	printf("getcost = %d, expected = %d\n", getCost(embargo), 2);
	assertTrue(getCost(embargo), 2);

	printf("getcost = %d, expected = %d\n", getCost(cutpurse), 4);
	assertTrue(getCost(cutpurse), 4);

	printf("getcost = %d, expected = %d\n", getCost(treasure_map), 4);
	assertTrue(getCost(treasure_map), 4);

	printf("getcost = %d, expected = %d\n", getCost(outpost), 5);
	assertTrue(getCost(outpost), 5);
 

if (!failed) {
		printf("\n Test Successfully Completed\n");
	}
	else {
		printf("\n Test Failed\n");
	}
	printf("\n");

	return 0;
}