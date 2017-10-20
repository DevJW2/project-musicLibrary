#include "linkedl.h"

song_node * add_song_node(char *, char *);

int table_len();

song_node * table_insert(char *, char *, int i);

song_node * checklist(song_node *, song_node *);

song_node * print_out_letter(char *);

song_node * print_out_song_of_artist(song_node *, char *);

song_node * print_out_library(song_node *);

song_node * search_song(char *, char *);

song_node * search_artist(char *);

song_node * delete_all(song_node *);

