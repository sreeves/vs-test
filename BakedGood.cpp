#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
#include "BakedGood.h"

string BakedGood::ToString() {
   const int PRECISION = 2;
	cout << fixed << setprecision(PRECISION);
   ostringstream os;
   os << "($" << price << ")";
   return os.str();
}