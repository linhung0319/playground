#include <iostream>
#include <string>
#include "CannotFly.h"
using namespace std;

CannotFly::CannotFly(string name)
    :Mammal(name){
        cout << name << " cannot fly." << endl;
    }