/*
Program Name; Kinetic Energy Calculator
Author's Name: Taaruni Ananya
Description: This program will take time and height inputs from the user, then calculate the time required for an object to reach the ground when dropped from a user-specified height, the velocity at which it hits the ground and the kinetic energy at the moment of impact.
*/

#include <stdio.h>
#include <math.h>

int main() {
    // variable components of the equations
    float mass; //mass in killograms
    float height; // height in meters
    
    // calculated components
    float time; //time in seconds
    float velocity; // velocity in meters per second
    float energy; // kinetic energy in Joules
    
    const float acceleration = 9.8; // acceleration in meters per second squared

    // User prompt for mass
    printf("Enter the mass of the object in kilograms: \n");
    scanf("%f", &mass);
    // User prompt for height
    printf("Enter the height of the drop in meters: \n");
    scanf("%f", &height);

    time = sqrt(2 * (height/acceleration)); // calculates time
    velocity = acceleration * time; // calculates velocity with calculated time
    energy = (0.5 * mass * pow(velocity, 2.0)); // calculates energy with calculated velocity

    // responses with calculated results
    printf("The time taken by an object weighing %.2f to reach the ground when dropped from heigh of %.2f meters is %.2f seconds.\n", mass, height, time);
    printf("The velocity of the object when it hits the ground = %.2f m/s.\n", velocity);
    printf("The kinetic energy at the moment of impact with the ground is %.2f Joules.\n", energy);

    return 0;
}