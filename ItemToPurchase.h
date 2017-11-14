#include <string>
using namespace std;

class ItemToPurchase {
public:
   ItemToPurchase(); 
   string GetName();
   void SetName(string itemName);
   double GetPrice();   
   void SetPrice(double itemPrice);
   int GetQuantity();
   void SetQuantity(int itemQuantity);


private: 
   string itemName;
   double itemPrice;
   int itemQuantity;
};


