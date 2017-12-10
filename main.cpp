
/*
Alexis Reeves, Section 10, lexinreeves@gmail.com
Description: Allows user to add Bread, Cupcakes, and LayerCakes. Returns the total shopping list and price with discounts.  
Done without pair programming and in Visual Studio.
Late Days: none

Test Case 1: Add one of each item
   Input: Bread Wheat 1, Cupcake Vanilla chocolate red 1, Layer-cake Chocolate vanilla 1 1, done
   Expected Output: Totals: Quantity = 3  Total = 15.45
   Result: Passed

Test Case 2: Add one Cupcake with creamcheese frosting and one without
   Input:Cupcake Yellow cream-cheese red 1, Cupcake Chocolate chocolate blue 1, done 
	Expected Output: Totals: Quantity = 2, Total = 4.10
   Result: Passed

Test Case 3: Buy 4 wheat breads, get 1 for free
   Input: Bread Wheat 4, done
   Expected Output: Quantity = 4, Total = 13.50
   Result: Passed
	*/

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
	vector<BakedGood*> tempVector;
	int numTimesOrdered = 1;
	int totalGoods = 0;
	double total = 0.0;
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

	cout << "Invoice:" << endl;
	cout << "Baked Good" << "\t\t\t\t\t" << "Quantity \t" << "Total" << endl;

	tempVector = myVector;
	for(int i = 0; i < tempVector.size(); ++i) {
		for(int j = i + 1; j < tempVector.size(); ++j) {
			if(tempVector.at(i)->ToString() == tempVector.at(j)->ToString()) {
				++numTimesOrdered;
				tempVector.erase(tempVector.begin() + j);
				--j;
			}
		}
		cout << tempVector.at(i)->ToString() << "\t\t\t" << numTimesOrdered << "\t" << tempVector.at(i)->DiscountedPrice(numTimesOrdered) << endl;
		totalGoods = totalGoods + numTimesOrdered;
		total = total + tempVector.at(i)->DiscountedPrice(numTimesOrdered);
		numTimesOrdered = 1;
	}

	cout << "Totals" << "\t\t\t" << totalGoods << "\t\t" << total << endl;


	for(int i = 0; i < myVector.size(); ++i) {
		delete myVector.at(i);		
	}
	//free memory
	cout << "Good Bye" << endl;
	
	return 0;
}