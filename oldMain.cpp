/**---------------------------------------------------------------------------
 * @main.cpp
 * Class Grid (manages a zipcode's grid information)
 * @author Sameep, Rebika, Aris, Mark Christenson
 *---------------------------------------------------------------------------
 * main file:  Runs the classes for the password management and attacks
 *---------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

#include "PasswordHasher.cpp"
#include "PasswordVerification.cpp"
#include "RainbowAttack.cpp"

int main(){
    if(DEBUG){cout << "Debugging mode is on\n";}

    PasswordHasher          hasher;
    PasswordVerification    verification;
    RainbowAttack           attacker;

    //This instance looks good because its length is longer than the hash length
    hasher.run("Set field width Sets the field width to be used on output operations. Behaves as if member width were called with n as argument on the stream on which it is inserted/extracted as a manipulator (it can be inserted/extracted on input streams or output streams).This manipulator is declared in header <iomanip>.");

    //This instance demonstrates the need to establish the function to handle the smaller hash values
    hasher.run("qwerty");

    return 0;
}
