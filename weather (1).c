/*	Program Author:  Orion Schyberg
	Program Name: 	 weather.c
	Program Purpose: Tells you the weather based off of data from files (not sockets, I double checked)
					 and reports back to you if it's going to be a good day for an outside wedding.
	Date Created: 	 02/19/2020
	Last Modified:	 02/25/2020
*/
#include <stdio.h>
#include <stdlib.h>

// Define constant variables
#define TEMP_LOW 60.0
#define TEMP_HIGH 75.0

// An integer method that acts as a boolean
int valiDate (int m, int d) {
	// Months cannot be greater than twelve, or less than 1.
	if (m > 12 && m < 1) return 0;
	
	// There cannot be below "Day 1" of a month
	else if (d < 1) return 0;
	
	// Alright this is where things get fun, let's start with February
	else if (m == 2 && d > 29) return 0;
	
	// And the months with 30 days...
	else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return 0;
	
	// And the rest with 31
	else if (d > 31) return 0;
	
	// And of course if everything checks out, we leave!
	else return 1;
}


// Defining our variables we need. This SHOULD be fine for any input the user enters.
FILE* inpFile;
char filename [100], d1 [100], m1 [100]; 
int month, day, dmCounter = 0, wdCounter = 0, cMonth, cDay, cYear;
float avgMonthTemp = 0, avgDayTemp = 0, cTemp = 0;

// And that's all we need. Let's rock!
int main (void) {
	// As per usual, I have my polite greeting.
	printf ("Welcome to the weather program! This program reads the potential temperature based off of the average temperatures listed in a file.\n\nWhat is the date of your wedding?\n");
	
	// Input valiadation, now with arrays and stdlib because I finally can!
	do {
		scanf ("%s %s", &m1, &d1);
		// atoi is a function that converts a char or string to an integer if it can, and returns 0 if it cannot. It is perfect in this case because a month or date shouldn't ever be zero.
		month = atoi (m1);
		day = atoi (d1);
		if (!valiDate (month, day)) {
			month = day = '\0';
			printf ("That was an invalid date! What is the date of your wedding?\n");
		}
	} while (!valiDate (month, day));
	
	// Input validation once again for the file.
	do {
		printf ("What is the name of the file holding the city's temperature data?\n");
		scanf ("%s", &filename);
		inpFile = fopen (filename, "r");
		
		// A rather basic try/catch for a "NULL pointer exception", if you will from C++. If the file isn't found, we need to get the user's proper input.
		if (inpFile == NULL) {
			fclose (inpFile);
			printf ("That filename was invalid! ");
		}
	} while (inpFile == NULL);
	fscanf (inpFile, "%d %d %d %f", &cMonth, &cDay, &cYear, &cTemp);
	
	// Alright, now we need to get the data from the file.
	while (cMonth != -1) {
		// Wedding day match?
		if (cMonth == month && cDay == day) {
			dmCounter++;
			wdCounter++;
			avgMonthTemp += cTemp;
			avgDayTemp += cTemp;
		}
		
		// If not, is it the month?
		else if (cMonth == month) {
			dmCounter++;
			avgMonthTemp += cTemp;
		}
		
		// Load up a new day.
		fscanf (inpFile, "%d %d %d %f", &cMonth, &cDay, &cYear, &cTemp);
	}
	// Now we close our file.
	fclose (inpFile);
	
	// Simple average calculations.
	avgMonthTemp /= dmCounter;
	avgDayTemp /= wdCounter;
	
	// Let's print the results...
	printf ("\nThe average temperature of your wedding month is %.2f", avgMonthTemp);
	printf ("\nThe average temperature on your wedding day is %.2f", avgDayTemp);
	
	// If the values are in between the suggested comfort values, we can hold it outside!
	if (TEMP_LOW <= avgDayTemp && TEMP_HIGH >= avgDayTemp && TEMP_LOW <= avgMonthTemp && TEMP_HIGH >= avgMonthTemp) printf ("\nThe weather looks good for an outdoor wedding!");
	
	// And if not... inside!
	else printf ("\nSorry, it's probably best to hold the wedding indoors.");
	
	// We're done.
	return 0;
}
