#include "music_lib.h"


song_node * add_song_node(song_node *table[], char *name, char artist[]) {
  int i = find_index(artist[0]);
  song_node *tmp;
  if (!(strncmp(artist, table[i]->artist, 1))) {
    tmp = table[i];
    tmp = insert_order(tmp, name, artist);
    table[i] = tmp;
    return table[i];
  }
  return tmp;
}

// Search song
song_node * search_song(song_node *table[], char *name, char *artist) {
  int i = find_index(artist[0]);
  song_node *tmp;
  tmp = table[i];
  while (tmp) {
    // Check if correct node
    if (!strcmp(name, tmp->name) && !strcmp(artist, tmp->artist)) {
      printf("Song exists!\n");
      return tmp;
    }
    tmp = tmp->next;
  }
  printf("Song doesn't exist!\n");
  return tmp;
}

// Search artist
song_node * search_artist(song_node *table[], char *artist) {
  int i = find_index(artist[0]);
  song_node *tmp;
  tmp = table[i];
  while (tmp) {
    // Check if correct node
    if (!strcmp(artist, tmp->artist)) {
      printf("Artist exists!\n");
      return tmp;
    }
    tmp = tmp->next;
  }
  printf("Artist doesn't exists\n");
  return tmp;
}

// Print all songs under letter
void print_out_letter(song_node *table[], char letter) {
   int i = find_index(letter);
   print_list(table[i]);
}

// Print all songs by artist
void print_out_artist_songs(song_node *table[], char *artist) {
  int i = find_index(artist[0]);
  song_node *tmp;
  tmp = table[i];
  while (tmp) {
    // Check if correct node
    if (!strcmp(artist, tmp->artist)) {
      printf("Artist: %s -- Name: %s\n", tmp->artist, tmp->name);
      // If the the next node's artist is not equal to the current artist, then return
	if (strcmp(artist, tmp->next->artist)) {
	  return;
	}
    }
    tmp = tmp->next;
  }
  printf("Artist not found!\n");
}

// Print Music Library
void print_library(song_node *table[]) {
  int i = 0;
  int empty = 1; 
  char letter = 97; // ASCII
  for (; i < 26; i++) {
    if (table[i] != 0){
      if(table[i]->next != 0){
	     printf("%c\n", letter);
	     print_list(table[i]);
       empty = 0; 
      }
    }
    letter++;
  }
  if(empty == 1){
    printf("Library is Empty\n");
  }
}

// Print out random songs
void shuffle(song_node *table[]) {
  int playlist_len = 3;
  int i = 0;
  song_node *tmp;
  int random;
  for (; i < playlist_len; i++) {
    random = rand();
    tmp = rand_node(table[random % 26]);
    print_song_node(tmp);
  }
}

// Remove songs
song_node * remove_one_song(song_node *table[], song_node * node) {
  return node;
}

// Delete songs
song_node * delete_all(song_node *table[]) {
  int i = 0;
  for (; i < 26; i++) {
    table[i] = free_list(table[i]);
  }
  return table[0]; 
}



// List length
int list_len(song_node *list) {
  int ret = 0;
  while (list) {
    list = list->next;
    ret++;
  }
  return ret;
}

// Print single node
void print_song_node(song_node *node) {
  printf("Artist: %s -- Name: %s \n", node->artist, node->name);
}

// Find correct letter index
int find_index(char first_letter) {
  int i = 0;
  int first_letter_value = first_letter - 'a';
  for (; i < 26; i++) {
    if (first_letter_value > i) {
    } else {
      return i;
    }
  }
  return i;
}
