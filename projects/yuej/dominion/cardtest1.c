#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define CARD_TEST "adventurer"

int main() {

   printf("\nStarting Card Test 1: %s\n", CARD_TEST);

   int flag = 0, i, cardDrawn1, cardDrawn2;

   // initialize gameState
   int players, seed, testCount = 0, originalCount = 0;
   struct gameState G, testG;
   int* k = kingdomCards(minion, smithy, gardens, tribute, baron, adventurer, cutpurse, mine, embargo, outpost);
   seed = 1000;
   players = 2;

   initializeGame(players, k, seed, &G);

   memcpy(&testG, &G, sizeof(struct gameState));

   // assert adventurer card is drawn
   testG.hand[players - 1][testG.handCount[players - 1]] = adventurer;
   testG.handCount[players - 1]++;
   if(G.handCount[players - 1] + 1 == testG.handCount[players - 1]){
      printf("Assert of test adventurer card drawn passed.\n");
   }
   else {
      printf("Assert of test adventurer card drawn failed.\n");
      flag = -1;
   }

   // assert that adventurer card draws two Treasure cards
   cardEffect(adventurer, 0, 0, 0, &testG, testG.hand[players - 1][testG.handCount[players - 1]], 0);

   for(i = 0; i < testG.handCount[players - 1]; i++) {
      cardDrawn1 = testG.hand[players - 1][i];

      if(cardDrawn1 == copper || cardDrawn1 == silver || cardDrawn1 == gold) {
         testCount++;
      }
   }
   for(i = 0; i < G.handCount[players - 1]; i++) {
      cardDrawn2 =  G.hand[players - 1][i];

      if(cardDrawn2 == copper || cardDrawn2 == silver || cardDrawn2 == gold) {
         originalCount++;
      }
   }

   if((testCount - originalCount) > 0 && (testCount - originalCount) < 3) {
      printf("Assert of test adventurer card draws: %d Treasure cards. Pass\n", (testCount - originalCount));
   }
   else {
      printf("Assert of test adventurer card draws: %d Treasure cards. Failed\n", (testCount - originalCount));
      flag = -1;
   }

   // assert that extra cards are present in testG from playing adventurer card
   if(G.handCount[players - 1] < testG.handCount[players - 1]) {
      printf("Assert of extra cards present in testG from playing adventurer card passed.\n");
   }
   else {
      printf("Assert of extra cards present in testG from playing adventurer card failed.\n");
   }

   if(flag == 0) {
      printf("Card test 1 passed.\n");
   }
   else {
      printf("Card test 1 failed.\n");
   }

   return 0;

}
