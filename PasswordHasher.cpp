/**---------------------------------------------------------------------------
 * @PasswordHasher.cpp
 * Class PasswordHasher (Hashes passwords)
 * @author Sameep, Rebika, Aris, Mark Christenson
 *---------------------------------------------------------------------------
 * PasswordHasher class:  Client machine should run this program and output
 * a hash value based on the salt value and the provided password
 *---------------------------------------------------------------------------
 */

#include "Globals.cpp"

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <iomanip>

using namespace std;

class PasswordHasher{
private:
    vector <int> password;              /**< ASCII values of password */
    int hashCode[HASHCHARACTERCOUNT];   /**< Running hash values */
    string hashString;                  /**< Hash values as chars in this string */
    void fillPassVector(string);
    void showPassVector();
    void runHash();
    void processHash();
    void clearValues();

public:
    PasswordHasher();
    void run(string);
};

/** Default constructor
 *  @pre None
 *  @post PasswordHasher object is made, outputs a debug message
 */
PasswordHasher::PasswordHasher(){
    if(DEBUG){cout << "PasswordHasher made\n";}

    clearValues();
}

/** Run method
 *  @pre Provide a string
 *  @post This function is intended to run all functionality of the PasswordHasher for the user
 */
void PasswordHasher::run(string _password){
  fillPassVector(_password);
  for(int i = _password.length()% HASHCHARACTERCOUNT; i > 0; i++){
    password.push_back(_password[_password.length() - i]);
  }
  if(DEBUG){showPassVector();}
  runHash();
  processHash();
  clearValues();
}

/** ClearValues method
 *  @pre None
 *  @post Empties password, hashCode, and hashString
 */
void PasswordHasher::clearValues(){
    while(password.size() > 0){
        password.pop_back();
    }

    for(int i = 0; i < HASHCHARACTERCOUNT; i ++){
        hashCode[i] = 0;
    }

    hashString = "";
}

/** ProcessHash method
 *  @pre None
 *  @post Fill the hash string characters associated with the hash values
 */
void PasswordHasher::processHash(){
    hashString = "";
    for(int i = 0; i < HASHCHARACTERCOUNT; i++){
        hashString += (char)hashCode[i];
    }
    if(DEBUG){
        cout << "Hash String: " << hashString << endl;
        cout << "Hash String Length: " << hashString.length() << endl;
    }
}

/** RunHash method
 *  @pre None
 *  @post Transform password vector values into their hashed values
 */
void PasswordHasher::runHash(){
    unsigned int index = 0;

    for(int i = 0; i < 1000; i++){
        if(index < password.size()){
            switch(index%4){
            case 0:
                if(DEBUG){cout  << "Hashing\n\t"
                                << "NextPassChar:\t\t" << password[index] << "\n\t"
                                << "CurrentHashChar:\t" << hashCode[index%HASHCHARACTERCOUNT] << "\n\t"
                                << "Equation: C ^ N =\t" << (password[index] ^ hashCode[index%HASHCHARACTERCOUNT]) << "\n";}
                hashCode[index%HASHCHARACTERCOUNT] = password[index] ^ hashCode[index%HASHCHARACTERCOUNT];
                break;
            case 1:
                if(DEBUG){cout  << "Hashing\n\t"
                                << "NextPassChar:\t\t" << password[index] << "\n\t"
                                << "CurrentHashChar:\t" << hashCode[index%HASHCHARACTERCOUNT] << "\n\t"
                                << "Equation: C ^ N =\t" << (password[index] ^ hashCode[index%HASHCHARACTERCOUNT]) << "\n";}
                hashCode[index%HASHCHARACTERCOUNT] = password[index] ^ hashCode[index%HASHCHARACTERCOUNT];
                break;
            case 2:
                if(DEBUG){cout  << "Hashing\n\t"
                                << "NextPassChar:\t\t" << password[index] << "\n\t"
                                << "CurrentHashChar:\t" << hashCode[index%HASHCHARACTERCOUNT] << "\n\t"
                                << "Equation: C ^ N =\t" << (password[index] ^ hashCode[index%HASHCHARACTERCOUNT]) << "\n";}
                hashCode[index%HASHCHARACTERCOUNT] = password[index] ^ hashCode[index%HASHCHARACTERCOUNT];
                break;
            case 3:
                if(DEBUG){cout  << "Hashing\n\t"
                                << "NextPassChar:\t\t" << password[index] << "\n\t"
                                << "CurrentHashChar:\t" << hashCode[index%HASHCHARACTERCOUNT] << "\n\t"
                                << "Equation: C ^ N =\t" << (password[index] ^ hashCode[index%HASHCHARACTERCOUNT]) << "\n";}
                hashCode[index%HASHCHARACTERCOUNT] = password[index] ^ hashCode[index%HASHCHARACTERCOUNT];
                break;
            default:
                if(DEBUG){cout << "Undefined case in PasswordHasher.runHash()'s switch statement.\n";}
                break;
            }

            index++;
        }
    }
}

/** fillPassVector
 *  @pre Provide a string
 *  @post Fills the password vector with the ASCII values for characters in the password
 */
void PasswordHasher::fillPassVector(string _password){
  for(int i = 0; i < _password.length(); i++){
    password.push_back((int)_password[i]);
  }
}

/** showPassVector
 *  @pre None
 *  @post Shows the values in the password vector
 */
void PasswordHasher::showPassVector(){
  for (int i = 0; i < password.size(); i++){
    cout << password[i] << " ";
  }
  cout << endl;
}
