#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "LayerCake.h"
   
LayerCake::LayerCake(string flavor, string frosting, int numLayers) {
   ostringstream ostream;
   price = LAYERCAKEPRICE;
   if(frosting == "cream-cheese") {
      price = LAYERCAKEPRICE + (1.00 * numLayers);
   }
   if(numLayers > 1) {
      price = price + (3.00 * numLayers);
   }

   ostream << numLayers << "-layer " << flavor << " cake with " << frosting;
   ostream << "frosting " << BakedGood::ToString();
   description = ostream.str();
}

string LayerCake::ToString() {
   return description;
}

double LayerCake::DiscountedPrice(int numGoods) {
   
}