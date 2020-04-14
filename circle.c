/*
 * Name: Lawton Pittenger
 * Course Number: COP 3223 Intro to Programming with C
 * Section Number:
 * Assignment Title: Circle.c
 * Date: 1/30/2020
 */

#include <stdio.h>

//Variable Declarations
int rLength, rWidth, tRadius, spacer, numPeople, temp;


//Main method, this is where I will take input from the user as well as perform
//calculations to output the max number of people this room can sit.
int main() {
    printf ("What are the length and width of the room (in feet)?\n");
    scanf ("%d %d", &rLength, &rWidth);
    printf ("What is the radius of the table?\n");
    scanf ("%d" ,&tRadius);
    printf ("What is the required space between each table (in feet)?\n");
    scanf ("%d", &spacer);
    printf ("How many people can be sat at each table?\n");
    scanf ("%d", &numPeople);

//Remove the spacer from the area of the room in order to simplify things.
    rLength -= spacer;
    rWidth -= spacer;

/*This is where I manipulate the tRadius variable in order to perform the proper calculations. What I do here is multiply
the tRadius by 2, in order to get the diameter. After that, I add the spacer to the diameter to make sure that I am accounting
for the necessary amount of space in-between tables. Once I had that done, I had to divide the roomLength and roomWidth by the
total diameter plus spacer of each table. Then I multiplied these values in order to create a grid for the entire room. Lastly,
I multiplied the number of tables by the number of people that could be sat at each table.
 */
    tRadius = (2*tRadius + spacer);
    tRadius = (rLength / tRadius) * (rWidth / tRadius);
    temp = (tRadius * numPeople);


//Simple print lines in order to output my calculations to the console for the user to see.
    printf("This arrangement sits ");
    printf("%d", temp);
    printf(" people\n");
}
