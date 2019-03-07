#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define RANDOM_TEST "smithy"
#define ITERATIONS 10000

int main() {

   printf("\nStarting Random Test 2: %s\n", RANDOM_TEST);

   struct gameState G;
   int k[10] = {minion, smithy, gardens, tribute, baron, adventurer, cutpurse, mine, embargo, outpost};
   int i, player = 0, num_passed = 0;
   srand(time(NULL));

   for(i = 0; i < ITERATIONS; i++) {
      struct gameState testG;

      // randomize pre-game info
      int rand_players = (rand() % (MAX_PLAYERS - 1) + 2);
      int rand_deckCount = (rand() % (MAX_DECK - 2) + 3);
      int rand_handCount = (rand() % (MAX_HAND - 4) + 5);
      int rand_seed = 1000;

      // initialize the game
      initializeGame(rand_players, k, rand_seed, &G);

      // randomize game info
      player = rand() % rand_players;
      G.whoseTurn = player;
      G.deckCount[player] = rand_deckCount;
      G.handCount[player] = rand_handCount;


      // copy game info to testG
      memcpy(&testG, &G, sizeof(struct gameState));

      // run cardEffect() w/ testG
      cardEffect(smithy, 0, 0, 0, &testG, 0, 0);

      // check to see if +2 cards in testG vs G
      if((G.handCount[player] + 2) == testG.handCount[player]) {
         // check to see if testG.deckCount is less than G.rand_deckCount
         if(testG.deckCount[player] < G.deckCount[player]) {
            // check to see if 0 victory cards are pulled from supply count
           if((G.supplyCount[estate] == testG.supplyCount[estate]) && (G.supplyCount[province] == testG.supplyCount[province]) && (G.supplyCount[duchy] == testG.supplyCount[duchy])) {
              num_passed++;
            }

         }
      }

   }

   if(num_passed == ITERATIONS) {
      printf("ALL TESTS PASSED OUT OF %d ITERATIONS.\n\n", ITERATIONS);
   }

   return 0;

}
