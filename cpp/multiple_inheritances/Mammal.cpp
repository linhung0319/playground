#include <iostream>
#include <string>
#include "Mammal.h"
using namespace std;

Mammal::Mammal(string name):Animal(name){
    cout << name << " is a mammal." << endl;
}