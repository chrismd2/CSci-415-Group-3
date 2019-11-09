/**---------------------------------------------------------------------------
 * @PasswordVerification.cpp
 * Class PasswordVerification (Verifies passwords based on the hash values in the
 * password file)
 * @author Sameep, Rebika, Aris, Mark Christenson
 *---------------------------------------------------------------------------
 * PasswordVerification class:  Accepts the hash value calculated by the
 * client and compares it to the passwords
 *---------------------------------------------------------------------------
 */

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
