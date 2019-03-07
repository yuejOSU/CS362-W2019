#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define CARD_TEST "village"

int main() {

   printf("\nStarting Card Test 3: %s\n", CARD_TEST);

   int flag = 0;
   int players = 2, player = 0, seed = 1000;
   struct gameState testG, G;
   int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

   initializeGame(players, k, seed, &G);

   memcpy(&testG, &G, sizeof(struct gameState));

   // assert Village card is drawn to hand
   testG.hand[player][testG.handCount[player]] = village;
   testG.handCount[player]++;
   if (G.handCount[player] + 1 == testG.handCount[player]) {
      printf("Assert passed, Village card drawn to player's hand.\n");
   }
   else {
      printf("Assert failed, Village card not drawn to player's hand.\n");
      flag = -1;
   }

   // assert 1 cards drawn from deck and Village card discarded
   cardEffect(village, 0, 0, 0, &testG, testG.hand[player][testG.handCount[player] - 1], 0);
   if (G.handCount[player] + 1 == testG.handCount[player]) {
      printf("Assert passed, 1 new card drawn and Village card discarded.\n");
   }
   else {
      printf("Assert failed, did not draw and/or discarded Village card.\n");
      flag = -1;
   }

   // assert if +2 action
   if (G.numActions + 2 == testG.numActions) {
      printf("Assert passed, +2 action.\n");
   }
   else {
      printf("Assert failed, did not +2 action, %d and %d.\n", G.numActions + 2, testG.numActions);
      flag = -1;
   }

   if (flag == 0) {
      printf("Card test 3 passed.\n");
   }
   else {
      printf("Card test 3 failed.\n");
   }

   return 0;

}
