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


    //Suche nach dem Song 
    printf("\nSuche nach Song Layla: \n");
    Song *found = find_song_by_title(&myPlaylist, "Layla");
    if (found)
    {
        printf("Gefunden: %s von %s\n", found->title, found->artist);
    }
    else
    {
        printf("Song nicht gefunden\n");
    }

    //Zähle die songs der Playlist 
    int count = count_songs_recursive(myPlaylist.p_head);
    printf("Die Playlist enthält %d Songs!\n", count);



    delete_playlist(&myPlaylist);

    return 0;
}