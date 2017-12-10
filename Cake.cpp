/*
Alexis Reeves, Section 10, lexinreeves@gmail.com
Description: Constructor for class Cake. Sets protected variables flavor and frosting. 
Done without pair programming and in Visual Studio.
Late Days: none
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "Cake.h"

Cake::Cake(string flavor, string frosting) {
   this->flavor = flavor;
   this->frosting = frosting;
}