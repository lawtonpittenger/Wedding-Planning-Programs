
/*
 * Name: Lawton Pittenger
 * Course Number: COP 3223 Intro to Programming with C
 * Section Number:
 * Assignment Title: COP3223 Assignment 1a (table.c)
 * Date: 1/30/2020
 * Purpose: Determines the optimal seating arrangement for a dining hall based off input from the user.
 */

#include <stdio.h>

// 	Main execution occurs here.
int main (void) {
    // 	All of the initial required variables
    int rWidth, rLength, tWidth, tLength, spacer, numPeople, numTables, rArea, tArea;

    // 	This block of code from lines 15-22 stores values in the variables we created earlier.
    printf ("What are the length and width of the room (in feet)?\n");
    scanf ("%d %d", &rLength, &rWidth);
    printf ("What are the length and width of the tables (in feet)?\n");
    scanf ("%d %d",&tLength, &tWidth);
    printf ("What is the required space between each table (in feet)?\n");
    scanf ("%d", &spacer);
    printf ("How many people can be sat at each table?\n");
    scanf ("%d", &numPeople);

    /* First off, we can just snip 3 feet off of the edges of the room.
    */
    rLength -= spacer;
    rWidth -= spacer;

    /*	The effective space a table takes up is now able to be modified simply. By adding 3 to the length
        and width of the table, we have the functional space a table now takes up.
    */
    tLength += spacer;
    tWidth += spacer;

    /*	At first I didn't believe it, but apparently the optimal arrangement of tables in some sort of rectangular
        formation is best done in one specific arrangement. The tables are either laid out lengthwise or widthwise,
        and that is just that. All experiments I ran in paint on a pixel-to-foot ratio show this to be true.

        this if-else statement determines the most optimal arrangement.
    */
    if (rLength / tLength * rWidth / tWidth >= rLength / tWidth * rWidth / tLength) numTables = rLength / tLength * (rWidth / tWidth);
    else numTables = rLength / tWidth * (rWidth / tLength);

    // And now, we print the output.
    printf ("\nThe optimal arrangement seats %d people.", numPeople * numTables);
    return 0;
}