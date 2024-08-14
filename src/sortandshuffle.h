#include <stdbool.h>

#ifndef SORTANDSHUFFLE_H_
#define SORTANDSHUFFLE_H_

bool isValid(char shuffled[24][80] , int i , int place , int numOfSongs);
void sortArtists(char artists[4][80], int numOfArtists, int numSongsPerArtist[4], char songs[4][3][80]);
void sortSongs(char songs[3][80] , int numSongsPerArtist);
void shuffleSongs(char songs[4][3][80], int numOfSongs , int numOfArtists , int numSongsPerArtist[4] ,char shuffled[24][80]);
#endif /* SORTANDSHUFFLE_H_ */
