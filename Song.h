#ifndef Song_h
#define Song_h

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Song {
public:
    Song(string songName = "none", string firstLine = "none");
    string GetName() const;
    string GetLine() const;
    int GetTimesPlayed() const;
    void AddTimesPlayed();

private: 
    string songName;
    string firstLine;
    int timesPlayed;
};
#endif
