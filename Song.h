#ifndef Song_h
#define Song_h

#include <iostream>
#include <vector>
#include <string>
#include "Playlist.h"
using namespace std;

class Song {
public:
    Song(string songName = "none", string firstLine = "none");
    string GetName() const;
    string GetLine() const;
    int GetTimesPlayed() const;

private: 
    string songName;
    string firstLine;
    int timesPlayed;
};
#endif