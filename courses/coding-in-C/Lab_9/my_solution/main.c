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
    printf("\nSearching for song 'Layla' (iterative):\n");
    Song *found = find_song_by_title(&myPlaylist, "Layla");
    if (found)
    {
        printf("Gefunden: %s von %s\n", found->title, found->artist);
    }
    else
    {
        printf("Song not found\n");
    }

    //Zähle die songs der Playlist 
    int count = count_songs_recursive(myPlaylist.p_head);
    printf("The playlist contains %d Songs!\n", count);



    delete_playlist(&myPlaylist);

    return 0;
}