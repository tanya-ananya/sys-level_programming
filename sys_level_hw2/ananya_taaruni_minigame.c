/*
Program Name: Guessing Minigame

Author: Taaruni Ananya

Program Description: This program will feature vaults that contain standard RPG loot; however, these vaults can only be opened by entering the correct code. Therefore, the game challenges the player to guess the code within a certain number of attempts. The game will provide players with feedback on their guesses, allowing them to determine the code. The feedback consists of three pieces of information: whether the code is higher or lower than the guess, how many digits are correct and in the correct spot, and how many digits are correct but not in the right spot. Of course, if the player guesses all digits correctly, then they will win this challenge and open the vault. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRIES 8
#define DIGITS 3
#define POSSIBLE_VALUES 9

// The following function will generate the random code that the player has to guess in an array
int target_code(int code_array[]) {
    int code = 0;

    for (int x = 0; x < DIGITS; x++) {
        code_array[x] = rand() % (POSSIBLE_VALUES + 1);
        code = code * 10 + code_array[x];
    }
    return code;
}

// The show_answer function will reveal the answer when called at the end of the game
void show_answer(int code_array[]) {
    for (int x = 0; x < DIGITS; x++) {
        printf("%d", code_array[x]);
    }
}

// The parse_reply function will first check if the input is the correct number of valid digits. Then, it will convert the string reply into integers and return that.
int parse_reply(char *string_reply, int code_array[]) {
    if ((int)strlen(string_reply) != DIGITS) {
        return -1;
    }

    int reply = 0;
    for (int x = 0; string_reply[x] != '\0'; x++) {
        if (string_reply[x] >= '0' && string_reply[x] <= '9') {
            code_array[x] = string_reply[x] - '0';
            reply = reply * 10 + (string_reply[x] - '0');
        }
        else {
            return -1;
        }
    }
    return reply;
}

// The num_correct_digits will compare values in each position and return the correct number of digits
int num_correct_digits(int answer[], int reply[]) {
    int answer_digits[10] = {0};
    int reply_digits[10] = {0};

    for (int x = 0; x < DIGITS; x++) {
        if (answer[x] != reply[x]) {
            answer_digits[answer[x]]++;
            reply_digits[reply[x]]++;
        }
    }

    int count_accuracy = 0;
    for (int y = 0; y <= 9; y++) {
        if (answer_digits[y]< reply_digits[y]) {
            count_accuracy += answer_digits[y];
        }
        else {
            count_accuracy += reply_digits[y];
        }
    }
    return count_accuracy;
}

// The num_correct_positions function will compare values in each position and return the correct number of digits in the right positions
int num_correct_positions(int answer[], int reply[]) {
    int count_accuracy = 0;
    for (int x = 0; x < DIGITS; x++) {
        if (answer[x] == reply[x]) {
            count_accuracy++;
        }
    }
    return count_accuracy;
}

int main(void) {
    srand(time(0));
    int answer_digits[DIGITS];
    int answer = target_code(answer_digits);

    int reply_digits[DIGITS];
    int num_tries = TRIES;
    char inputted_ans[128];

    printf("\n\nWelcome to the Tunnels of Doom Guessing Minigame. Guess the three digit code: \n\n");

    while (num_tries > 0) {
        printf("%d tries remaining. What is the code? ", num_tries);

        // gets the player's input
        if (!fgets(inputted_ans, sizeof(inputted_ans), stdin)) {
            break;
        }
        inputted_ans[strcspn(inputted_ans, "\r\n")] = '\0';

        // checks for the user wanting to quit
        if (inputted_ans[0] == 'q' || inputted_ans[0] == 'Q') {
            printf("End of game. Answer: ");
            show_answer(answer_digits);
            return 0;
        }

        // converts the string to an integer using the parse_reply function
        int input_num = parse_reply(inputted_ans, reply_digits);
        if (input_num < 0) {
            printf("Please try again with the correct number of digits and characters");
            continue;
        }

        num_tries--; // reduces the number of tries left after each guess

        // if the user guesses correctly, a message is printed
        if (input_num == answer) {
            printf("You opened the vault!\n\n");
            return 0;
        }

        // uses a pointer to check and return if the user's guess is either too high or too low compared to the target
        char *dir;
        if (input_num > answer) {
            dir = "Too high";
        }
        else {
            dir = "Too low";
        }

        // The following calls the num_correct_digits and num_correct_positions functions to calculate the user's accuracy
        int correct_digits = num_correct_digits(answer_digits, reply_digits);
        int correct_positions = num_correct_positions(answer_digits, reply_digits);

        printf("%s, %d digits are correct and in the right place, %d digits are correct and in the wrong place. \n\n", dir, correct_positions, correct_digits);
    }

    // If the user runs out of tries, this error nessage will be printed along with the answer
    printf("The vault shuts down permanently due to too many incorrect attempts.\nYou failed to open the vault!\nThe secret code was ");
    show_answer(answer_digits); 

    return 0;
}