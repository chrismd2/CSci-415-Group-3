#include "Globals.cpp"

#include <iostream>
using namespace std;

class PasswordVerification{
public:
    PasswordVerification();
};

PasswordVerification::PasswordVerification(){
    if(DEBUG){cout << "PasswordVerification made\n";}
}
