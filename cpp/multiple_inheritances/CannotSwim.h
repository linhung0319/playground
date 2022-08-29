#ifndef CANNOTSWIM_H
#define CANNOTSWIM_H

#include <string>
#include "Mammal.h"
using namespace std;

// Use virtual inheritance to avoid diamond problem
class CannotSwim:virtual public Mammal{
public:
    CannotSwim(string name);
};

#endif