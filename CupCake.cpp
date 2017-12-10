/*
Alexis Reeves, Section 10, lexinreeves@gmail.com
Description: Definitions of class CupCake. Constructor for CupCake instances and Functions "ToString" and "DiscountedPrice".
Done without pair programming and in Visual Studio.
Late Days: none
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "CupCake.h"

CupCake::CupCake(string flavor, string frosting, string colorSprinkles) : Cake(flavor, frosting) {
   ostringstream ostream;
   price = CUPCAKEPRICE;
   this->colorSprinkles = colorSprinkles;

   if(frosting == "cream-cheese") {
      price = CUPCAKEPRICE + .20;
   }
   ostream << flavor << " cupcake with " << frosting << " frosting and " << colorSprinkles;
   ostream << " sprinkles " << BakedGood::ToString();
   description = ostream.str();
}

string CupCake::ToString() {
   return description;
}

double CupCake::DiscountedPrice(int numGoods) {
   double discountedPrice;
   const int NUMFORLARGE = 4;
   const int NUMFORSMALL = 2;
   const double LARGEDISCOUNT = .40;
   const double SMALLDISCOUNT = .30;

   if(numGoods >= NUMFORLARGE) {
      discountedPrice = numGoods * (price - LARGEDISCOUNT);
   }
   else if(numGoods >= NUMFORSMALL) {
      discountedPrice = numGoods * (price - SMALLDISCOUNT);
   }
   else {
      discountedPrice = numGoods * price;
   }
   return discountedPrice;
}