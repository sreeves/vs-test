/*
Alexis Reeves, Section 02, lexinreeves@gmail.com
Description: Runs ItemToPurchase class. Includes a constructor with default parameters. Includes Get/Set name, price, 
quanity, and description functions. Includes print cost function ad print description function. 
Done without pair programming and in Visual Studio.
Late Days: none
*/

#include "ItemToPurchase.h"
#include <iostream>

using namespace std;

ItemToPurchase::ItemToPurchase() {
   itemName = "none";
   itemPrice = 0.0;
   itemQuantity = 0;
   itemDescription = "none";
   return;
}

ItemToPurchase::ItemToPurchase(string itemName = "none", string itemDescription = "none",
                               double itemPrice = 0.0, int itemQuantity = 0) {
   this->itemName = itemName;
   this->itemDescription = itemDescription;
   this->itemPrice = itemPrice;
   this->itemQuantity = itemQuantity;
}

string ItemToPurchase::GetName() const {
   return this->itemName;
}

void ItemToPurchase::SetName(string itemName) {
   this->itemName = itemName;
}

double ItemToPurchase::GetPrice() const {
   return this->itemPrice;
} 

void ItemToPurchase::SetPrice(double itemPrice) {
   this->itemPrice = itemPrice;
}

int ItemToPurchase::GetQuantity() const {
   return this->itemQuantity;
}

void ItemToPurchase::SetQuantity(int itemQuantity) {
   this->itemQuantity = itemQuantity;
}

void ItemToPurchase::SetDescription(string itemDescription) {
   this->itemDescription = itemDescription;
}

string ItemToPurchase::GetDescription() const {
   return this->itemDescription;
}

void ItemToPurchase::PrintCostItem() const {
   cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity * itemPrice << endl;
}

void ItemToPurchase::PrintDescriptionItem() const {
   cout << itemName << ": " << itemDescription << endl;
}
