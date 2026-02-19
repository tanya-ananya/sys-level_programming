/*
Program Name: Password Modifier

Author: Taaruni Ananya

Program Description:
This program will take in any password from the user and modify it to protect the sensitive information
*/

# include <stdio.h>
# include <math.h>
# include <string.h>

int main(void) {
    char password[21];
    
    // Reads input
    printf("Enter password here: ");
    scanf("%20s", password);

    // Modifies password
    for(int i = 0; i < strlen(password); i++) {
        if (password[i] == 'i') {
            password[i] = '1';
        }
        else if (password[i] == 'a') {
            password[i] = '@';
        }
        else if (password[i] == 'm') {
            password[i] = 'M';
        }
        else if (password[i] == 'B') {
            password[i] = '8';
        }
        else if (password[i] == 's') {
            password[i] = '$';
        }
    }

    strcat(password, "!");
    printf("%s\n", password);

    return 0;
}