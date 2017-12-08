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
   ostream << flavor << " cupcake with " << frosting << "frosting and" << colorSprinkles;
   ostream << " sprinkles " << BakedGood::ToString();
   description = ostream.str();
}

string CupCake::ToString() {
   return description;
}

double CupCake::DiscountedPrice(int numGoods) {

}