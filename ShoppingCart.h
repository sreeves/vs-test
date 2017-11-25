/*
Alexis Reeves, Section 02, lexinreeves@gmail.com
Description: Header file for class Shopping Cart. Includes private variables customerName, date, and, items. Declares public
functions get name/date, add item, remove item, change quantity, print descriptions, and get number of items and the total price.  
Done without pair programming and in Visual Studio.
Late Days: none
*/

#ifndef ShoppingCart_h
#define ShoppingCart_h

#include <iostream>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart {
public:
   ShoppingCart(string customerName = "none", string date = "January 1, 2016");
   string GetName() const;
   string GetDate() const;
   void AddItem(ItemToPurchase item);
   void RemoveItem(string item);
   void ChangeQuantity(string item, int newQuantity);
   void PrintDescriptions() const;
   void NumItemsAndPrice(int& numItems, double& totalPrice) const;

private:
   string customerName;
   string date;
   vector<ItemToPurchase> items;
};

#endif
