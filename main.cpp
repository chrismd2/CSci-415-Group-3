#include <iostream>
#include <math.h>
#include "mapm-master/mapm-master/m_apm.h"

using namespace std;

int computeDbyPHINandE(const int&, const int&); //  If given phi n and e, will compute d
int computeDbyNandE(const int& n, const int& e); //  If given n and e, will compute d
int ComputePhiN(const int&);//  If given n will compute phi n
int ComputePhiN(const int&, const int&);//  If given p and q, will compute phi n
//  Given alpha, q, and a public key, compute the private key
int ComputePrivateKey(const int& alpha, const int & q, const int& publicKey);

int main(){
    int n = 3599;
    int e = 31;
    //cout << ComputeD(ComputePhiN(n), e);

    int p = 59;
    int q = 61;
    n = p*q;
    int phiN = ComputePhiN(n);

    int alpha = 2;
    q = 11;
    int publicKey = 3;

    MAPM num = pow(2,329);
    char numStr[256];
    num.toString(numStr, 50);
    //cout << numStr;


    static  char  obuf1[1024];
    MAPM a;               //a is uninitialized (value is undefined)
    MAPM b = "4.5e12";    //b is 4.5 trillion
    MAPM c = 3;           //c is now three
    MAPM d = 6.1;         //d is now six point one
    a = "2";
    b = a.ipow_nr(329);
    b.toIntegerString(obuf1);
    //printf("81 ^ 32 = [%s] \n",obuf1);
    cout << obuf1 << endl;

    for(int i  = 0; i <= 100; i++){
        cout << obuf1[i];
        if(i%10 == 9){
            cout <<endl;
        }
    }


    return 0;
}
int ComputePrivateKey(const int& alpha, const int & q, const int& publicKey){
    int privateKey = 1;
    int power = pow(alpha, privateKey);
    while(power % q != publicKey){
        privateKey++;
        power = pow(alpha, privateKey);
    }

    return privateKey;
}

int computeDbyNandE(const int& n, const int& e){
    return computeDbyPHINandE(ComputePhiN(n), e);
}


int computeDbyPHINandE(const int& phiN, const int& e){
    int d = phiN;
    while(e*d%phiN != 1 && d > 1){
        d--;
    }
    return d;
}

int ComputePhiN(const int& p, const int& q){
    return (p-1)*(q-1);
}

int ComputePhiN(const int& n){
    double root = sqrt(n);
    int p = root;
    while(n%p>0){
        p--;
    }
    return ComputePhiN(p, n/p);
}
