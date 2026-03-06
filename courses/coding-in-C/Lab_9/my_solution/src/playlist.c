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

void print_playlist(const Playlist *playlist)
{
    printf("Playlist contains %d song(s):\n", playlist->size);
    Song *current = playlist->p_head;
    while (current)
    {
        printf("Title: %s, Artist: %s\n", current->title, current->artist);
        current = current->p_nextSong;
    }
    
}

void delete_firstSong(Playlist *playlist)
{
    if (!playlist->p_head)
    {
        return;
    }
    Song *tempo = playlist->p_head;
    playlist->p_head = tempo->p_nextSong;

    free(tempo->artist);
    free(tempo->title);
    free(tempo);

    playlist->size--;
}

void delete_playlist(Playlist *playlist)
{
    while(playlist->p_head)
    {
        delete_firstSong(playlist);
    }
}

Song* find_song_by_title(Playlist *playlist, const char *title)
{
    //pointer auf ersten Song playlist 
    Song *current = playlist->p_head;

    //Solange current vorhanden 
    while(current)
    {
        //Wenn titel des aktuellen Songs = Titel des gesuchten Songs
        if (strcmp(current->title, title)== 0)
        {
            //Gebe aktuellen Song als den gefunden Zurück
            return current;
        }
        //springe zum nächsten Song in der Playlist 
        current = current->p_nextSong;
    }
    //Wenn kein pasender Song gefunden wurde return NULL
    return NULL;
}

int count_songs_recursive(const Song *current)
{
    //Wenn der aktuelle Knoten Nicht existiert 
    if (current == NULL)
    {
        return 0;
    }
    //Wenn nicht dann gib 1 + den wert von der gleichen Funktion des näcshten Knoten
    return 1 + count_songs_recursive(current->p_nextSong);
    
}

void sort_playlist_by_title(Playlist *playlist)
{
    //Wenn Liste NULL dann beenden da nichts zu sortieren 
    if(!playlist->p_head)
    {
        return;
    }

    int switched;
    Song *ptr1;
    Song *sorted_ptr = NULL;

    do
    {
        switched = 0;
        ptr1 = playlist->p_head;
        //Solange der ptr1->p_nextSong nicht gleich dem sorted_pointer ist 
        while (ptr1->p_nextSong != sorted_ptr)
        {
            //Wenn die Songs ptr1 und ptr1->p_nextSong nicht richtig sortiert sind
            if(strcmp(ptr1->title, ptr1->p_nextSong->title)>0)
            {
                //Vertausche die songs in extra funktion 
                switch_songs(ptr1, ptr1->p_nextSong);
                //Setzte switched =1 sodass die schleife weiter läuft -> noch nicht fertig sortiert!
                switched = 1;
            }
            //gehe eine Position weiter
            ptr1 = ptr1->p_nextSong;

        }
        //Verschiebe Sortier Grenze auf ptr1
        sorted_ptr = ptr1;
        
    } while (switched);
}

static void switch_songs(Song *x, Song *y)
{
    // Speicher die Werte zwischen 
    char *temp_t = x->title;
    char *temp_a = x->artist;

    //Werte
    y->artist = x->artist;
    y->title = x->title;

}
