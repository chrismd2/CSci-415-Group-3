
#include "pwmanager.h"
#include "md5.h"

pwmanager::pwmanager()
{
    filesize=99;
    
}

void pwmanager::generate_file()
{
    srand(time(NULL));
    std::ifstream source;
    std::ofstream pw_file;
    source.open("passwordlist");

    pw_file.open("passwordfile.txt");

    int salt;
    int uid;
    string password;

    md5 MD5;
    std::stringstream stream;
    for (int i = 1; i <= filesize; i++)
    {
        salt = rand() + i;
        stream << salt;
        source >> password;

        uid = i;
        pw_file << uid << " " << salt << " ";
        MD5 = md5(password.c_str() + stream.str());
        pw_file << MD5 << "\n";
        pw_file.flush();
        //cout << "User " << i << "'s password: " << password << " Salt: "<< salt << " Hash: " << MD5 << "\n";
    }
    source.close();
    pw_file.close();
}

void pwmanager::verify(int uid, string password)
{
    std::ifstream pw_file;
    pw_file.open("passwordfile.txt");
    int id;
    string salt;
    string hash;
    string newHash;
    md5 MD5;
    bool found = false;

    while(!found){
        pw_file >> id >> salt >> hash;
        if(id==uid){
            found=true;
            cout << "User " << uid << " was found in file.\n\n";
        }
    }

    if(found)
    {
        MD5 = md5(password.c_str() + salt);
        newHash = MD5.Print();
        cout<<"User's info: \n";
	cout << "ID: " << id << "   salt: " << salt << "   hash: " << hash << '\n';

        //cout << id  << " " << salt  << " " << hash << "\n";
        //check if generated hash matches file hash.
        cout << "Password and Salt hashing " << password << "+" << salt << " : " << newHash << "\n\n";
        if (!newHash.compare(hash))
        {
            
            cout << "User " << uid << " password was verified successfully!\n";
        }
        else
        {
            cout << "User was not verified\n";
        }
        
    }
    else
    {
        cout << "User was not found, Please try again!\n";
    }
    pw_file.close();

}