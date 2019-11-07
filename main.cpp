#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

try{
    #include "PasswordHasher.cpp"
    #include "PasswordVerification.cpp"
    #include "RainbowAttack.cpp"
}
catch{
    cout << "Files not found.\n";
}

const bool DEBUG = false;

int main(){
    if(DEBUG){
        cout << "Debugging mode is on\n";
    }
    
    return 0;
}
