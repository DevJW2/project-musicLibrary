#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
};

struct song_node * table[26];

void print_list(struct song_node *);
struct song_node * insert_front(struct song_node *, char[], char[]);
struct song_node * free_list(struct song_node *); 
struct song_node * insert_order(struct song_node *, char[], char[]);
struct song_node * compare_songs(struct song_node *, struct song_node *);


