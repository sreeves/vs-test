#include "ItemToPurchase.h"
ItemToPurchase::ItemToPurchase() {
   itemName = "none";
   itemPrice = 0.0;
   itemQuantity = 0;
   return;
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
