/*
Alexis Reeves, Section 02, lexinreeves@gmail.com
Description: Includes Shopping Cart class. Defines public functions for adding, removing, changing quantity, printing descriptions,
and printing total items and price. 
Done without pair programming and in Visual Studio.
Late Days: none
*/

#include <iostream>
#include <vector>
#include "ShoppingCart.h"

using namespace std;

ShoppingCart::ShoppingCart(string customerName, string date) {
   this->customerName = customerName;
   this->date = date;
}

string ShoppingCart::GetName() const {
   return this->customerName;
}

string ShoppingCart::GetDate() const {
   return this->date;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
   for(int i = 0; i < items.size(); ++i) {
      if(item.GetName() == items.at(i).GetName()) {
         cout << "Item is already in cart. Nothing added." << endl;
         return;
      }
   }
   items.push_back(item);   
   return;
}

void ShoppingCart::RemoveItem(string item) {
   for (int i = 0; i < items.size(); ++i) {
      if (item == items.at(i).GetName()) {
         items.erase(items.begin() + i);
         return;
      }
   }
   cout << "Item not found in cart. Nothing removed." << endl;
   return;
}

void ShoppingCart::ChangeQuantity(string itemName, int newQuantity) {
   bool found = false;
   for (int i = 0; i < items.size(); ++i) {
      if (itemName == items.at(i).GetName()) {
         items.at(i).SetQuantity(newQuantity);
         found = true;
         break;
      }
   }
   if (!found) {
      cout << "Item not found in cart. Nothing modified." << endl;
   }

   return;
}

void ShoppingCart::PrintDescriptions() const { 
   if (items.size() == 0) {
      cout << "Shopping cart is empty." << endl;
      return;
   }
   cout << "Item Descriptions" << endl;
   for (int i = 0; i < items.size(); ++i) {
      cout << items.at(i).GetName() << ": " << items.at(i).GetDescription() << endl;
   }

   return;
}

void ShoppingCart::NumItemsAndPrice(int& numItems, double& totalPrice) const {
   if(items.size() == 0) {
      cout << "Shopping cart is empty." << endl;
      return;
   }

   for(int i = 0; i < items.size(); ++i) {
      numItems = numItems + (items.at(i).GetQuantity());
   }

   cout << "Number of Items: " << numItems << endl << endl;
   totalPrice = 0.0;
   
   for(int i = 0; i < items.size(); ++i) {
      items.at(i).PrintCostItem();
      totalPrice = totalPrice + (items.at(i).GetPrice()) * (items.at(i).GetQuantity());
   }
  
   cout << endl << "Total: $" << totalPrice << endl;
   return;
}
