/*
Program Name: String Reversal

Author: Taaruni Ananya

Progrma Description: This program takes input from the user and reverses the input, then prints the new string.
*/

#include <stdio.h>
#include <string.h>
#define MAX_LEN 150

// This helper function takes two character pointers (left and right) and swaps them. 
void swap(char *left, char *right) {
    char temp = *left;
    *left = *right;
    *right = temp;
}

// This function takes a character pointer (str) pointing to a null-terminated string entered by the user and delivers the swapped output.
void reverseString(char *str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        swap(&str[start], &str[end]);
        start++;
        end--;
    }
}

int main() {
    char message[MAX_LEN];

    printf("Enter a string: ");
    fgets(message, MAX_LEN, stdin);
    printf("\nOriginal string: %s", message);
    reverseString(message);
    printf("Reversed string: %s", message);

    return 0;
}