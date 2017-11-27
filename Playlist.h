/*
Alexis Reeves, Section 02, lexinreeves@gmail.com
Description: Defines Playlist class. Provides ability to add and delete songs in a playlist. 
Done without pair programming and in Visual Studio.
Freed memory in main.cpp on lines 156, 175
Late Days: none
*/

#ifndef Playlist_h
#define Playlist_h

#include <iostream>
#include <vector>
#include "Song.h"
using namespace std;

class Playlist {
public:
   Playlist(string name = "none");
   string GetName() const;
   void AddSong(Song* songChoice);
   void Play() const;
   void List() const;
   void DeleteSong(int songChoice);
   void Delete(string songName);

private: 
   vector<Song*> list;
   string name;
};
#endif
