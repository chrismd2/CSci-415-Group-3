#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

#include "PasswordHasher.cpp"
#include "PasswordVerification.cpp"
#include "RainbowAttack.cpp"

const bool DEBUG = true;

int main(){
    if(DEBUG){
        cout << "Debugging mode is on\n";
    }

    return 0;
}
