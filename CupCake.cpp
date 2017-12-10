#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "CupCake.h"

CupCake::CupCake(string flavor, string frosting, string colorSprinkles) {
   ostringstream ostream;
   price = CUPCAKEPRICE;
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