#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Bread.h"
#include "LayerCake.h"
#include "CupCake.h"
using namespace std;

int main () {
	string item;
	string breadType;
	string flavor;
	string frosting;
	string sprinkleColor;
	int numLayers;
	int number;
	vector<BakedGood*> myVector;
	const int PRECISION = 2;
	
	
	cout << fixed << setprecision(PRECISION);
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
				cin >> flavor;
				cin >> frosting;
				cin >> numLayers;
				cin >> number;
				for(int i = 0; i < number; ++i) {
					LayerCake* myLayerCake = new LayerCake(flavor, frosting, numLayers);
					myVector.push_back(myLayerCake);
				}

			}
			else if(item == "Cupcake") {
				cin >> flavor;
				cin >> frosting;
				cin >> sprinkleColor;
				cin >> number;
				for(int i = 0; i < number; ++i) {
					CupCake* myCupCake = new CupCake(flavor, frosting, sprinkleColor);
					myVector.push_back(myCupCake);
				}
				
			}
			else {
				//cout << "ERROR BAD INPUT" << endl;
			}
		}
	}

	cout << "Order Confirmations:" << endl;
	for(int i = 0; i < myVector.size(); ++i) {
		cout << myVector.at(i)->ToString() << endl;
	}

	for(int i = 0; i < myVector.size(); ++i) {
		delete myVector.at(i);		
	}

	
	return 0;
}