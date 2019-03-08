#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define CARD_TEST "council_room"


int main() {

   printf("\nStarting Card Test 4: %s\n", CARD_TEST);

   int flag = 0, i;
   int players = 2, player = 0, seed = 1000;
   struct gameState testG, G;
   int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

   initializeGame(players, k, seed, &G);

   memcpy(&testG, &G, sizeof(struct gameState));

   // assert Counicl Room card is drawn to hand
   testG.hand[player][testG.handCount[player]] = council_room;
   testG.handCount[player]++;
   if (G.handCount[player] + 1 == testG.handCount[player]) {
      printf("Assert passed, Council Room card drawn to player's hand.\n");
   }
   else {
      printf("Assert failed, Council Room card not drawn to player's hand.\n");
      flag = -1;
   }

   // assert 4 cards are drawn from deck and Council Room card is discarded
   cardEffect(council_room, 0, 0, 0, &testG, testG.hand[player][testG.handCount[player] - 1], 0);

   if (G.handCount[player] + 4 == testG.handCount[player]) {
      printf("Assert passed, +4 cards drawn and Council Room card discarded.\n");
   }
   else {
      printf("Assert failed, did not draw and/or dsicard Council Room card.\n");
      flag = -1;
   }

   // assert +1 buy
   if (G.numBuys + 1 == testG.numBuys) {
      printf("Assert passed, +1 buy.\n");
   }
   else {
      printf("Assert failed, did not get +1 buy.\n");
      flag = -1;
   }

   // assert 1 card drawn for each other player
   for (i = 1; i < players; i++) {
      if (G.handCount[i] + 1 == testG.handCount[i]) {
         printf("Assert passed, player %d card drawn.\n", (i + 1));
      }
      else {
         printf("Assert failed, player %d card not drawn.\n", (i + 1));
         flag = -1;
      }
   }

   if (flag == 0) {
      printf("Card test 4 passed.\n");
   }
   else {
      printf("Card test 4 failed.\n");
   }

   return 0;

}
