#ifndef RTABLE_CPP
#define RTABLE_CPP

#include <iostream>
#include <fstream>
#include <sstream>
#include "md5.cpp"
using namespace std;

//byte* reduce(string output, string hash){
//byte digest[16];
  //  md5 MD5 = md5(hash.c_str());
//}

int rTable(){
    std::ifstream pw_file;
    pw_file.open("passwordfile.txt");
	    std::ifstream p_file;
    p_file.open("LargePasswordDictionary");//100000 most used passwords
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
#endif // RTABLE_CPP
