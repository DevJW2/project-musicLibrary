//#include "linkedl.h"
#include "music_lib.h"


int main(){
  song_node *list = NULL;
  print_list(list);
	
  //printf("%d\n", list_len(list));
	
  printf("~~~~~~~~~~~~~~~~TESTING INSERT_FRONT~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  list = insert_front(list, "best", "song");
  //printf("list len: %d\n", list_len(list));
	
  list = insert_front(list, "hey", "there");
  //printf("list len: %d\n", list_len(list));
	
  list = insert_front(list, "bro", "omg");
  //printf("list len: %d\n", list_len(list));
	
  print_list(list);
	
  list = free_list(list);
  //printf("list len: %d\n", list_len(list));
  print_list(list);
	
	
  printf("~~~~~~~~~~~~~~~~TESTING INSERT_ORDER~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  list = add_song_node(list, 0, "First", "One");
  printf("%lu\n", list_len(list));
  print_list(list);
	
  list = insert_at(list, 1, "Second", "Two");
  printf("%lu\n", list_len(list));
  print_list(list);
	
  list = insert_at(list, 0, "Zeroth", "Zero");
  printf("%lu\n", list_len(list));
  print_list(list);
	
  list = insert_at(list, 2, "1.5th", "1.5");
  printf("%lu\n", list_len(list));
  print_list(list);
	
  list = insert_at(list, 1, "0.5th", "0.5");
  printf("%lu\n", list_len(list));
  print_list(list);
	
  list = insert_at(list, 0, "Zeroth", "Anotha Zero");
  printf("%lu\n", list_len(list));
  print_list(list);
	
	
  printf("~~~~~~~~~~~~~~~~TESTING INSERT_ORDER~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  list = insert_order(list, "First", "One");
  printf("list len: %lu\n", list_len(list));
  print_list(list);
	
  list = insert_order(list, "Second", "Two");
  printf("list len: %lu\n", list_len(list));
  print_list(list);
	
  list = insert_order(list, "Zeroth", "Zero");
  printf("list len: %lu\n", list_len(list));
  print_list(list);
	
  list = insert_order(list, "1.5th", "1.5");
  printf("list len: %lu\n", list_len(list));
  print_list(list);
	
  list = insert_order(list, "secoNd", "A Two");
  printf("list len: %lu\n", list_len(list));
  print_list(list);
	
  list = insert_order(list, "secoNd", "ZTwo");
  printf("list len: %lu\n", list_len(list));
  print_list(list);
	
  list = insert_order(list, "Zeroth", "ZZZero");
  printf("list len: %lu\n", list_len(list));
  print_list(list);
	
	
	
  printf("~~~~~~~~~~~~~~~~TESTING FIND FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  song_node *temp;
	
  temp = find_song_by_artist_song(list, "1.5", "bro");
  printf("artist: %s\t\tsong: %s\n", temp->artist, temp->name);
	
  temp = find_song_by_artist_song(list, "Zero", "wa");
  printf("artist: %s\t\tsong: %s\n", temp->artist, temp->name);
	
  temp = find_firstsong_by_artist(list, "Zeroth");
  printf("artist: %s\t\tsong: %s\n", temp->artist, temp->name);	
	
  temp = find_firstsong_by_artist(list, "Second");
  printf("artist: %s\t\tsong: %s\n", temp->artist, temp->name);
	
  temp = find_firstsong_by_artist(list, "sEcOnd");
  printf("artist: %s\t\tsong: %s\n", temp->artist, temp->name);
	
  printf("~~~~~~~~~~~~~~~~TESTING GET_RANDOM_SONG~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  int x;
  for (x = 0; x < 10; x++) {
    temp = rand_node(list);
    printf("artist: %s\t\tsong: %s\n", temp->artist, temp->name);
  }
	
  printf("~~~~~~~~~~~~~~~~TESTING REMOVE_NODE~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("original list\n");
  print_list(list);
	
  list = remove_node(list, 0);
  print_list(list);
	
  list = remove_node(list, 4);
  print_list(list);
	
  list = remove_node(list, 3);
  print_list(list);
	
  list = remove_node(list, 1);
  print_list(list);
	
  printf("~~~~~~~~~~~~~~~~TESTING FREE_LIST~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  list = free_list(list);
  print_list(list);
	
	
	
  printf("~~~~~~~~~~~~~~~~LIBRARY FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  song_node *library[26];
  for (x = 0; x < 26; x++) {
    library[x] = NULL;
  }
	
  printf("~~~~~~~~~~~~~~~~TESTING ADD_SONG~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  //library[0] = new_node("ahh", "song", library[0]);
	
  add_song_node("ahh", "oh no");
  add_song_node("ahh", "song");
  add_song_node("aah", "pizza");
  add_song_node("billy", "bob");
  add_song_node("babby", "waaa");
  add_song_node("billy", "hello");
	
	
  printf("~~~~~~~~~~~~~~~~TESTING PRINT_LIBRARY~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  //	print_library(library);
	
	
  printf("~~~~~~~~~~~~~~~~TESTING FIND_BY_ARTIST~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  temp = search_artist("ahh");
  print_list(temp);
	
  temp = search_artist("BabbY");
  print_list(temp);
	
  temp = search_artist("chuck");
  print_list(temp);
	
	
  printf("~~~~~~~~~~~~~~~~TESTING FIND_BY_SONG_NAME_ARTIST~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  temp = search_song("ahh", "oh no");
  print_list(temp);
	
  temp = search_song("billy", "bob");
  print_list(temp);
	
  temp = search_song("chuck", "fun");
  print_list(temp);
	
  temp = search_song("billy", "fun");
  print_list(temp);
	
	
  printf("~~~~~~~~~~~~~~~~TESTING PRINT_ALL_BY_LETTER~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  print_all_by_letter(library, 'a');
  print_all_by_letter(library, 'B');
  print_all_by_letter(library, 'x');
	
	
  printf("~~~~~~~~~~~~~~~~TESTING PRINT_ALL_BY_ARTIST~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  print_all_by_artist(library, "billy");
  print_all_by_artist(library, "babby");
  print_all_by_artist(library, "DNE");
	
	
  printf("~~~~~~~~~~~~~~~~TESTING SHUFFLE~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  //adding songs for the shuffle function
  add_song(library, "dad", "jokes");
  add_song(library, "efreet", "it's lit");
  add_song(library, "freon", "holes");
  add_song(library, "joker", "funny boi");
	
	
  shuffle(library);
  shuffle(library);
  shuffle(library);
	
	
  printf("~~~~~~~~~~~~~~~~TESTING DELETE_SONG~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  print_all_by_letter(library, 'b');
  delete_song(library, "billy", "hello");
  print_all_by_letter(library, 'b');
	
  delete_song(library, "babby", "hello");
  print_all_by_letter(library, 'b');
	
  delete_song(library, "babby", "waaa");
  print_all_by_letter(library, 'b');
	
  delete_song(library, "billy", "bob");
  print_all_by_letter(library, 'b');
	
	
  printf("~~~~~~~~~~~~~~~~TESTING DELETE_ALL_SONG~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  //print_library(library);
  //delete_all(library);
  //print_library(library);
	
  return 0;
}
