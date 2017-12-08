#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
#include "Bread.h"

Bread::Bread(string breadType) {
   ostringstream os;
   const int PRECISION = 2;
	cout << fixed << setprecision(PRECISION);
   price = BREADPRICE;
   //this->breadType = breadType;
   os << breadType << " bread " << BakedGood::ToString();
   description = os.str();
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