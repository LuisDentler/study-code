#include "../include/playlist.h"


void init_playlist(Playlist *p_playlist)
{
    p_playlist->p_head = NULL;
    p_playlist->size = 0;
}


void add_song(Playlist *playlist, const char *title, const char *artist)
{
    if (playlist->size >= MAX_SONGS)
    {
        printf("Maximum of songs reached !");
        return;
    }
    Song *new_song = malloc(sizeof(*new_song));
    if(!new_song)
    {
        return;
    }

    new_song->title = malloc(strlen(title)+1);
    new_song->artist = malloc(strlen(artist)+1);

    if (!new_song->title || !new_song->artist)
    {
        free(new_song->artist);
        free(new_song->title);
        free(new_song);
        return;
    }
    strcpy(new_song->title, title);
    strcpy(new_song->artist, artist);
    new_song->p_nextSong = NULL;

    if(!playlist->p_head)
    {
        playlist->p_head = new_song;
    }
    else
    {
        Song *last = playlist->p_head;
        while (last->p_nextSong)
        {
            last=last->p_nextSong;
        }
        last->p_nextSong = new_song;
        
    }
    playlist->size++;
    
    
}
