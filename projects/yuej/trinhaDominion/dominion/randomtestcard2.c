#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define RANDOM_TEST "village"
#define ITERATIONS 10000

int main() {

   printf("\nStarting Random Test 3: %s\n", RANDOM_TEST);

   struct gameState G;
   int k[10] = {minion, smithy, gardens, tribute, baron, adventurer, cutpurse, mine, embargo, outpost};
   int i, player = 0, cardEffect_fail = 0, compareCount_fail = 0, actionCount_fail = 0, deckCount_fail = 0;
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
      int result = cardEffect(village, 0, 0, 0, &testG, 0, 0);

      testG.hand[player][testG.handCount[player]] = village;
      testG.handCount[player]++;

      // check if cardEffect() failed
      if(result == -1) {
         cardEffect_fail++;
      }

      // check if +1 card in testG vs G
      if(G.handCount[player] + 1 == testG.handCount[player]) {
         ; // do nothing
      }
      else {
         compareCount_fail++;
      }

      // check if +2 action in testG vs G
      if(G.numActions + 2 == testG.numActions) {
         ; // do nothing
      }
      else {
         actionCount_fail++;
      }

      // check if testG.deckCount is less than G.deckCount
      if(testG.deckCount[player] < G.deckCount[player]) {
         ; // do nothing
      }
      else {
         deckCount_fail++;
      }
   }

   // print results
   if(cardEffect_fail == 0 && compareCount_fail == 0 && actionCount_fail == 0 && deckCount_fail == 0) {
      printf("All tests passed!\n");
   }
   else {
      printf("Some test(s) have failed!\n");
   }
   printf("CardEffect() failed %d times out of %d iterations.\n", cardEffect_fail, ITERATIONS);
   printf("testG.handCount +1 card vs G.handCount failed %d times out of %d iterations.\n", compareCount_fail, ITERATIONS);
   printf("testG +2 numActions vs G numActions failed %d times out of %d iterations.\n", actionCount_fail, ITERATIONS);
   printf("testG.deckCount less than G.deckCount failed %d times out of %d iterations.\n", deckCount_fail, ITERATIONS);

   return 0;

}
