#ifndef PWMANAGER
#define PWMANAGER

#include <fstream>
#include <iostream>
#include <sstream>

using std::cin;
using std::cout;
using std::string;

class pwmanager
{
public:
    int filesize;
    pwmanager();
    void generate_file();
    void verify(int uid, string password);


private:

};

#endif