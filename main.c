#include "music_lib.h"

int main() {

  srand(time(NULL));
  
  int i;
  song_node *table[26];
  for (i = 0; i < 26; i++) {
    table[i] = (song_node *)malloc(sizeof(song_node));
  }

  char *songname = "bro!";
  char *artist = "applecider";

  char *songname1 = "rem";
  char *artist1 = "ape";

  char *songname2 = "astral";
  char *artist2 = "apple";

  char *songname3 = "bird";
  char *artist3 = "band";

  char *songname4 = "sys";
  char *artist4 = "boy";

  char *songname5 = "girl";
  char *artist5 = "kar";

  printf("LINKED LIST TESTS\n");
  printf("================================================================\n");

  printf("TESTING insert_front\n\n");
  table[0] = insert_front(table[0], songname, artist);
  table[0] = insert_front(table[0], songname1, artist1);
  print_list(table[0]);
  table[1] = insert_front(table[1], songname3, artist3);
  printf("================================================================\n");

  printf("TESTING insert_order\n\n");
  printf("adding ARTIST: apple, SONG: astral\n");
  table[0] = insert_order(table[0], songname2, artist2); 
  print_list(table[0]);
  printf("================================================================\n");
  

  printf("\n================================================================\n");
  printf("TESTING find_song_by_artist_song\n\n");
  song_node *testsong = find_song_by_artist_song(table[0], songname, artist);
  print_list(testsong);
  printf("\n");
  testsong = find_song_by_artist_song(table[0], songname3, artist);
  print_list(testsong);
  
  printf("\n================================================================\n");
  printf("TESTING find_firstsong_by_artist\n\n");
  printf("Looking for applecider...");
  song_node *testsong1 = find_firstsong_by_artist(table[0], artist); 
  print_list(testsong1);
  printf("\n");
  printf("Looking for ban...");
  testsong1 = find_firstsong_by_artist(table[0], artist3); 
  print_list(testsong1);
  printf("================================================================\n");

  printf("\n================================================================\n");
  printf("TESTING rand_node\n\n");
  print_song_node(rand_node(table[0]));
  printf("================================================================\n");
  
  printf("\n\n================================================================\n");
  printf("MUSIC LIBRARY TESTS\n");
  printf("================================================================\n\n");

  printf("\n================================================================\n");
  printf("TESTING add_song_node\n");
  printf("adding Artist: boy, Song: sys...\n");
  add_song_node(table,songname4,artist4);
  printf("adding Artist: kar, Song: girl...\n");
  add_song_node(table,songname5,artist5);
  
  printf("\n================================================================\n");
  printf("TESTING search_song\n\n");
  printf("Looking for applecider...bro...\n");
  song_node *song3 = search_song(table, songname, artist);
  print_list(song3);
  printf("\n");
  printf("Looking for (not found)...");
  song3 = search_song(table, "not found", "not found"); 
  print_list(song3);
  printf("================================================================\n");

  printf("\n================================================================\n");
  printf("TESTING search_artist\n\n");
  song_node *song4 = search_artist(table, artist1); 
  print_list(song4);
  printf("\n");
  song4 = search_artist(table, "not found"); 
  print_list(song4);
  printf("================================================================\n");

  printf("\n================================================================\n");
  printf("TESTING print_out_letter\n\n");
  printf("printing out all 'a'\n");
  print_out_letter(table, 'a');
  printf("================================================================\n");

  printf("\n================================================================\n");
  printf("TESTING print_out_artist_songs\n\n");
  printf("printing out all songs from applecider\n");
  print_out_artist_songs(table, "applecider");
  printf("================================================================\n");

  printf("\n================================================================\n");
  printf("TESTING print_library\n\n");
  print_library(table);
  printf("================================================================\n");
  
  printf("\n================================================================\n");
  printf("TESTING remove_one_song\n\n");
  remove_one_song(table, "ape", "rem");
  printf("removing song rem by ape\n");
  print_library(table);
  printf("================================================================\n");

  printf("\n================================================================\n");
  printf("TESTING shuffle\n\n");
  shuffle(table);
  printf("================================================================\n");

  printf("\n================================================================\n");
  printf("TESTING delete_all\n\n");
  delete_all(table);
  print_out_artist_songs(table, "applecider");
  printf("printing out table...\n");
  print_library(table);
  printf("================================================================\n");
  
  return 0;
}
