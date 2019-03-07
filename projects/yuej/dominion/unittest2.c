#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define UNIT_TEST "fullDeckCount"

int main() {

   printf("\nStarting Unit Test 2: %s\n", UNIT_TEST);

   int flag = 0;
   int players = 2, seed = 1;
   struct gameState G;
   int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

   initializeGame(players, k, seed, &G);

   int testHand1[0];
   int testDeck1[0];
   int testDiscard1[0];
   int result;

   memcpy(G.hand[0], testHand1, 0);
   memcpy(G.deck[0], testDeck1, 0);
   memcpy(G.discard[0], testDiscard1, 0);
   G.handCount[0] = 0;
   G.deckCount[0] = 0;
   G.discardCount[0] = 0;

   // assert condition when deck is empty
   result = fullDeckCount(0, copper, &G);
   if (result == 0) {
      printf("Assert passed, expected deck count of 0 matches actual result.\n");
   }
   else {
      printf("Assert failed, expected deck count of 0 does not match actual result.\n");
      flag = -1;
   }

   int testHand2[5];
   testHand2[0] = copper;
   testHand2[1] = copper;
   testHand2[2] = copper;
   testHand2[3] = copper;
   testHand2[4] = copper;
   memcpy(G.hand[0], testHand2, 5 * sizeof(int));
   G.handCount[0] = 5;

   int testDeck2[5];
   testDeck2[0] = copper;
   testDeck2[1] = copper;
   testDeck2[2] = copper;
   testDeck2[3] = copper;
   testDeck2[4] = copper;
   memcpy(G.deck[0], testDeck2, 5 * sizeof(int));
   G.deckCount[0] = 5;

   int testDiscard2[2];
   testDiscard2[0] = copper;
   testDiscard2[1] = copper;
   memcpy(G.discard[0], testDiscard2, 2 * sizeof(int));
   G.discardCount[0] = 2;

   // assert for gold cards, expecting 0
   result = fullDeckCount(0, gold, &G);
   if (result == 0) {
      printf("Assert passed, expected deck count of 0 matches actual result.\n");
   }
   else {
      printf("Assert failed, expected deck count of 0 does not match actual result.\n");
      flag = -1;
   }

   // assert for copper cards, expecting 12
   result = fullDeckCount(0, copper, &G);
   if (result == 12) {
      printf("Assert passed, expected deck count of 15 matches actual result.\n");
   }
   else {
      printf("Assert failed, expected deck count of 12 does not match actual result.\n");
      flag = -1;
   }

   if (flag == 0) {
      printf("Unit test 2 passed.\n");
   }
   else {
      printf("Unit test 2 failed.\n");
   }

   return 0;

}
