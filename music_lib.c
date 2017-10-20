#include "music_lib.h"

int table_len(){
  int i = 0;
  while (table[i++]){}
  return i;
}



song_node * table_insert(char song_name[], char artist[], int i){ //helper function to add_song_node
  int len = table_len();
  song_node * temp = (song_node *)malloc(sizeof(song_node));
  temp->name = song_name;
  temp->artist = artist;
  while(len-i > 0){
    if(len-i == 1){
      table[len] = table[i];
      table[i] = temp;
      break;
    }
    table[len+1] = table[len];
    i++;
  }
  return NULL;
}


song_node * add_song_node(song_node * table, char song_name[], char artist[]){
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
    return table_insert(song_name, artist,i);
}

song_node * search_song(song_node * table, char song_name[], char artist[]){
  int i = 0;
  while (table[i]){
    if( !strncmp(table[0]->artist, artist,1) )
      return find_song_by_artist_song(table[i],song_name,artist);
    i++;
  }
  return NULL;
}

song_node * search_artist(song_node * table, char artist[]){
  int i = 0;
  while (table[i]){
    if( !strncmp(table[0]->artist, artist,1) )
      return find_firstsong_by_artist(table[i],artist);
    i++;
  }
  return NULL;
}

song_node * delete_all(song_node * list){
  int x = 0;
  for(x = 0; x < 26; x++){
    table[x] = free_list(table[x]);
  }
}



