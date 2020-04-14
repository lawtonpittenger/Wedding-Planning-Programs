/* Name: Lawton Pittenger
 * Course: COP3223
 * Assignment: Program 3B / Schedule.c
 * */


#include <stdio.h>
#include <stdlib.h>



//Main method

int main()
{



//Declaring all necessary variables

    int index[168] = {0};
    int startIndexing, endIndexing, overBooked;
    int i, j, k, l, num = 1;
    int day, sHour, eHour;
    int numSchedule, numEvents;
    FILE *ptr;



//This is where I open the schedule.txt file and scan all of its contents

    ptr = fopen("schedule.txt", "r");
    fscanf(ptr, "%d" , &numSchedule);




//This is where I have my first for loop that scans through the entire schedule file.

    for(i=0; i<numSchedule; i++)
    {
        fscanf(ptr, "%d" , &numEvents);




//This nested for loop is responsible for all the calculations.

        for(j=0; j<numEvents; j++)
        {
            fscanf(ptr, "%d %d %d" , &day, &sHour, &eHour);

            startIndexing = day*24 + sHour;
            endIndexing = day*24 + eHour;

//Last nested loop which is resposible for updating the index to make sure it is correct at all times.

            for(k=startIndexing; k<endIndexing; k++)
            {
                index[k]++;

                if(index[k]>1)
                {
                    overBooked = 1;
                    break;
                }
                else
                {
                    overBooked = 0;
                }
            }
            if(overBooked)
            {
                break;
            }
        }



//Checks to make sure that the item in position l is not greater than 168. (The number of hours om a week)

        for (l=0; l<168; l++)
        {
            index[l]=0;
        }

//prints to the console so the user can see.

        if(overBooked)
        {
            printf("Schedule #%d: Sorry, you double booked yourself again.\n", num);
            num++;
        }
        else
        {
            printf("Schedule #%d: Good job! no conflicts!\n", num);
            num++;
        }
    }

    fclose(ptr);

    return 0;
}