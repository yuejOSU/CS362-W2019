#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define UNIT_TEST "BuyCard"

int main() {

   printf("\nStarting Unit test 3: %s\n", UNIT_TEST);

   int flag = 0, assertion;
   int players = 2, seed = 1;
   struct gameState G;
   int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

   initializeGame(players, k, seed, &G);

   // assert when there are no buys
   G.numBuys = 0;
   assertion = buyCard(feast, &G);

   if (assertion == -1) {
      printf("Assert passed, denies a buy when there are no buys.\n");
   }
   else {
      printf("Assert failed, accepts a buy when there are no buys.\n");
      flag = -1;
   }

   // assert when there are buys but not enough coins
   G.numBuys = 7;
   G.coins = 0;
   assertion = buyCard(feast, &G);

   if (assertion == -1) {
      printf("Assert passed, denies a buy when there are not enough coins.\n");
   }
   else {
      printf("Assert failed, accepts a buy when there are not enough coins.\n");
      flag = -1;
   }

   // assert when there are buys and enough coins
   G.numBuys = 5;
   G.coins = 50;
   assertion = buyCard(feast, &G);

   if (assertion == 0) {
      printf("Assert passed, accepts a buy when there are enough coins.\n");
   }
   else {
      printf("Assert failed, does not accept a buy when there are enough coins.\n");
      flag = -1;
   }

   if (flag == 0) {
      printf("Unit test 3 passed.\n");
   }
   else {
      printf("Unit test 3 failed.\n");
   }

   return 0;

}
