#include "linkedl.h"

song_node* add_song_node(char song_name[], char artist[]);

int table_len();

song_node * table_insert(char song_name[], char artist[], int i);

song_node * checklist(song_node *, struct song_node *);

song_node * print_out_letter(char letter[]);

song_node * print_out_song_of_artist(song_node *, char artist[]);

song_node * print_out_library(song_node *);

