#ifndef Bread_header
#define Bread_header
#include <iostream>
#include <string>
#include "BakedGood.h"
using namespace std;

class Bread : public BakedGood {
public:
   Bread(string breadType = "not specified", int quantity = 0);

protected:
   string breadType;
   int quantity;
   static const double breadPrice = 4.50;

};

#endif