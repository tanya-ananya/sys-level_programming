/*
Program Name: Command Launcher

Author: Taaruni Ananya

Program Description: This program takes input from the user and will run the command, simulating a basic command shell.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void) {
    char cmd[100];
    char path[120] = "/bin/";

    while (1) {
        printf("my_shell :> ");
        fgets(cmd, sizeof(cmd), stdin);

        cmd[strcspn(cmd, "\n")] = '\0';

        if (strcmp(cmd, "exit") == 0) {
            printf("Exiting...\n\n");
            exit(0);
        }
        
        strcpy(path, "/bin/");
        strcat(path, cmd);

        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(1);
        } else if (pid == 0) {
            execl(path, cmd, NULL);

            strcpy(path, "/usr/bin/");
            strcat(path, cmd);
            execl(path, cmd, NULL);

            perror("execl failed");
            exit(1);
        } else {
            wait(NULL);
            printf("Parent: command completed. \n\n");
        }
    }
    return 0;
}