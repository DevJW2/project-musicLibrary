#include "linkedl.h"

song_node * add_song_node(char *, char *);

int table_len();

song_node * table_insert(char *, char *, int i);

song_node * checklist(song_node *, song_node *);

void print_out_letter(char);

void print_out_artist_songs(song_node *, char *);

void print_library();

song_node * search_song(char *, char *);

song_node * search_artist(char *);

song_node * delete_all(song_node *);

