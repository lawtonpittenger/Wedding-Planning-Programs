//Name: Lawton Pittenger
//Course: COP 3223C - 0004
//Professor: Dr. Khahn Vu
//Assignment: Program 2B, cake.c
#include<stdio.h>




//Variables
const double PI = 3.141592654;
int l,i,r;
int guests=0;
double a, ra1, ra2;




//Main method
int main(void)
{
    //Collecting input from the user, storing it in variables.
    printf("How many layers will your cake have?\n");
    scanf("%d",&l);
    printf("What is the radius of the top layer?\n");
    scanf("%lf",&ra1);
    printf("What is the radius of the bottom layer?\n");
    scanf("%lf",&ra2);
    printf("How much cake in cross-sectional area does each guest need?\n");
    scanf("%lf",&a);





    //Difference variable declaration and for loop, this is the main algorithm that calculates the max number of
    //people that the specified cake could feed.
    double difference=(ra2-ra1)/((double)l-1);
    for(i=0,r=ra1;i<l;i++)
    {
        double p =PI*r*r/a;
        guests+=(int)p;
        r += difference;
    }





    //prints the result so the user can see it.
    printf("Your cake will feed %d guests\n", guests);
    return 0;
}