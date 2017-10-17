//Jeffrey Weng, Jensen Li
//Project 0: my_tunez
//Period 10
/*
insert front
insert nodes in order
find and return a pointer to a node based on artist and song name
find and return a pointer to the first song of an artist based on artist name
Return a pointer to random element in the list.
remove a single specified node from the list
free the entire list
*/


#include "linkedl.h"

void print_list(struct song_node * list){
  printf("list content: ");
  
  while(list){
    printf("%s,",(* list).i);
    list = list->next;
  }
  printf("\n");
}

struct song_node * insert_front(struct song_node * list, char song_name[], char artist[]){
  struct song_node * new_node = (struct song_node *)malloc(sizeof(*list));
  (* new_node).next = list;
  (* new_node).name  = song_name;
  (* new_node).artist = artist;

  return new_node;
}

struct song_node* free_list(struct song_node * list){
  struct song_node * tmp; 
  while(list){
    tmp = (*list).next;
    free(list);
    list = tmp; 
  }

  return list; 
}





int main(){
  struct song_node * new_list = NULL;

}
