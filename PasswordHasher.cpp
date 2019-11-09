#include "Globals.cpp"

#include <iostream>
using namespace std;

class PasswordHasher{
public:
    PasswordHasher();
};

PasswordHasher::PasswordHasher(){
    if(DEBUG){cout << "PasswordHasher made\n";}
}
