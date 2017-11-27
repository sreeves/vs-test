/*
Alexis Reeves, Section 02, lexinreeves@gmail.com
Description: Simulate a music player app where user can add songs to library, add songs to playlists, 
	list playlists, delete playlists, and delete songs.
Done without pair programming and in Visual Studio.
Freed memory in main.cpp on lines 156, 175
Late Days: none

Test Case 1: Add multiple songs and list
   Input: add, Jingle Bells, jingle bells batman smells, Silent Night, silent night holy night, STOP, list;
   Expected Output: Jingle Bells: "jingle bells batman smells", 0 play(s).
					Silent Night: "silent night holy night", 0 play(s).
   Result: Passed

Test Case 2: Create mulitple playlists and list
   Input: addp, Christmas, addp, Running, listp
   Expected Output: 0: Christmas
						  1: Running
   Result: Passed

Test Case 3: add delete a playlist
   Input: addp, Christmas, addp, Running, listp, delp, 0, listp
   Expected Output: 0: Running
   Result: Passed
*/

#include <iostream>
#include <vector>
#include "Playlist.h"
#include "Song.h"
using namespace std;

void AddToLibrary(vector<Song*>& library) {
   bool stop = false;
	Song* mySong;
	string songName;
	string firstLine;
	
	cout << "Read in Song names and first lines (type \"STOP\" when done):" << endl;
	while (!stop) {
		cout << "Song Name:" << endl;
	   getline(cin, songName);
		if (songName == "STOP") {
			break;
		}
		cout << "Song's first line:";
		getline(cin, firstLine);
		mySong = new Song(songName, firstLine);
		library.push_back(mySong);
	}

	return;
}

void ListSongs(const vector<Song*>& library, bool print) {
	
	for(int i = 0; i < library.size(); ++i) {
	   if(print) {
			cout << i << ": " << library.at(i)->GetName() << endl;
		}
		else { 
			cout << library.at(i)->GetName() << ": \"" << library.at(i)->GetLine();
			cout << "\", " << library.at(i)->GetTimesPlayed() << " play(s)." << endl;
		}
	}
}

void AddToPlaylists(vector<Playlist>& myPlaylists) {
	string name;

	cout << "Playlist name:" << endl;
	getline(cin, name);
	Playlist playList = Playlist(name); 
	myPlaylists.push_back(name);
}

void ListPlaylists(const vector<Playlist>& myPlaylists) {
	for(int i = 0; i < myPlaylists.size(); ++i) {
		cout << i << ": " << myPlaylists.at(i).GetName() << endl;
	}

	return;    
}

main() {
	string userChoice;
	Song mySongs;
	vector<Song*> library;
	vector<Playlist> myPlaylists;
	int playlistNum = 0;
	int songNum = 0;
	


	cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl;
	bool quit = false;

	do {
		cout << "Enter your selection now:" << endl;
		cin >> userChoice;

		if(userChoice == "add") {
			cin.ignore();
			AddToLibrary(library);
		}
		else if(userChoice == "list") {
			ListSongs(library, false);
		}
		else if(userChoice == "addp") {
			cin.ignore();
			AddToPlaylists(myPlaylists);
		}
		else if(userChoice == "addsp") {
			ListPlaylists(myPlaylists);
			cout << "Pick a playlist index number:" << endl;
			cin >> playlistNum;
			ListSongs(library, true);
			cout << "Pick a song index number:" << endl;
			cin >> songNum;
			myPlaylists.at(playlistNum).AddSong(library.at(songNum));
		}
		else if(userChoice == "listp") {
			ListPlaylists(myPlaylists);
		}
		else if(userChoice == "play") {
			ListPlaylists(myPlaylists);
			cout << "Pick a playlist index number:" << endl;
			cin >> playlistNum;
			cout << "Playing first lines of playlist:" << myPlaylists.at(playlistNum).GetName() << endl;
			myPlaylists.at(playlistNum).Play();
		}
		else if(userChoice == "delp") {
			ListPlaylists(myPlaylists);
			cout << "Pick a playlist index number to delete:" << endl;
			cin >> playlistNum;
			myPlaylists.erase(myPlaylists.begin() + playlistNum);
		}
		else if(userChoice == "delsp") {
			ListPlaylists(myPlaylists);
			cout << "Pick a playlist index number:" << endl;
			cin >> playlistNum;
			myPlaylists.at(playlistNum).List();
			cout << "Pick a song index number to delete:" << endl;
			cin >> songNum;
			myPlaylists.at(playlistNum).DeleteSong(songNum);

		}
		else if(userChoice == "delsl") {
			ListSongs(library, true);
			cout << "Pick a song index number:" << endl;
			cin >> songNum;
			userChoice = library.at(songNum)->GetName();
			for(int i = 0; i < myPlaylists.size(); ++i) {
				myPlaylists.at(i).Delete(userChoice);
			}
			delete library.at(songNum); //FREE MEMORY
			library.erase(library.begin() + songNum);
		}
		else if(userChoice == "options") {
			cout << "add      Adds a list of songs to the library" << endl;
			cout << "list     Lists all the songs in the library" << endl;
			cout << "addp     Adds a new playlist" << endl;
			cout << "addsp    Adds a song to a playlist" << endl;
			cout << "listp    Lists all the playlists" << endl;
			cout << "play     Plays a playlist" << endl;    
			cout << "delp     Deletes a playlist" << endl;
			cout << "delsp    Deletes a song from a playlist" << endl;
			cout << "delsl    Deletes a song from the library (and all playlists)" << endl;
			cout << "options  Prints this options menu" << endl;
			cout << "quit     Quits the program" << endl;
		}
		else if(userChoice == "quit") {
			cout << "Goodbye!";
			for(int i = 0; i < library.size(); ++ i) {
				delete library.at(i); //FREE MEMORY
			}
			quit = true;
		}
		else {
			cout << "add      Adds a list of songs to the library" << endl;
			cout << "list     Lists all the songs in the library" << endl;
			cout << "addp     Adds a new playlist" << endl;
			cout << "addsp    Adds a song to a playlist" << endl;
			cout << "listp    Lists all the playlists" << endl;
			cout << "play     Plays a playlist" << endl;
			cout << "delp     Deletes a playlist" << endl;
			cout << "delsp    Deletes a song from a playlist" << endl;
			cout << "delsl    Deletes a song from the library (and all playlists)" << endl;
			cout << "options  Prints this options menu" << endl;
			cout << "quit     Quits the program" << endl;
		}
		

	} while (!quit);




	return 0;
}
