/*
Program Name: Leap Year

Author: Taaruni Ananya

Program Description:
This program will take in any year from the user and return whether it's a leap year or not.
*/

# include <stdio.h>
# include <math.h>

int main(void) {
    int year;
    

    printf("Enter the year: ");
    scanf("%d", &year);

    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        printf("%d - leap year", year);
    }
    else {
        printf("%d - not a leap year", year);
    }

    return 0;
}