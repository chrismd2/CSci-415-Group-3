/**---------------------------------------------------------------------------
 * @RainbowAttack.cpp
 * Class RainbowAttack (finds passwords satisfying hash values)
 * @author Sameep, Rebika, Aris, Mark Christenson
 *---------------------------------------------------------------------------
 * RainbowAttack class:  Attack the server/provider based on dictionary
 * and modifications hashed with salt values against the password file
 *---------------------------------------------------------------------------
 */

#include "Globals.cpp"
#include <iostream>
using namespace std;

class RainbowAttack{
public:
    RainbowAttack();
};

RainbowAttack::RainbowAttack(){
    if(DEBUG){cout << "RainbowAttack made\n";}
}
