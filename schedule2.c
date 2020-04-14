/* Name: Lawton Pittenger
 * Course: COP3223
 * Assignment: Program 3B / Schedule2.c
 * */


#include <stdio.h>

//Main method

int main()
{

    //Variable Declarations

    int fileday, filestart, fileend, events, schedules, x, y, z, a, begin, ending;
    int schedulenum = 0;
    int sum= 0;
    int finalhours=0;
    int hours[168]={0};

//Scans through the entire file
    FILE *ifp;
    ifp = fopen("schedule.txt", "r");
    fscanf(ifp, "%d", &schedules);


    //Very similar style of nested for loops that I used in the first part of this problem. (Schedule.c)
    for(x = 0; x < schedules ; x++)
    {
        schedulenum++;
        fscanf(ifp, "%d", &events);
        for(y = 0 ; y<events ; y++)
        {
            fscanf(ifp,"%d %d %d", &fileday, &filestart, &fileend);

            sum = fileend - filestart;

            begin = fileday*24 + filestart;
            ending= fileday*24 + fileend;

            for(z=begin; z<ending; z++)
            {
                hours[z]++;

                if(hours[z] > 1)
                {
                    sum = 0;

                    break;
                }

            }

            finalhours += sum;
        }


        //Prints the calculated results to the console so the  user can see.
        printf("\n\nSchedule #%d contains %d hours of scheduled acitvity.",schedulenum, finalhours);

        finalhours = 0;

        for(a = 0; a<168;a++)
        {
            hours[a]=0;
        }

    }


    fclose(ifp);
    return 0;
}