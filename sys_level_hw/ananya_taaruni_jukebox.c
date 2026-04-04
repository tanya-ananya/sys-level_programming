/*
Program Name: Taaruni's Jukebox

Author: Taaruni Ananya

Program Description: This C program will display song lyrics to the user in the terminal. There will be a list of songs available in the lyric jukebox that the user can pick using its track number. The program will then finally display lyrics from the selected song.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SONGS_COUNT 6
#define LINES 100

// Detailed data for songs 
typedef struct {
    int track;
    char artist[50];
    char song[50];
    char album[50];
    char filename[50];
} Song;

// The folllowing will be the list of songs available for the user to select featuring the artist, song, and album
Song jukebox[SONGS_COUNT] = {
    {1, "Tame Impala", "Dracula", "Deadbeat", "dracula.txt"},
    {2, "Troye Sivan, Ariana Grande", "Dance to This", "Bloom", "dance_to_this.txt"},
    {3, "Troye Sivan, Tate McRae", "You", "Single", "you.txt"},
    {4, "BTS", "Swim", "Arirang", "swim.txt"},
    {5, "Justin Bieber", "Off My Face", "Justice", "off_my_face.txt"},
    {6, "Sam Smith, Normani", "Dancing with a Stranger", "Single", "dancing_with_a_stranger.txt"}
};

// The following will be in charge of printing the list
void print_menu(void) {
    printf("\n\nWelcome to Taaruni Ananya's Lyric Jukebox\n");
    printf("Please select a track from the list below:\n\n");

    printf("%-5s: %-30s  %-25s  %-24s\n", "Track", "Artist", "Song", "Album");
    printf("%-5s%-30s%-25s%-24s\n", "-----", "------------------------------", "-------------------------", "------------------------");

    // A for loop will be deployed for printing all tracks in the list by calling each song's details from jukebox
    for (int x = 0; x < SONGS_COUNT; x++) {
        printf("%d:     %-30s  %-25s  %-24s\n", 
                jukebox[x].track,
                jukebox[x].artist,
                jukebox[x].song, 
                jukebox[x].album
        );
    }
    printf("\nQ: Quit\n");
}

// The following will read the selected song's lyrics file, then print each line with a one second delay
void play_song(Song *s) {
    FILE *fp = fopen(s->filename, "r");
    if (fp == NULL) {
        printf("\nSelection not available. Please try again and select from the list.");
        return;
    }

    printf("Playing %s - %s - %s\n", s->artist, s->song, s->album);

    char line[LINES];
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf(" %s\n", line);
        fflush(stdout); // prints a line of the lyrics
        sleep(1); // ensures a one second delay between prints
    }

    fclose(fp);
}

int main(void) {
    char input[LINES];
    int selection;
    print_menu();

    while (1) {
        printf("Enter a track number or Q to quit: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        // if the user chooses to quit
        if (strcmp(input, "Q") == 0 || strcmp(input, "q") == 0) {
            break;
        }

        selection = atoi(input);

        if (selection < 1 || selection > SONGS_COUNT) {
            printf("\nSelection not available. Please try again and select from the list.");
            continue;
        }

        play_song(&jukebox[selection - 1]);
        print_menu();
    }

    return 0;
}