#ifndef CANNOTFLY_H
#define CANNOTFLY_H

#include <string>
#include "Mammal.h"
using namespace std;

// Use virtual inheritance to avoid diamond problem
class CannotFly:virtual public Mammal{
public:
    CannotFly(string name);
};

#endif