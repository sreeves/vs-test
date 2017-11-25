/*
Alexis Reeves, Section 02, lexinreeves@gmail.com
Description: Header file for itemToPurchase class. Includes private variables item name, price, quantity, and description.
Declaration for public functions.  
Done without pair programming and in Visual Studio.
Late Days: none
*/

#ifndef ItemToPurchase_header
#define ItemToPurchase_header

#include <string>
using namespace std;

class ItemToPurchase {
public:
   ItemToPurchase(); 
   ItemToPurchase(string itemName, string itemDescription, double itemPrice, int itemQuantity);
   string GetName() const;
   void SetName(string itemName);
   double GetPrice() const;   
   void SetPrice(double itemPrice);
   int GetQuantity() const;
   void SetQuantity(int itemQuantity);
   void SetDescription(string itemDescription);
   string GetDescription() const;
   void PrintCostItem() const;
   void PrintDescriptionItem() const;

private: 
   string itemName;
   double itemPrice;
   int itemQuantity;
   string itemDescription;
};

#endif

