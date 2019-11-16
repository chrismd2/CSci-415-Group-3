#ifndef RTABLE_CPP
#define RTABLE_CPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "md5.cpp"
using namespace std;

//byte* reduce(string output, string hash){
//byte digest[16];
  //  md5 MD5 = md5(hash.c_str());
//}

int rTable(string fileName){
    std::ifstream pw_file;
    pw_file.open("passwordfile.txt");
	    std::ifstream p_file;
    p_file.open(fileName);
    int id;
    string salt;
    string hash;
	string password;
    string newHash;
    md5 MD5;
	int count=0;

    bool found = false;

    for(int i=0;i<100000;i++){
		p_file >> password;
		for(int j=0;j<100;j++)
	{
			pw_file >> id >> salt >> hash;
		MD5 = md5(password + salt);
        newHash = MD5.Print();
        if(newHash==hash)
		{
            cout << "Password with salt "<<salt<<" and hash" << hash << " was cracked successfully.\n";
			cout<<"The password is: "<<password<<"\n";
			count+=1;
        }
	}
	pw_file.close();
	pw_file.open("passwordfile.txt");

	}
	cout<<"Total number of passwords cracked: "<<count<<"\n";
    cout<<"Program has ended.\n";
	p_file.close();
    pw_file.close();
}

int main(){
    time_t startTime = time(NULL);
    double runTime;
    ofstream outputFile;
    outputFile.open("Output.txt");

    startTime = time(0);
	rTable("SmallPasswordDictionary");
    runTime = difftime(time(0), startTime);
    cout << "Time = " << runTime << endl;
    outputFile << "Time = " << runTime << endl;

    startTime = time(0);
	rTable("SmallPasswordDictionary2");
    runTime = difftime(time(0), startTime);
    cout << "Time = " << runTime << endl;
    outputFile << "Time = " << runTime << endl;

    startTime = time(0);
	rTable("LargePasswordDictionary2");
    runTime = difftime(time(0), startTime);
    cout << "Time = " << runTime << endl;
    outputFile << "Time = " << runTime << endl;
    startTime = time(0);

    startTime = time(0);
	rTable("LargePasswordDictionary3");
    runTime = difftime(time(0), startTime);
    cout << "Time = " << runTime << endl;
    outputFile << "Time = " << runTime << endl;

	rTable("LargePasswordDictionary");
    runTime = difftime(time(0), startTime);
    cout << "Time = " << runTime << endl;
    outputFile << "Time = " << runTime << endl;

    startTime = runTime;
}
#endif // RTABLE_CPP
