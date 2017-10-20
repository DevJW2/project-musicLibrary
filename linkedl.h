#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

struct song_node * table[26];

void print_list(song_node *);
song_node * insert_front(song_node *, char[], char[]);
song_node * free_list(song_node *); 
song_node * insert_order( song_node *, char[], char[]);
song_node * find_song_by_artist_song(song_node *, char[], char[]);
song_node * find_firstsong_by_artist(song_node *, char[]);
song_node * remove_node(song_node *, char[], char[]);
song_node * rand_node(song_node *);
