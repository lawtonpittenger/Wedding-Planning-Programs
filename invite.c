/*  
Name: Lawton Pittenger
Course: COP 3223C - 0004
Professor: Dr. Khahn Vu
Assignment: Program 2B, invite.c
*/
#include <stdio.h>
 
// Program constants
#define SMALL_PACKAGE 50
#define LARGE_PACKAGE 200
#define ABSOLUTE_MIN 0
#define GUEST_MAX 10000
#define COST_MAX 500.00
 
// Default value constants
#define DEFAULT_SMALL_PACKAGE_COST 50.99
#define DEFAULT_LARGE_PACKAGE_COST 150.99
#define DEFAULT_GUESTS 240
 
int main(void) {
  // Prices of the small and large packages
  float pSCost, pLCost;
 
  // The 3 main integers that we need.
  int guests, sPacks, lPacks;
 
  // I always like to greet users to the program and inform them of any special limitations.
  printf ("Welcome to the wedding invitation program!\n\nThis program exists to help you get the optimal numbers of wedding invitation packages for your wedding guests. Please be advised that there are several constraints to follow:");
  printf ("\n- The number of invitations in a small package are %d\n- The number of invitations in a large package are %d\n- The maximum number of guests is %d\n- The cost of a package needs to be less than %.2f\n\n", SMALL_PACKAGE, LARGE_PACKAGE, GUEST_MAX, COST_MAX);
 
  // Let's get the user's input on the cost of small packages.
  printf ("What is the cost of small packages (in USD)?\n$");
  scanf("%f", &pSCost);
 
  // Let's make sure that the number follows the constraints outlined.
  if (pSCost >= COST_MAX || pSCost <= ABSOLUTE_MIN) {
    pSCost = DEFAULT_SMALL_PACKAGE_COST;
    printf ("The entered number was invalid! The default value of %.2f will be applied for the value of small packages.\n", DEFAULT_SMALL_PACKAGE_COST);
  }
 
  // Now for the large packages...
  printf ("What is the cost of large packages (in USD)?\n$");
  scanf ("%f", &pLCost);
 
  // Once again ensuring that the user followed the requested outlines...
  if (pLCost >= COST_MAX || pLCost <= ABSOLUTE_MIN) {
    pLCost = DEFAULT_LARGE_PACKAGE_COST;
    printf ("The entered number was invalid! The default value of %.2f will be applied for the value of large packages.\n", DEFAULT_LARGE_PACKAGE_COST);
  }
 
  // ...and finally, for the number of invites being sent.
  printf ("What is the number of invites being sent?\n");
  scanf ("%d", &guests);
 
  // We want to make sure that it follows the constraints as well.
  if (guests >= GUEST_MAX || guests <= ABSOLUTE_MIN) {
    guests = DEFAULT_GUESTS;
    printf ("The entered number was invalid! The default value of %d will be applied for the number of invites being sent.\n", DEFAULT_GUESTS);
  }
 
  // What are these numbers for? They allow me to run the code cleanly and make my IF/ELSE statements easier to read. Discrim 1 and Discrim 2 have important functions that will be described below...
  int discrim1;
  float discrim2;
 
  // Discrim 1 discovers how many small packs fit into large packs.
  if (LARGE_PACKAGE / SMALL_PACKAGE % 2 == 0) discrim1 = LARGE_PACKAGE / SMALL_PACKAGE;
 
  // Specifically for the constraints we have in this program, this isn't necessary, but I like having fluidity in case a user changes the constant numbers up a little bit in the program itself to test my mathematics.
  else discrim1 = LARGE_PACKAGE / SMALL_PACKAGE + 1;
 
  // For checking cost efficiency. Why? Well, if for some reason this is greater than the other discrim, there is no reason to get large packages at all!
  discrim2 = pLCost / pSCost;
 
  // For absurdly low numbers of guests, the code that starts on 87 would hiccup.
  if (guests <= SMALL_PACKAGE && pLCost >= pSCost) {
    sPacks = 1;
    lPacks = 0;
  }
 
  else if (guests <= SMALL_PACKAGE && pLCost < pSCost) {
    lPacks = 1;
    sPacks = 0;
  }
 
  // We check to make sure that the case outlined in line 72 is not true.
  else if (discrim1 >= discrim2) {
    // IF it's cost efficient to get a large package, we can do it. Important: lPacks CAN end up being 0 here. However, this is OKAY as we check some things out below.
    lPacks = guests / LARGE_PACKAGE;
 
    // Adjusts our guests without invites count for the number of large packs we will get.
    guests -= lPacks * LARGE_PACKAGE;
 
    // IF the number of large packages covers the entire guest count, we don't need any additional packages.
    if (guests == 0) sPacks = 0;
 
    // Fall-through logic a great way to make efficient code and check for additional conditions, such as these 2 IF statements that check cost efficiency!
    // Sometimes it's cheaper to get another large package instead of a small one. The first statement checks to see if there isn't any remainder with small packages. The second assumes that there is one, and checks to see if the condition still fits with the correctly adjusted small package amount that would be required.
    else if (pLCost <= pSCost * guests / SMALL_PACKAGE && guests % SMALL_PACKAGE == 0) lPacks ++;
    else if (pLCost <= pSCost * guests / SMALL_PACKAGE + 1 && guests % SMALL_PACKAGE != 0) lPacks ++;
 
    // IF there are guests without invites, we need another small package.
    else if (guests / SMALL_PACKAGE == 0 && guests % SMALL_PACKAGE > 0) sPacks ++;
 
    // IF the number of guests is perfectly fit by some number of small packages.
    else if (guests % SMALL_PACKAGE == 0) sPacks = guests / SMALL_PACKAGE;
   
    // IF we get here, there was a remainder leftover in the above statement and we need one additional small package.
    else sPacks = guests / SMALL_PACKAGE + 1;
  }
 
  // Amazingly, this is all that is needed if for some reason small packages are a better deal than large packages.
  else {
    sPacks = guests / SMALL_PACKAGE;
    guests -= SMALL_PACKAGE * sPacks;
    lPacks = 0;
    // Any leftover guests? One more package is needed.
    if (guests > 0) sPacks ++;
  }
 
  // We're done. Print out the results!
  printf ("\n\nYou should order %d small package(s).", sPacks);
  printf ("\nYou should order %d large package(s).", lPacks);
  printf ("\nYour cost for invitations will be $%.2f.\n\nThank you for using the program!\n", sPacks * pSCost + lPacks * pLCost);
 
  return 0;
}