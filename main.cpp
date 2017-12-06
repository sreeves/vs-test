#include <iostream>
#include <string>
#include <vector>
#include "Bread.h"
#include "LayerCake.h"
#include "CupCake.h"
using namespace std;

int main () {
	string item;
	string breadType;
	int number;
	vector<BakedGood*> myVector;
	

	cout << "**Bread and Cakes Bakery**" << endl << endl;
	cout << "Enter sub-order (enter \"done\" to finish)" << endl;
	
	while(true) {
		if(item == "done") {
			break;
		}
		else{
			cout << "Sub-order:" << endl;
			cin >> item;
			if(item == "Bread") {
				cin >> breadType;
				cin >> number;
				for(int i = 0; i < number; ++i) {
					Bread* myBread = new Bread(breadType);
					myVector.push_back(myBread);
				}

			}
			else if(item == "Layer-cake") {

			}
			else if(item == "CupCake") {

			}
			else {
				cout << "ERROR BAD INPUT" << endl;
			}
		}
	}

	for(int i = 0; i < myVector.size(); ++i) {
		delete myVector.at(i);		
	}
	return 0;
}