//Jeffrey Weng, Jensen Li
//Project 0: my_tunez
//Period 10


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
   

song_node * insert_order(  song_node * list, char song_name[], char artist[]){
  int cmp = strcmp(list->artist, artist);
  song_node * temp = (song_node *)malloc(sizeof(song_node));
  if(cmp < 0)
    return insert_front(list,song_name,artist);
  else if (cmp == 0){
    
  }
  else {

  }
    
}

song_node * find_song_by_artist_song(song_node * list, char song_name[], char artist[]){
  
}

song_node * find_firstsong_by_artist(song_node * list, char artist[]){

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

/*
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
*/
