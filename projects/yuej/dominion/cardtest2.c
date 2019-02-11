#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define CARD_TEST "smithy"

int main() {

   printf("\nStarting Card Test 2: %s\n", CARD_TEST);

   int flag = 0;

   // initialize gameState
   int players = 2, seed = 1000, player = 0;
   struct gameState testG, G;
   int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

   initializeGame(players, k, seed, &G);

   memcpy(&testG, &G, sizeof(struct gameState));

   // assert Smithy card is drawn to hand
   testG.hand[player][testG.handCount[player]] = smithy;
   testG.handCount[player]++;
   if (G.handCount[player] + 1 == testG.handCount[player]) {
      printf("Assert passed, Smithy card drawn to player's hand.\n");
   }
   else {
      printf("Assert failed, Smithy card not drawn to player's hand.\n");
      flag = -1;
   }

   // assert 3 cards drawn from deck and Smithy card discarded
   cardEffect(smithy, 0, 0, 0, &testG, testG.hand[player][testG.handCount[player] - 1], 0);
   if (G.handCount[player] + 3 == testG.handCount[player]) {
      printf("Assert passed, 3 new cards drawn and Smithy card discarded.\n");
   }
   else {
      printf("Assert failed, did not draw and/or discarded Smithy card.\n");
      flag = -1;
   }

   // assert that no victory cards have been pulled from supply count
   if (G.supplyCount[estate] == testG.supplyCount[estate]) {
      printf("Assert passed, count of Estate victory card has not changed.\n");
   }
   else {
      printf("Assert failed, count of Estate victory card has been changed.\n");
      flag = -1;
   }

   if (G.supplyCount[province] == testG.supplyCount[province]) {
      printf("Assert passed, count of Province victory card has not changed.\n");
   }
   else {
      printf("Assert failed, count of Province victory card has been changed.\n");
      flag = -1;
   }

   if (G.supplyCount[duchy] == testG.supplyCount[duchy]) {
      printf("Assert passed, count of Duchy victory card has not changed.\n");
   }
   else {
      printf("Assert failed, count of Duchy victory card has been changed.\n");
      flag = -1;
   }

   if (flag == 0) {
      printf("Card test 2 passed.\n");
   }
   else {
      printf("Card test 2 failed.\n");
   }

   return 0;

}
