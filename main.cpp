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

void List(const vector<Song*>& library) {
    
    for(int i = 0; i < library.size(); ++i) {
        cout << library.at(i)->GetName() << ": \"" << library.at(i)->GetLine() << "\", " << library.at(i)->GetTimesPlayed() << " play(s)." << endl;
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
            List(library);
        }
        else if(userChoice == "addp") {
            cin.ignore();
            AddToPlaylists(myPlaylists);
        }
        else if(userChoice == "addsp") {
        
        }
        else if(userChoice == "listp") {
            ListPlaylists(myPlaylists);
        }
        else if(userChoice == "play") {

        }
        else if(userChoice == "delp") {

        }
        else if(userChoice == "delsp") {

        }
        else if(userChoice == "delsl") {

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
                delete library.at(i);
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
