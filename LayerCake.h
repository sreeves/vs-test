/*
Alexis Reeves, Section 10, lexinreeves@gmail.com
Description: Declarations of class LayerCake. Contains protected variables numLayers, LAYERCAKEPRICE.   
Done without pair programming and in Visual Studio.
Late Days: none
*/

#ifndef LayerCake_header
#define LayerCake_header
#include <iostream>
#include "Cake.h"
using namespace std;

class LayerCake : public Cake {
public:
   LayerCake(string flavor, string frosting, int numLayers);
   string ToString() const;
   double DiscountedPrice(int numGoods);

protected:
   int numLayers;
   const double LAYERCAKEPRICE= 9.00;
};

#endif