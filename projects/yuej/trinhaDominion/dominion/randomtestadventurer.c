#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define RANDOM_TEST "adventurer"
#define ITERATIONS 10000

int main() {

   printf("\nStarting Random Test 1: %s\n", RANDOM_TEST);

   struct gameState G;
   int k[10] = {minion, smithy, gardens, tribute, baron, adventurer, cutpurse, mine, embargo, outpost};
   int i, player = 0, cardEffect_fail = 0, handCount_fail = 0, compareCount_fail = 0, deckCount_fail = 0;
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
      int result = cardEffect(adventurer, 1, 0, 0, &testG, 0, 0);

      // check if cardEffect() failed
      if(result == -1) {
         cardEffect_fail++;
      }

      // check last two cards if they are treasure cards
      int cardDrawn1, cardDrawn2;
      cardDrawn1 = testG.hand[player][testG.handCount[player] - 2];
      cardDrawn2 = testG.hand[player][testG.handCount[player] - 1];
      if((cardDrawn1 == copper || cardDrawn1 == silver || cardDrawn1 == gold) && (cardDrawn2 == copper || cardDrawn2 == silver || cardDrawn2 == gold)) {
         ; // do nothing
      }
      else {
         handCount_fail++;
      }

      // check to see if +2 cards in testG vs G
      if(G.handCount[player] + 2 == testG.handCount[player]) {
         ; // do nothing
      }
      else {
         compareCount_fail++;
      }

      // check to see if testG.deckCount is less than G.rand_deckCount
      if(testG.deckCount[player] < G.deckCount[player]) {
         ; // do nothing
      }
      else {
         deckCount_fail++;
      }
   }

   // print results
   if(cardEffect_fail == 0 && handCount_fail == 0 && compareCount_fail == 0) {
      printf("All tests passed!\n");
   }
   else {
      printf("Some test(s) have failed!\n");
   }
   printf("CardEffect() failed %d times out of %d iterations.\n", cardEffect_fail, ITERATIONS);
   printf("testG.handCount +2 treasure cards failed %d times out of %d iterations.\n", handCount_fail, ITERATIONS);
   printf("testG.handCount +2 cards vs G.handCount failed %d times out of %d iterations.\n", compareCount_fail, ITERATIONS);
   printf("testG.deckCount less than G.deckCount failed %d times out of %d iterations.\n", deckCount_fail, ITERATIONS);

   return 0;

}
