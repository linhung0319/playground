#ifndef MAMMAL_H
#define MAMMAL_H

#include <string>
#include "Animal.h"
using namespace std;

class Mammal: public Animal{
public:
    Mammal(string name);
};

#endif