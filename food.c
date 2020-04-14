/*
 * Name: Lawton Pittenger
 * Course Number: COP 3223 Intro to Programming with C
 * Section Number:
 * Assignment Title: COP3223 Assignment 1a (food.c)
 * Date: 1/30/2020
 * Purpose: Determines the optimal seating arrangement for a dining hall based off input from the user.
 */


#include <stdio.h>

int main()
{
    //Declaring Variables
    int pricechicken, pricebeef, numGuests, limit, totalSteak, totalChicken;


    //Taking input from the user, including cost of chicken, beef, numGuests, and spending limit.
    printf("What is the cost of the chicken, in dollars?\n");
    scanf("%d" ,&pricechicken);
    //Checks to make sure that the user enters a value within the correct range.
    if (pricechicken < 0 || pricechicken >= 100){
        printf("Invalid Input\n");
    }


    printf("What is the cost of the beef in dollars?\n");
    scanf("%d" ,&pricebeef);
    //Checks to make sure that the user enters a value within the correct range.
    if (pricebeef <= pricechicken || pricebeef >= 100){
        printf("Invalid Input\n");
    }


    printf("How many guests will there be?\n");
    scanf("%d",&numGuests);
    //Checks to make sure that the user enters a value within the correct range.
    if (numGuests <= 10 || numGuests >= 1000){
        printf("Invalid Input\n");
    }


    printf("What is your spending limit for food, in dollars?\n");
    scanf("%d",&limit);
    //Checks to make sure that the user enters a value within the correct range.
    if (limit <= pricechicken * pricebeef || limit >= pricebeef * numGuests){
        printf("Invalid Input\n");
    }


    /*
     * This is where I perform the calculations in order to output the minimum number of guests who must order chicken
     * for the total cost of the meals to be less than or equal to the designated target. In order to do this, I first
     * found the difference between the price of beef and price of chicken. After that, I simply used that to figure out
     * the maximum number of people who could order beef and still have the total price be beneath the limit / target.
     * After calculating the total number of steaks, I simply subtracted that value from the total number of people that
     * would be attending the event, in order to get the number of guests that must order chicken.
    */
    int disc = (pricebeef - pricechicken);
    totalSteak = (limit - (pricechicken * numGuests)) / disc;
    totalChicken = (numGuests - totalSteak);


    //Simple print line in order to output the minimum number of guests who must order chicken
    //for the total cost of the meals to be less than or equal to the designated target.
    printf("You need at least %d guests to order the chicken.\n", totalChicken);
    return 0;

}


