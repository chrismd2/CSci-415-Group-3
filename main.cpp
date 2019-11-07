#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

#include "bigint.cpp"

bigint power(bigint a,  bigint src, bigint exp){
    if(exp > 1){
        a = power(a, src, exp - 1);
    }
    a = a*src;
    return a;
}

bigint power(bigint base0, bigint exp0){
    bigint base = base0;
    bigint exp = 1;
        /**
        */
    cout << "Computing " << base0 << "^" << exp0 << endl;
    if(exp0!=1){
        exp+=1;
    }
    if(exp0 == 0){
        base = 1;
    }
        /**
        */
    cout << "\t" << exp << " - " << exp0 << " = "<< exp * exp - exp0 << endl;
    while (exp * exp <= exp0 && exp0 != 1){
        /**
        */
        cout << "\t(" << base << "^" << exp << ")^" << exp << endl;
        bigint e = exp;
        exp = exp * exp;
        for(bigint i = 0; i < exp/e; i+=1){
            base = base * base;
        /**
        */
            cout << "\t"<< i+1 << "/" << exp/e << " Base = " << base << endl;
        }
    }
        /**
        */
    cout << "\tbeforepluses\n\t" << exp << " - " << exp0 << " = " << exp + exp - exp0 << endl;
    while (exp + exp <= exp0){
        base = base * base;
        exp = exp + exp;
        /**
        */
        cout << "\t" << base0 << "^" << exp << " = " << base << endl;
        cout << "\t" << "Base = " << base << endl;
    }
        /**
        */
    cout << "\t" << exp << " - " << exp0 << " = " << exp + 1 - exp0 << endl;
    while(exp+1 <= exp0){
        base = base*base0;
        exp = exp + 1;
        /**
        */
        cout << "\t" << base0 << "^" << exp << " = " << base << endl;
        cout << "\t" << "Base = " << base << endl;
    }
    /**
    while(exp>1){
        base = base*src;
        exp = exp-1;
        cout << exp <<endl;
    }
    */


    cout << "Base = " << base << endl;
    return base;
}

bigint computeD(bigint n){
    bigint d = n - 1;
    bigint r = 1;
    bigint two = 2;
    if(n%two==0){
        d=d-d;
    }
    while(d%power(two, r) != 0){
        r = r+1;
    }

    //cout << d << "/" << two<< "^" << r << " = ";
    d = d / power(two, r);
    //cout <<d <<endl;
    return d;
}

bigint computeDPlus(bigint n, bigint r){
    int iterations = 1;
    bigint d = n - 1;
    bigint two = 2;
    if(n%two==0){
        d=d-d;
    }
    while(d%power(two, r) != 0 && r < iterations){
        r = r+1;
    }
    if(r == iterations){
        d = 0;
    }

    //cout << d << "/" << two<< "^" << r << " = ";
    d = d / power(two, r);
    //cout <<d <<endl;
    return d;
}

bigint chooseA(bigint n){
    int rando;
    int diffInt = 0;
    bigint a = rand() % 21;
    bigint m = n / INT_MAX;
    bigint diff = n - m*INT_MAX;
    while(diff > 0){
        diffInt++;
        diff-=1;
    }
    //cout <<n<<"/"<<INT_MAX<<"="<< m << endl;
    while(m>0){
        rando = rand()%INT_MAX;
        a += rando;
        m-=1;
    }
    rando = rand()%diffInt;
    a+= rando;
    if(a>n){
        a = chooseA(n);
    }
    return a;
}

bigint computeX_0(bigint n, bigint d){
    bigint a = chooseA(n);
    cout << "a: " << a << endl;
    bigint x0 = power(a, d);
    //cout << "computing " << x0 << "%n\n";
    x0 = x0%n;
    cout << "x0: "<<x0<<endl;
    return x0;
}

bigint computeXi(bigint xi, bigint n){
    xi = xi*xi;
    xi = xi%n;
    cout << "xi: " << xi << endl;
    return xi;
}

bool findPrime(int add, bigint n)
{
    int iterations = 5;
    bool isPrime = false;
    n+=add;
    if(n%2==0){
        n+=1;
    }
    if(n%5 ==0){
        n+=2;
    }
    cout<<"D("<< n <<")="<<computeD(n) << endl;

    srand(time(NULL));
    cout << "n: " << n<< endl;
    bigint x0 = computeX_0(n, computeD(n));
    if(x0 == 1 || x0 == n-1){
            isPrime = true;
    }
    bigint one = 1;
    if(x0 != 1 && x0!=n-1){
        cout << "run xi\n";
        bigint xi = computeXi(x0, n);
        if(xi == n-1){
                isPrime = true;
        }
        int r = 1;
        int i = 0;
        while (xi != 1 && xi!=0 && xi != n-1 && i < iterations && !isPrime){
            xi = computeXi(xi, n);
            if(xi == n-1){
                    isPrime = true;
            }
            r++;

            bigint dp =computeDPlus(n, r);
            //cout << "d+: "<< dp;
            if(dp <= one){
                xi = computeX_0(n, dp+1);
                if(xi == 1 || xi == n-1){
                    isPrime = true;
                }
            }
            if(r == iterations) {
                xi = computeX_0(n, dp);
                if(xi == 1 || xi == n-1){
                        isPrime = true;
                }
                i++;
                r=0;
            }
        }
    }

    switch(isPrime){
    case 0:
        cout << n << " is probably not prime.\n";
        break;
    case 1:
        cout << n << " is probably prime.\n";
    }

    return isPrime;
}

bool findPrime(bigint n)
{
    bool isPrime = false;
    int iterations = 1;

    while(!isPrime){
        isPrime = findPrime(iterations, n);
        iterations++;
    }

    return isPrime;
}


int main(){
    int ai = 2;
    int bi = 15;
    bigint a,b,c;
    a = ai;
    b = bi;
    //c = power(a, b) + 1;
    //cout << c << endl;
    //cout << INT_MAX << endl;

    bigint n;
    unsigned long ni = 1;
    /**
    while(ni > 0){
        n = power(a,b);
        ni = pow(ai, bi);
        cout << "\t" << " n: " << n << endl;
        cout << "\t" << "ni: " << ni << endl << endl;
        bi++;
        b += 1;
    }
    */

    a = a-a;
    b = b-b;

    a = 10;
    b = 99;
    n= power(a, b);
    findPrime(n);

    return 0;
}
