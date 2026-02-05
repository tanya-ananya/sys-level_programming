/*
Program Name: Passenger

Author: Taaruni Ananya

Program Description:
This program will take in, store, and welcome passenger's and their flight schedule.
*/

# include <stdio.h>
# include <math.h>

int main(void) {

    // passenger details
    char first_name[50];
    char last_name[50];

    // flight details
    char airline_name[50];
    char flight_num[20];
    char seat_num[3];
    char seat_letter[2];

    // Intake flight and passenger details from user
    printf("Enter the passenger's first name: \n");
    scanf("%s", first_name);

    printf("Enter the passenger's last name: \n");
    scanf("%s", last_name);

    printf("Enter the airline name: \n");
    scanf("%s", airline_name);

    printf("Enter the flight number: \n");
    scanf("%s", flight_num);

    printf("Enter the seat row number: \n");
    scanf("%s", seat_num);

    printf("Enter the seat letter: \n");
    scanf("%s", seat_letter);

    // Print welcome message with inputted information
    printf("Welcome %s %s!! Your flight is %s %s. Your seat is %s%s.", first_name, last_name, airline_name, flight_num, seat_num, seat_letter);

    return 0;
}