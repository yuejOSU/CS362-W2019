#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define UNIT_TEST "supplyCount"

int main() {

   printf("\nStarting Unit Test 4: %s\n", UNIT_TEST);

   int flag = 0, assertion;
   int players = 2, seed = 1;
   struct gameState G;
   int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

   initializeGame(players, k, seed, &G);

   // assert that function returns correct supply count
   G.supplyCount[gold] = 5;
   assertion = supplyCount(gold, &G);

   if (assertion == 5) {
      printf("Assert passed, function returns correct supply count.\n");
   }
   else {
      printf("Assert failed, function does not return correct supply count.\n");
      flag = -1;
   }

   G.supplyCount[silver] = 0;
   assertion = supplyCount(silver, &G);

   if (assertion == 0) {
      printf("Assert passed, function returns correct supply count.\n");
   }
   else {
      printf("Assert failed, function does not return correct supply count.\n");
      flag = -1;
   }

   if (flag == 0) {
      printf("Unit test 4 passed.\n");
   }
   else {
      printf("Unit test 4 failed.\n");
   }

   return 0;

}
