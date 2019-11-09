#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

#include "PasswordHasher.cpp"
#include "PasswordVerification.cpp"
#include "RainbowAttack.cpp"

int main(){
    if(DEBUG){
        cout << "Debugging mode is on\n";
    }

    PasswordHasher          hasher;
    PasswordVerification    verification;
    RainbowAttack           attacker;

    return 0;
}
