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

private: 
   vector<Song*> list;
   string name;
        

};
#endif
