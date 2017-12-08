#ifndef BakedGood_header
#define BakedGood_header
#include <iostream>
using namespace std;

class BakedGood {
   public:
      virtual string ToString() = 0;
      virtual double DiscountedPrice(int numGoods) = 0;
      
   protected:
      string description;
      double price;
};

#endif