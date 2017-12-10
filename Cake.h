/*
Alexis Reeves, Section 10, lexinreeves@gmail.com
Description: Declaration of abstract class Cake. Protected variables flavor and frosting. 
Done without pair programming and in Visual Studio.
Late Days: none
*/

#ifndef Cake_header
#define Cake_header
#include <iostream>
using namespace std;
#include "BakedGood.h"

class Cake : public BakedGood {
public:
   Cake(string flavor, string frosting);

protected:
   string flavor;
   string frosting;
};

#endif