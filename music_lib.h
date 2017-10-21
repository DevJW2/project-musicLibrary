#include "linkedl.h"

song_node * add_song_node(song_node *table[], char *name, char artist[]);

song_node * search_song(song_node *table[], char *name, char *artist);

song_node * search_artist(song_node *table[], char *artist);

void print_out_letter(song_node *table[], char letter);

void print_out_artist_songs(song_node *table[], char *artist);

void print_library(song_node *table[]);

void shuffle(song_node *table[]);

song_node * remove_one_song(song_node *table[], song_node * node);

song_node * delete_all(song_node *table[]);

int list_len(song_node *list);

void print_song_node(song_node *node);

int find_index(char first_letter);

