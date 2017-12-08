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
   string flavor;
   string frosting;
   string colorSprinkles;
   const double CUPCAKEPRICE = 1.95;
};

#endif