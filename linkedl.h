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
int table_len();
song_node * table_insert(char song_name[], char artist[], int i);
song_node * insert_front(song_node *, char[], char[]);
song_node * free_list(song_node *); 
song_node * insert_order( song_node *, char[], char[]);
song_node * checklist(song_node *, struct song_node *);


