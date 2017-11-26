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

