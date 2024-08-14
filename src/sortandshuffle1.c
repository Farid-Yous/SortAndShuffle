#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(char shuffled[24][80], int place)
{
    int limit = place - 5 < 0? 0 : place - 5;                            /*limit checks if i goes out of bounds and replaces it with the appropriate value if so*/

    for( int j = limit; j < place; j++)
    {
        if(strcmp(shuffled[j] , shuffled[place]) == 0)           //check if the songs are the same
            return false;
    }
    return true;

}
/*in order to allign with the format of the document specified on moodle,
I implemented an algorithm that, at every occurence of an artist swap in the sorting algorithm,
all of their songs will be swapped as well so that the sorted artist will be displayed with their sorted songs underneath.
*/
void sortArtists(char artists[4][80], int numOfArtists, int numSongsPerArtist[4], char songs[4][3][80]) {
    int i, j, k;
    char temp_artist[80], temp_songs[3][80];
    int temp_numSongs;

    // Perform the sorting on the artists array (insertion sort)
    for (i = 0; i < numOfArtists - 1; i++) {
        for (j = i + 1; j < numOfArtists; j++) {
            if (strcmp(artists[i], artists[j]) > 0) {
                // Swap artists
                strcpy(temp_artist, artists[i]);
                strcpy(artists[i], artists[j]);
                strcpy(artists[j], temp_artist);

                // Swap the number of songs per artist
                temp_numSongs = numSongsPerArtist[i];
                numSongsPerArtist[i] = numSongsPerArtist[j];
                numSongsPerArtist[j] = temp_numSongs;

                // Swap all songs
                for (k = 0; k < 3; k++) {
                    strcpy(temp_songs[k], songs[i][k]);
                    strcpy(songs[i][k], songs[j][k]);
                    strcpy(songs[j][k], temp_songs[k]);
                }
            }
        }
    }
    // Print sorted artists and their songs
    for(i = 0; i < numOfArtists; i++) {
        printf("Songs for: %s\n", artists[i]);
        fflush(stdout);
        for(j = 0; j < numSongsPerArtist[i]; j++) {
            printf("%s\n", songs[i][j]);
            fflush(stdout);
        }
    }
}
/*
* This method sorts the songs of a specific artist alphabetically. It takes as input:
* - songsOfAnArtist: the array of the songs of an artist that was provided from the standard input
* - numOfArtists: the number of artists provided from the standard input
*/
void sortSongs(char songs[3][80] , int numSongsPerArtist)
{
    int i , j;
    char temp[80];
    for(i = 0; i < numSongsPerArtist - 1; i++)
    {
       for(j = i + 1; j < numSongsPerArtist; j++)
       {
        if(strcmp(songs[i] , songs[j]) > 0)
        {
            strcpy(temp,songs[i]);                // store into temporary array
            strcpy(songs[i] , songs[j]);
            strcpy(songs[j] , temp);
        }
       }
    }
}
/* shuffleSongs is a function that shuffles songs and implements a simple boolean helper function called isValid found at the top of this file.
ShuffleSongs randomises a place in the array for a potential swap, and before the swap passes the array and place into the checker to see if its valid.
if it is found to not be valid, the place is randomised again. */
void shuffleSongs(char songs[4][3][80], int numOfSongs , int numOfArtists , int numSongsPerArtist[4] ,char shuffled[24][80]) {
    char temp[80];
    int i, place;
    // Duplicate each song in the songs array into shuffled
    printf("artists %d \n songs %d \n" , numOfArtists , numOfSongs);
    fflush(stdout);
    for (i = 0; i < (numOfSongs * 2) - 1; i++) {
        place = rand() % (numOfSongs * 2); // Get initial place for potential swap

        while (!isValid(shuffled, place)) {
            place = rand() % (numOfSongs * 2); // Keep looking for a valid place if the current choice is not valid
        }

        // Perform the swap
        strcpy(temp, shuffled[i]);              // copy into a temporary array
        strcpy(shuffled[i], shuffled[place]);
        strcpy(shuffled[place], temp);
    }
    printf("shuffled playlist:\n");
    fflush(stdout);
    for (i = 0; i < numOfSongs * 2; i++) {
        printf("%d: %s \n", i + 1, shuffled[i]);
        fflush(stdout);
    }
}

