#include <iostream>
#include <string>
#include "Cat.h"
#include "Mammal.h"
using namespace std;

// In general, it is not allowed to call 
// the grandparent’s constructor directly, 
// it has to be called through parent class. 
// It is allowed only when ‘virtual’ keyword is used.
Cat::Cat()
    :Pet("Cat"), CannotFly("Cat"), CannotSwim("Cat"), Mammal("Cat"){
        cout << "I am a cat. Meow~" << endl;
    }