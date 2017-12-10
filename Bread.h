/*
Alexis Reeves, Section 10, lexinreeves@gmail.com
Description: Declaration of class Bread. Contains protected variables breadType and BREADPRICE.
Done without pair programming and in Visual Studio.
Late Days: none
*/

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
   string ToString() const;
   double DiscountedPrice(int numGoods);

protected:
   string breadType;
   const double BREADPRICE = 4.50;

};

#endif