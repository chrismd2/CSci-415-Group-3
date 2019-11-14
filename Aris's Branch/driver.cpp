

#include "md5.h"
#include "pwmanager.h"

int main(int argc, char** argv)
{

    pwmanager manager = pwmanager();
    if (argc > 1)
        for (int i = 1; i < argc; i++)
        {
            if (argv[i][0] == '-' && argv[i][1] == 'g')
                manager.generate_file();
        }

    string password;
    int uid;
    bool done = false;


    {

        cout << "Please enter a user ID you want to verify: ";
        cin >> uid;
        cout << "Please enter the user's password: ";
        cin >> password;
        manager.verify(uid, password);
    }
}