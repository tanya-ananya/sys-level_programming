/* 
Program Name: Word Frquency

Author: Taaruni Ananya

Program Description: This program will take in an input from the user and output the frequencies of each word.
*/

# include <stdio.h>
# include <math.h>
# include <string.h>

int main(void) {
    int n;
    char words[20][10]; // constricts to 20 words, up to 10 characters

    // Reads input
    printf("Enter words here \n");
    scanf("%d", &n);

    for (int x = 0; x < n; x++) {
        scanf("%9s", words[x]); // This for loop will read the inputted words }
    }

    for (int x = 0; x < n; x++) { // This for loop will count frequencies
        int frequencies = 0;

        for (int y = 0; y < n; y++) {
            if (strcmp(words[x], words[y]) == 0) {
                frequencies++;
            }
        }

        printf("%s - %d\n", words[x], frequencies);
    }

    return 0;
}