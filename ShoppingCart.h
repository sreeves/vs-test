#include <iostream>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart {
public:
   ShoppingCart(string customerName = "none", string date = "January 1, 2016");
   string GetName();
   string GetDate();
   void AddItem(ItemToPurchase);

private:
   string customerName;
   string date;
   vector<ItemToPurchase> items;
};