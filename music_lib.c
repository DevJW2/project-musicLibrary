#include "music_lib.h"

int table_len(){
  int i = 0;
  while (table[i++]){}
  return i;
}


song_node * table_insert(char song_name[], char artist[], int i){
  int len = table_len();
  song_node * temp = (song_node *)malloc(sizeof(song_node));
  temp->name = song_name;
  temp->artist = artist;
  while(len--){
    if(len == 1){
      table[len] = table[0];
      table[0] = temp;
      break;
    }
    table[len+1] = table[len];
  }
  return NULL;
}


song_node * add_song_node(char song_name[], char artist[]){
  int i = 0;
  int len = table_len();
  int cmp = strncmp(table[0]->artist, artist,1);
  song_node * temp = (song_node *)malloc(sizeof(song_node));
  while (table[i] && !(cmp<0)){
    i++;
    cmp = strncmp(table[i]->artist, artist,1);
  }
  if(cmp == 0){
    return table[i];
  }
  else
    return table_insert(song_name, artist);
}
