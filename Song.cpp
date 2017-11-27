/*
Alexis Reeves, Section 02, lexinreeves@gmail.com
Description: Contains public functions for Song class. 
Done without pair programming and in Visual Studio.
Freed memory in main.cpp on lines 156, 175
Late Days: none
*/

#include <iostream>
#include "Song.h"
using namespace std;

Song::Song(string songName, string firstLine) {
	this->songName = songName;
	this->firstLine = firstLine;
	timesPlayed = 0;
}

string Song::GetName() const {
	return this->songName;
}

string Song::GetLine() const {
	return this->firstLine;
}

int Song::GetTimesPlayed() const {
	return this->timesPlayed;
}

void Song::AddTimesPlayed() {
	this->timesPlayed++;
	return;
}