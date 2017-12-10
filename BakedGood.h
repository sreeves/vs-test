/*
Alexis Reeves, Section 10, lexinreeves@gmail.com
Description: An abstract class with declarations of two pure virtual functions - "ToString" and "DiscountedPrice".
Done without pair programming and in Visual Studio.
Late Days: none
*/
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