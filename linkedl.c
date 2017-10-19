//Jeffrey Weng, Jensen Li
//Project 0: my_tunez
//Period 10
/*
  insert nodes in order
  find and return a pointer to a node based on artist and song name
  find and return a pointer to the first song of an artist based on artist name
  Return a pointer to random element in the list.
  remove a single specified node from the list
  free the entire list
*/


#include "linkedl.h"

void print_list( song_node * list){
  printf("list content: ");
  
  while(list){
    printf("%s - %s",(* list).name, (* list).name);
    list = list->next;
  }
  printf("\n");
}

song_node * insert_front(  song_node * list, char song_name[], char artist[]){
  song_node * new_node = (  song_node *)malloc(sizeof(*list));
  (* new_node).next = list;
  (* new_node).name  = song_name;
  (* new_node).artist = artist;

  return new_node;
}

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
	     

//FIX THIS, THIS DOESN'T DO WHAT I WANT IT TO DO
song_node * compare_songs(  song_node * list1,   song_node * list2){
  //return the song that is literally behind another song in the linked list.
  if (strcmp((* list1).artist, (* list2).artist) < 0){
    return list1;
  } 
  else if(strcmp((* list1).artist, (* list2).artist) > 0){
    return list2;
  }
  else{
    if(strcmp((* list1).name, (* list2).name) < 0){
      return list1; 
    }
    else{
      return list2;
    }
  }
  
  return NULL; 
}

song_node * insert_order(  song_node * list, char song_name[], char artist[]){
  int cmp = strcmp(list->artist, artist);
  song_node * temp = (song_node *)malloc(sizeof(song_node));
  
  
}




song_node* free_list(  song_node * list){
  song_node * tmp; 
  while(list){
    tmp = (*list).next;
    free(list);
    list = tmp; 
  }

  return list; 
}





int main(){
  song_node * new_list = NULL;

}
