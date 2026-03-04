#include "include/playlist.h"

int main(void)
{
    printf("Max Playlistgröße ist auf %d gesetzt.\n",MAX_SONGS);
    Playlist myPlaylist;
    init_playlist(&myPlaylist);

    add_song(&myPlaylist, "Crawling", "Linkin Park");
    add_song(&myPlaylist, "Layla", "Eric Clapton");
    add_song(&myPlaylist, "Esperanto", "Max Herre");

    print_playlist(&myPlaylist);

    delete_firstSong(&myPlaylist);

    print_playlist(&myPlaylist);

    delete_playlist(&myPlaylist);

    return 0;
}