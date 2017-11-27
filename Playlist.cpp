/*
Alexis Reeves, Section 02, lexinreeves@gmail.com
Description: Contains public functions for class Playlist.
Done without pair programming and in Visual Studio.
Freed memory in main.cpp on lines 156, 175
Late Days: none
*/

#include <iostream>
#include <vector>
#include "Playlist.h"
using namespace std;

Playlist::Playlist(string name) {
   this->name = name;
}

string Playlist::GetName() const {
   return this->name;
}

void Playlist::AddSong(Song* songChoice) {
   list.push_back(songChoice);
   return;
}

void Playlist::Play() const {
   for(int i = 0; i < list.size(); ++i) {
      cout << list.at(i)->GetLine() << endl;
      list.at(i)->AddTimesPlayed();
   }
   return;
}

void Playlist::DeleteSong(int songChoice) {
   list.erase(list.begin() + songChoice);
   return;
}

void Playlist::List() const {
   for(int i = 0; i < list.size(); ++i) {
      cout << i << ": " << list.at(i)->GetName() << endl;
   }
   return;
}

void Playlist::Delete(string songName) {
   for(int i = 0; i < list.size(); ++i) {
      if(songName == list.at(i)->GetName()) {
         DeleteSong(i);
         --i;
      }
   }
   return;
}




