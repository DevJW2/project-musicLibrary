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
  if(cmp < 0)
    return insert_front(list,song_name,artist);
  else if (cmp > 0){
    return insert_order(list->next,song_name,artist);
  }
  else {
    while(!strcmp(list->artist,artist)){
      if(strcmp(list->name,song_name) < 0)
	return insert_front(list,song_name,artist);
      else
	list = list->next;
    }
    return insert_front(list,song_name,artist);
  }
}
    

song_node * find_song_by_artist_song(song_node * list, char song_name[], char artist[]){
  while(list){
    if(strcmp(song_name, list->name) == 0 && strcmp(artist, list->artist)){
      return list; 
    }
    list = list->next;
  }
  
  return NULL; 
}

song_node * find_firstsong_by_artist(song_node * list, char artist[]){
  while(list){
    if(strcmp(artist, list->artist) == 0){
      return list->name; 
    }
    
  }
  return NULL; 
}

song_node * rand_node(song_node * list){
  song_node * temp = list;
  int counter = 0;
  while(temp->next){
    temp = temp->next;
    counter++;
  }
  int r = rand() % counter;
  for(r; r > 0; r--)
    list = list->next;
  return list;
}

song_node * remove_node(song_node * list, char song_name[], char artist[]){
  song_node * temp = list->next;
  if(strcmp(list->name, song_name) && strcmp(list->artist, artist))
    return list->next = temp->next;
  while (!(strcmp(temp->name, song_name) && strcmp(temp->artist, artist)) && temp->next){
    list = list->next;
    temp = temp->next;
  }
  return list->next = temp->next;
  }
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
