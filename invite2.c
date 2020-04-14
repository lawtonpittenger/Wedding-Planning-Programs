/*  Name: Lawton Pittenger
 *Course: COP 3223C - 0004
 *Professor: Dr. Khahn Vu
 * Assignment: Program 2B, invite2.c
*/
#include <stdio.h>

// Program constants
#define SMALL_PACKAGE 50
#define LARGE_PACKAGE 200
#define ABSOLUTE_MIN 0
#define GUEST_MAX 10000
#define COST_MAX 500.00

int main(void) {
    // Prices of the small and large packages
    float pSCost, pLCost;

    // The 3 main integers that we need.
    int guests, sPacks, lPacks;
    guests = sPacks = lPacks = 0;



    // Let's get the user's input on the cost of small packages.
    printf ("What is the cost of small packages (in USD)?\n$");
    scanf("%f", &pSCost);

    // Let's make sure that the number follows the constraints outlined. Except this time, we can use a loop and get rid of "default constants" which I have previously used.
    while (pSCost >= COST_MAX || pSCost <= ABSOLUTE_MIN) {
        printf ("That number was invalid! What is the cost of small packages (in USD)?\n$");
        scanf("%f", &pSCost);
    }

    // Now for the large packages...
    printf ("What is the cost of large packages (in USD)?\n$");
    scanf ("%f", &pLCost);

    // Once again ensuring that the user followed the requested outlines...
    while (pLCost >= COST_MAX || pLCost <= ABSOLUTE_MIN) {
        printf ("That number was invalid! What is the cost of large packages (in USD)?\n$");
        scanf("%f", &pLCost);
    }

    // ...and finally, for the number of invites being sent.
    printf ("What is the number of invites being sent?\n");
    scanf ("%d", &guests);

    // We want to make sure that it follows the constraints as well.
    while (guests >= GUEST_MAX || guests <= ABSOLUTE_MIN) {
        printf ("That number was invalid! What is the number of invites being sent?\n");
        scanf ("%d", &guests);
    }


    int discrim1;
    float discrim2;

    // Discrim 1 discovers how many small packs fit into large packs.
    if (LARGE_PACKAGE / SMALL_PACKAGE % 2 == 0) discrim1 = LARGE_PACKAGE / SMALL_PACKAGE;
        else discrim1 = LARGE_PACKAGE / SMALL_PACKAGE + 1;

    // For checking cost efficiency. Why? Well, if for some reason this is greater than the other discrim, there is no reason to get large packages at all!
    discrim2 = pLCost / pSCost;

    if (guests <= SMALL_PACKAGE && pLCost >= pSCost) {
        sPacks ++;
        guests = 0;
    }
    else if (guests <= SMALL_PACKAGE && pLCost < pSCost) {
        lPacks ++;
        guests = 0;
    }

        // If it's cost effective to definitely get large packages and possibly small packages...then:
    else if (discrim1 >= discrim2) {
        // We will obviously have some large packs under this condition. Increments the number of large packages needed until the number of guests may be better served by smaller ones.
        while (guests / LARGE_PACKAGE != 0) {
            lPacks ++;
            guests -= LARGE_PACKAGE;
        }

        // Now we have a loop to determine what else gets added! Remember, when guests are greater than 0, this loop will iterate.
        while (guests > 0) {
            // If it's cost effective, get another large pack!
            if (pLCost <= pSCost * guests / SMALL_PACKAGE && guests % SMALL_PACKAGE == 0) {
                lPacks ++;
                guests -= LARGE_PACKAGE;
            }
                // Again if it's cost effective to get another large pack instead.
            else if (pLCost <= pSCost * guests / SMALL_PACKAGE + 1 && guests % SMALL_PACKAGE != 0) {
                lPacks ++;
                guests -= LARGE_PACKAGE;
            }

                // Otherwise, increment the small packs by 1 and modify the guests counter by the number of people in that.
            else {
                sPacks ++;
                guests -= SMALL_PACKAGE;
            }
        }
    }

        // If this triggers, only small packages should be even considered.
    else {
        // Similarly to the above loop, if guests are greater than zero it will iterate.
        while (guests > 0) {
            sPacks ++;
            guests -= SMALL_PACKAGE;
        }
    }

    //  Print out the results so the user can see!
    printf ("\nYou should order %d small package(s).", sPacks);
    printf ("\nYou should order %d large package(s).", lPacks);
    printf ("\nYour cost for invitations will be $%.2f.\n\n", sPacks * pSCost + lPacks * pLCost);

    return 0;
}
