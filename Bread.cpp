/*
Alexis Reeves, Section 10, lexinreeves@gmail.com
Description: Definitions of class Bread. Constructor for Bread  instances and Functions "ToString" and "DiscountedPrice".
Done without pair programming and in Visual Studio.
Late Days: none
*/

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
   os << breadType << " bread " << BakedGood::ToString(); //CALL TO BASE CLASS
   description = os.str();
}

string Bread::ToString() const {
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