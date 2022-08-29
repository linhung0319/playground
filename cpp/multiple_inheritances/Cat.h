#ifndef CAT_H
#define CAT_H

#include "CannotFly.h"
#include "CannotSwim.h"
#include "Pet.h"

class Cat:public Pet, public CannotFly, public CannotSwim{
public:
    Cat();
};

#endif