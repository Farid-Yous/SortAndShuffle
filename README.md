# Sort and Shuffle Project
## Overview
## This project is a C program that allows users to input multiple artists and their respective songs, sorts the artists alphabetically along with their songs, and then shuffles the songs randomly. The shuffled playlist ensures that the same song does not appear twice in the space of 5 songs.

# Features
## Sort Artists and songs:
## Uses insertSort algorithm to sort both artists and their respective songs
## Shuffle Songs:
## Takes all of the inputted songs twice and shuffles them in a manner that they do not repeat in a 5 song range

# How It Works

1. **Input**: 
   - The user is prompted to input up to 4 artists/groups and up to 3 songs per artist/group. 
   - Each song is associated with its artist to maintain artist-song linkage during sorting and shuffling.

2. **Sorting**: 
   - The program first sorts the songs of each artist alphabetically.
   - Then, it sorts the artists alphabetically and reorders their songs accordingly.

3. **Shuffling**: 
   - The program duplicates each song and then shuffles them. 
   - The shuffling ensures that no song appears more than once in close proximity in the final playlist.

4. **Output**: 
   - The program prints the sorted list of artists and their songs.
   - After shuffling, it prints the shuffled playlist.

# How to Compile and Run

To compile the program, use a C compiler like `gcc`:
