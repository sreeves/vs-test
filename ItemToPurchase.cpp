#include "ItemToPurchase.h"
#include <iostream>

using namespace std;

ItemToPurchase::ItemToPurchase() {
   itemName = "none";
   itemPrice = 0.0;
   itemQuantity = 0;
   return;
}

ItemToPurchase::ItemToPurchase(string itemName = "none", string itemDescription = "none", double itemPrice = 0.0, int itemQuantity = 0) {
   this->itemName = itemName;
   this->itemDescription = itemDescription;
   this->itemPrice = itemPrice;
   this->itemQuantity = itemQuantity;
}

string ItemToPurchase::GetName() {
   return this->itemName;
}

void ItemToPurchase::SetName(string itemName) {
   this->itemName = itemName;
}

double ItemToPurchase::GetPrice() {
   return this->itemPrice;
} 

void ItemToPurchase::SetPrice(double itemPrice) {
   this->itemPrice = itemPrice;
}

int ItemToPurchase::GetQuantity() {
   return this->itemQuantity;
}

void ItemToPurchase::SetQuantity(int itemQuantity) {
   this->itemQuantity = itemQuantity;
}

void ItemToPurchase::SetDescription(string itemDescription) {
   this->itemDescription = itemDescription;
}

string ItemToPurchase::GetDescription() {
   return this->itemDescription;
}

void ItemToPurchase::PrintCostItem() {
   cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity * itemPrice << endl;
}

void ItemToPurchase::PrintDescriptionItem() {
   cout << itemName << ": " << itemDescription << endl;
}