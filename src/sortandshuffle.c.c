#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int i = 0, j, k = 0, numOfArtists = 0, numOfSongs = 0, numSongsPerArtist[4];
    char artists[4][80] ,songs[4][3][80] , hyphen[4] = {' ','-',' ','\0'} , shuffled[24][80];
    srand(time(NULL));
    while (numOfArtists < 4)
    {
        printf("Insert an artist/group name:\n");
        fflush(stdout);
        fgets(artists[numOfArtists], sizeof(artists[numOfArtists]), stdin); // Read artist name including spaces
        if (artists[numOfArtists][0] == '\n')
        {
            artists[numOfArtists][0] = '\0'; // Set the string to empty
            break;
        }
    for (j = 0; j < 3; j++) // Loop to get songs for the artist
    {
        printf("Insert song %d for %s: ", j + 1, artists[numOfArtists]); //user input
        fflush(stdout);
        fgets(songs[numOfArtists][j], sizeof(songs[k]), stdin);             // Read song name including spaces
        strcat(songs[numOfArtists][j] , hyphen);
        strcat(songs[numOfArtists][j] , artists[numOfArtists]);
        strcpy(shuffled[k++],songs[numOfArtists][j]);                       // copy twice directly into the shuffling array to save loops
        strcpy(shuffled[k++],songs[numOfArtists][j]);
        if (songs[numOfArtists][j][0] == '\n')
        {
            songs[numOfArtists][j][0] = '\0'; // Set the string to empty
            break;
        }
        numOfSongs++;

    }
        numSongsPerArtist[numOfArtists] = j;
        numOfArtists++;

    }

    for(i = 0; i < numOfArtists; i++)
    {
        sortSongs(songs[i] , numSongsPerArtist[i]);
    }
    sortArtists(artists, numOfArtists , numSongsPerArtist , songs);
    shuffleSongs(songs , numOfSongs , numOfArtists , numSongsPerArtist , shuffled);
    return 0;
}
