#ifndef ItemToPurchase_header
#define ItemToPurchase_header

#include <string>
using namespace std;

class ItemToPurchase {
public:
   ItemToPurchase(); 
   ItemToPurchase(string itemName, string itemDescription, double itemPrice, int itemQuantity);
   string GetName();
   void SetName(string itemName);
   double GetPrice();   
   void SetPrice(double itemPrice);
   int GetQuantity();
   void SetQuantity(int itemQuantity);
   void SetDescription(string itemDescription);
   string GetDescription();
   void PrintCostItem();
   void PrintDescriptionItem();


private: 
   string itemName;
   double itemPrice;
   int itemQuantity;
   string itemDescription;
};

#endif

