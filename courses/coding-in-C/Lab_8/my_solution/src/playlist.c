#include "../include/playlist.h"


void init_playlist(Playlist *p_playlist)
{
    p_playlist->p_head = NULL;
    p_playlist->size = 0;
}
