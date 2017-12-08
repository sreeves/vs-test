#ifndef LayerCake_header
#define LayerCake_header
#include <iostream>
#include "Cake.h"
using namespace std;

class LayerCake : public Cake {
public:
   LayerCake(string flavor, string frosting, int numLayers);
   string ToString();
   double DiscountedPrice(int numGoods);

protected:
   string flavor;
   string frosting;
   int numLayers;
   const double LAYERCAKEPRICE= 9.00;
};

#endif