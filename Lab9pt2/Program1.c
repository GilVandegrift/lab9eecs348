/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: g982v599
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
float strToFloat(str[])
{
	return newFloat;
}
*/
char isIn(int array[],int elem,int size)
{
	char in = 'n';
	int lcv;
	for (lcv=0;lcv<size;lcv++){
		if (elem == array[lcv]){
			in = 'y';
		}
	}
	return in;
}

int main()
{
	char months[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	//above is the array of strings(arrays of chars)
	float sales[12];//creates an array of floats to hold sales
	FILE *fp;//file obj
	char buff[255];//temp string
	fp = fopen("input.txt", "r");//opens the file
	int lcv;//loopcontrol variable
	int lcvTwo;//loop control variable two
	printf("Month      Sales\n\n");//title with two new lines
	for (lcv =0; lcv < 12; lcv++) {//loops through the info in the file
		fscanf(fp, "%s", buff);//scans from file to buff (ends at first space encountered)
		printf("%s", months[lcv]);//prints the month
		int space = strlen(months[lcv]);//space is the length of the month and determines how many spaces to use
		for(lcvTwo =0; lcvTwo < (11 - space); lcvTwo++) {//loops till 11-length of the month and prints a space
			printf(" ");
		}
		printf("%s\n", buff);//prints sales
		float newSales;//creates a float
		newSales = (float)atof(buff);//turns buff to a float
		sales[lcv] = newSales;//adds teh sales to the array of sales
	}

	//summary
	printf("\nSales summary:\n");
	//getting min stuff
	int minIndex = 0;
	float minimum = sales[0];
	for (lcv = 0; lcv < 12; lcv++) {//loops through float and sees what the lowest is and stores thoughs values
		if (sales[lcv] < minimum){
			minIndex = lcv;
			minimum = sales[lcv];
		}
	}
	//getting max stuff
	int maxIndex = 0;
	float maximum = sales[0];
	for (lcv = 0; lcv < 12; lcv++) {
		if (sales[lcv] > maximum) {
			maxIndex = lcv;
			maximum = sales[lcv];
		}
	}
	float sumOfSales = 0;
	for (lcv = 0; lcv < 12; lcv++) {
		sumOfSales = sumOfSales + sales[lcv];
	}
	float average = sumOfSales/12;
	printf("Minimum sales:  $");
	printf("%.2f  ", minimum);
	printf("(%s)\n", months[minIndex]);
	printf("maximum sales:  $");
	printf("%.2f  ", maximum);
	printf("(%s)\n", months[maxIndex]);
	printf("Average sales:  $");
	printf("%.2f  \n", average);

	//sixmonth moving avg rep
	printf("\nSix-Month Average Report:\n");
	for(lcv =0; lcv <7; lcv++){
		printf("%s", months[lcv]);
		int space = strlen(months[lcv]);//space is the length of the month and determines how many spaces to use
		for(lcvTwo =0; lcvTwo < (11 - space); lcvTwo++) {//loops till 11-length of the month and prints a space
			printf(" ");
		}
		printf("- %s", months[lcv+5]);
		int spaceTwo = strlen(months[lcv+5]);//space is the length of the month and determines how many spaces to use
		for(lcvTwo =0; lcvTwo < (11 - spaceTwo); lcvTwo++) {//loops till 11-length of the month and prints a space
			printf(" ");
		}
		float sixAvg = 0;
		for (lcvTwo =lcv; lcvTwo<(lcv+6);lcvTwo++){
			sixAvg = sixAvg + sales[lcvTwo];
		}
		sixAvg=(sixAvg/6);
		printf("$%.2f\n", sixAvg);
	}

	//highest to lowest
	//*
	printf("\nSales Report (Highest to lowest):\n");
	printf("Months     Sales\n");
	int order[12];
	for (lcv=0;lcv<12;lcv++){
		int greater = 0;
		for (lcvTwo=0;lcvTwo<12;lcvTwo++){
			if (sales[lcv] > sales[lcvTwo]) {
				greater++;
			}
		order[lcv] = greater;
		}
	}
	int lcvThree;
	for (lcv=0;lcv<12;lcv++) {
		for (lcvTwo=0;lcvTwo<12;lcvTwo++) {
			if (order[lcvTwo] == (11-lcv)) {
				printf("%s", months[lcvTwo]);
				int space = strlen(months[lcvTwo]);//space is the length of the month and determines how many spaces to use
				for(lcvThree =0; lcvThree < (11 - space); lcvThree++) {//loops till 11-length of the month and prints a space
					printf(" ");
				}
				printf("$%.2f\n", sales[lcvTwo]);
			}
		}
	}
//*/

	fclose(fp);
	return 0;
}
