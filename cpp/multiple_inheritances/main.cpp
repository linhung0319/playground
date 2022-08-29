#include <iostream>
#include "Cat.h"
using namespace std;

int main()
{
// We use virtual inheritance to avoid diamond problem.

// The order of calling the class is
// Animal -> Mammal -> Pet -> CannotFly -> CannotSwim.
// Even if we placed Pet before CannotFly and CannotSwim
// when we declared Cat, C++ traced the grandparent of 
// Cat first.
    Cat cat;
}