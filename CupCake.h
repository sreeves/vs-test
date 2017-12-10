/*
Alexis Reeves, Section 10, lexinreeves@gmail.com
Description: Declarations for class CupCake. Contains protected variables flavor, frosting, colorSprinkles, CUPCAKEPRICE.
Done without pair programming and in Visual Studio.
Late Days: none
*/

#ifndef CupCake_header
#define CupCake_header
#include <iostream>
#include "Cake.h"
using namespace std;

class CupCake : public Cake {
public:
   CupCake(string flavor, string frosting, string colorSprinkles);
   string ToString();
   double DiscountedPrice(int numGoods);

protected:
   string colorSprinkles;
   const double CUPCAKEPRICE = 1.95;
};

#endif