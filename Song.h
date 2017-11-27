/*
Alexis Reeves, Section 02, lexinreeves@gmail.com
Description: Defines Song class. Provides ability to store a song. 
Done without pair programming and in Visual Studio.
Freed memory in main.cpp on lines 156, 175
Late Days: none
*/

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
