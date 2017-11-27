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
	this->timesPlayed = ++timesPlayed;
	return;
}