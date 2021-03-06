//Jeffrey Weng, Jensen Li
//Period 10


#include "linkedl.h"

void print_list(song_node *node) {
  while (node && node->next) {
    printf("%s -- %s | ", node->artist, node->name);
    node = node->next; // Set node equal to next node
  }
  printf("\n");
  //printf("NULL\n");
}

song_node * insert_front(  song_node * list, char *song_name, char *artist){
  song_node * new_node = (  song_node *)malloc(sizeof(*list));
  //(* new_node).next = list;

  strcpy(new_node->name, song_name);
  strcpy(new_node->artist,artist);

  new_node->next = list;
  return new_node;
}
   

song_node * insert_order(  song_node * list, char *song_name, char *artist){
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

song_node * find_song_by_artist_song(song_node * list, char *song_name, char *artist){
  while (list->next) {
    if (!strcmp(song_name, list->name) && !strcmp(artist, list->artist)) {
      printf("Found Song\n");
      return list;
    }
    list = list->next;
  }
  printf("Song not found\n");
  return list;
}


song_node * find_firstsong_by_artist(song_node * list, char *artist){
  while (list->next) {
    if (!strcmp(artist, list->artist)) {
      printf("First artist's song found!\n");
      return list;
    }
    list = list->next;
  }
  printf("Artist not found\n");
  return list;
}

song_node * rand_node(song_node * list){
  song_node * temp = list;
  int counter = 0;
  while(temp->next){
    temp = temp->next;
    counter++;
  }
  if(!counter){
    return list;
  }
  int r = rand() % counter;
  for(r; r > 0; r--)
    list = list->next;
  return list;
}


song_node * remove_node(song_node * list, char *song_name, char *artist){
  song_node * tmp;
  if(list){
    tmp = list->next;
    free(list);
    list = tmp; 
  }
  return list; 
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
