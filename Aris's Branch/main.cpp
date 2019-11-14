#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <time.h>

#include "rtable.cpp"
#include "md5.h"
#include "pwmanager.h"
#include "bigint.cpp"

using namespace std;

bigint power(bigint base0, bigint exp0){
    bigint base = 1;
    for(bigint i = 0; i<exp0; i+=1){
        base *= base0;
    }
    return base;
}

string salt(){
    string salt;
    int iSalt;

    for(int i = 0; i < 6; i++){
        iSalt = rand()%(125-33)+33;
        salt += (char)iSalt;
    }
    return salt;
}

void iteratorSalt(string fileName, string password){
    string Salt = "000000";
    int iSalt;
    ofstream file;
    file.open(fileName, ios_base::app);

    for(int i = 0; i < 6; i++){
        iSalt = 0;
        for(bigint j = 0; j < 92; j+=1){
            iSalt++;
            Salt[i] =(char)(iSalt + 33);
            md5 aHash(Salt + password);
            file << aHash;
            file << "~";
        }
    }
    file << "\n";
}

int main(){
    srand(time(0));
    string str;
    bigint passwordCount = 100000;
    bigint divisor = 6;
    bigint portionStart, endPoint;
    bigint workCount = passwordCount/divisor;

    if(true){
        ifstream RainbowPortion;
        RainbowPortion.open("Count.txt");
        getline(RainbowPortion, str);
        portionStart = str;
    }
    endPoint = portionStart + workCount;

    if(true){
        ofstream RainbowPortion;
        RainbowPortion.open("Count.txt");
        RainbowPortion << portionStart + endPoint;
    }

    cout << portionStart << " - " << endPoint << endl;
    string filename = "RainbowPortion-";
    string tempString = "";

    int iteration = 0;
    for(bigint i = 0; i < portionStart/workCount; i+=1){
        iteration++;
    }

    tempString = to_string(iteration);
    filename+=tempString;
    filename+=".txt";
    ofstream RainbowPortion;
    RainbowPortion.open(filename);

    string Salt = salt();
    string Password = salt();

    md5 hashCode(Salt + Password);

    cout << "H(" << Password << ", " << Salt << ") = " <<hashCode << endl;

    ifstream passFile;
    passFile.open("LargePasswordDictionary");
    for(bigint i = 0; i < portionStart; i+=1){
        getline(passFile, Password);
    }
    for(bigint j = 0; j < workCount; j+=1){
        iteratorSalt(filename, Password);
        getline(passFile, Password);
    }

    RainbowPortion.close();
    passFile.close();

    return 0;
}
