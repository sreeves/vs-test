#include <iostream>
#include <vector>
#include "ShoppingCart.h"

using namespace std;

ShoppingCart::ShoppingCart(string customerName, string date) {
   this->customerName = customerName;
   this->date = date;
}

string ShoppingCart::GetName() {
   return this->customerName;
}

string ShoppingCart::GetDate() {
   return this->date;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
   for(int i = 0; i < items.size(); ++i) {
      if(item.GetName() == items.at(i).GetName()) {
         cout << "Item is already in cart. Nothing added." << endl;
      }
   }
}
