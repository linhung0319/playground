#include <iostream>
#include <string>
#include "CannotSwim.h"
using namespace std;

CannotSwim::CannotSwim(string name)
    :Mammal(name){
        cout << name << " cannot swim." << endl;
    }