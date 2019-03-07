#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {

   printf("\nStarting Unit Test 1: getCost() function\n");

   // initialize card costs and the test array
   int i;
   int testCardCost[27] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4};
   int testCardName[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};

   int testCheck[27];
   char* cardNames[27] = {"curse", "estate", "duchy", "province", "copper", "silver", "gold", "adventurer", "council_room", "feast", "gardens", "mine", "remodel", "smithy", "village", "baron", "great_hall", "minion", "steward", "tribute", "ambassador", "cutpurse", "embargo", "outpost", "salvager", "sea_hag", "treasure_map"};

   // loop to get the cost from function to test array
   for(i = 0; i < 27; i++) {
      testCheck[i] = getCost(testCardName[i]);
   }

   // loop to assert getCost() performed correctly
   int assertCounter = 0;

   for(i = 0; i < 27; i++) {
      if(!(testCardCost[i] == testCheck[i])) {
         printf("Assert failed on this card: %s\n", cardNames[i]);
      }
      else {
         printf("Assert passed on this card: %s\n", cardNames[i]);

         assertCounter++;
      }
   }

   // check getCost() performs correctly when passed a bad int
   if(getCost(-8) == -1) {
      printf("Assert passed on this card: %s\n", "-8");

      assertCounter++;
   }
   else {
      ;   // do nothing
   }

   if(assertCounter == 28) {
      printf("Unit test 1 passed.\n");
   }
   else {
      printf("Unit test 1 failed.\n");
   }

}
