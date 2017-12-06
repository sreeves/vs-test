#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "Bread.h"

Bread::Bread(string breadType) {
   ostringstream ostream;
   //this->breadType = breadType;
   ostream << breadType << " bread" << "($" << BREADPRICE << ")" << endl;
   description = ostream.str();
}

string Bread::ToString() {
   return description;
}

double Bread::DiscountedPrice(int numGoods) {
   double discountedPrice;
   const int DISCOUNTNUM = 3;
   int freeLoaves;
   freeLoaves = numGoods / DISCOUNTNUM;
   discountedPrice = (numGoods - freeLoaves) * BREADPRICE;
   return discountedPrice;
}