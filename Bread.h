#ifndef Bread_header
#define Bread_header
#include <iostream>
#include <string>
#include <sstream>
#include "BakedGood.h"
using namespace std;

class Bread : public BakedGood {
public:
   Bread(string breadType = "not specified");
   string ToString();
   double DiscountedPrice(int numGoods);

protected:
   string breadType;
   const double BREADPRICE = 4.50;


};

#endif