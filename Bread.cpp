#include <iostream>
#include <string>
using namespace std;
#include "Bread.h"

Bread::Bread(string breadType, int quantity) {
   this->breadType = breadType;
   this->quantity = quantity;
}