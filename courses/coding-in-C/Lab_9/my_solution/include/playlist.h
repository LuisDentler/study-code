#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//preprocessor macro MAximale Songs in der Playlist
#define MAX_SONGS 100

//Structs 
typedef struct Song
{
    char *title;
    char *artist;
    struct Song *p_nextSong;
}Song;

typedef struct Playlist
{
    Song *p_head;
    int size;
}Playlist;

//Funktionen 
void init_playlist(Playlist *p_playlist);
void add_song(Playlist *playlist, const char *title, const char *artist);
void print_playlist(const Playlist *playlist);
void delete_firstSong(Playlist *playlist);
void delete_playlist(Playlist *playlist);

Song* find_song_by_title(Playlist *playlist, const char *title);



#endif