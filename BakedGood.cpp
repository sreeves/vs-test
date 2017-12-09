#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
#include "BakedGood.h"

string BakedGood::ToString() {
   const int PRECISION = 2;
   ostringstream os;
	os << fixed << setprecision(PRECISION);
   os << "($" << price << ")";
   return os.str();
}