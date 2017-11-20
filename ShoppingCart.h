#ifndef ShoppingCart_h
#define ShoppingCart_h

#include <iostream>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart {
public:
   ShoppingCart(string customerName = "none", string date = "January 1, 2016");
   string GetName();
   string GetDate();
   void AddItem(ItemToPurchase item);
   void RemoveItem(string item);
   void ChangeQuantity(string item, int newQuantity);
   void PrintDescriptions();
   void NumItemsAndPrice(int& numItems, double& totalPrice);

private:
   string customerName;
   string date;
   vector<ItemToPurchase> items;
};

#endif