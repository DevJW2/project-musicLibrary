#include "music_lib.h"

int table_len(){
  int i = 0;
  while (table[i++]){}
  return i;
}



song_node * table_insert(char *song_name, char *artist, int i){ //helper function to add_song_node
  int len = table_len();
  song_node * temp = (song_node *)malloc(sizeof(song_node));

  strcpy(temp->name, song_name);
  strcpy(temp->artist, artist);
  
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


song_node * add_song_node(char *song_name, char *artist){
  int i = 0;
  int len = table_len();
  int cmp = strncmp(table[0]->artist, artist,1);
  song_node * temp = (song_node *)malloc(sizeof(song_node));
  while (table[i] && !(cmp<0)){
    i++;
    cmp = strncmp(table[i]->artist, artist,1);
  }
  if(cmp == 0){
    return insert_order( table[i], song_name, artist );
  }
  else
    return table_insert(song_name, artist,i);
}



song_node * search_song(char *song_name, char *artist){
  int i = 0;
  while (table[i]){
    if( !strncmp(table[0]->artist, artist,1) )
      return find_song_by_artist_song(table[i],song_name,artist);
    i++;
  }
  return NULL;
}

song_node * search_artist(char *artist){
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

/*
  Print out all the entries under a certain letter.
  Print out all the songs of a certain artist
  Print out the entire library.
*/

void print_out_letter(char c){
  song_node * temp = (song_node *)malloc(sizeof(song_node));
  int len = table_len();
  while(len--){
    if (strncmp(table[len]->artist, c) > 0)
      break;
    if (!strncmp(table[len]->artist, c)){
      temp = table[len];
      break;
    }
  }
  printf("All %c artists and songs\n", c);
  if(!temp) 
    printf("There are no artists or songs in this list");
  while (temp = temp->next)
    printf("%s: %s |", temp->artist, temp->name);
  printf("\n");
}

void print_out_artist_songs(song_node * list, char * artist){
  while (list = list->next){
    if (strcmp(list->artist, artist) > 0)
      break;
    if (strcmp(list->artist, artist) == 0)
      printf(" %s: %s |", temp->artist, temp->name);
  }
}

void print_library(){
  int len = table_len();
  hchar * temp = '';
  for(len; len > 0; len--){
    strncpy(temp, table[len]->artist, 1);
    print_out_letter(temp);
  }
}
