#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

class User
{
public:
    string userName;
    string password;

    User(string userName, string password) : userName(userName), password(password) {}
};

class AuthSystem
{
public:
    string registerUser(string userName)
    {
        bool exist = true;
        string fileUser, filePassword;
        string password;

        while (true)
        {
            ifstream infile("database.txt");

            if (infile.is_open())
            {
                exist = true;

                while (infile >> fileUser >> filePassword)
                {
                    if (fileUser == userName)
                    {
                        exist = false;
                        cout << "\nThis user already exists!";
                        cout << "\nTry a different username.";
                        break;
                    }
                }
                infile.close();
            }

            if (!exist)
            {
                cout << "\nEnter User Name : ";
                cin >> userName;
                transform(userName.begin(), userName.end(), userName.begin(), ::tolower);
            }
            else
            {
                ofstream file("database.txt", ios::app);

                cout << "\nEnter Password : ";
                cin >> password;

                if (file.is_open())
                {
                    file << userName << " " << password << endl;
                    file.close();
                }

                cout << "\nAccount Created Successfully!";
                cout << "\nNow, You can login with username.";
                return userName;
            }
        }
    }

    bool loginUser(string userName, string password)
    {
        string fileUser, filePassword;

        ifstream infile("database.txt");

        if (infile.is_open())
        {
            while (infile >> fileUser >> filePassword)
            {
                if (fileUser == userName)
                {
                    if (filePassword == password)
                    {
                        infile.close();
                        return true;
                    }
                }
            }
            infile.close();
        }

        return false;
    }

    void displayUsers()
    {
        string line;
        ifstream infile("database.txt");

        if (infile.is_open())
        {
            while (getline(infile, line))
            {
                cout << "\n"
                     << line;
            }
            infile.close();
        }
    }
};

int main()
{
    AuthSystem s;
    string userName;
    string password;
    bool isLoggedIn = false;

    cout << "------- Login System -------";

    while (true)
    {
        if (!isLoggedIn)
        {
            int choice;
            cout << "\n1. Login";
            cout << "\n2. Sign Up";
            cout << "\n3. Display Users";
            cout << "\nEnter Choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "\nEnter User Name : ";
                cin >> userName;
                transform(userName.begin(), userName.end(), userName.begin(), ::tolower);

                cout << "\nEnter Password : ";
                cin >> password;

                if (s.loginUser(userName, password))
                {
                    isLoggedIn = true;
                }
                else
                {
                    cout << "\nIncorrect User name or password!";
                }
                break;

            case 2:
                cout << "\nUser Name must contain letters and numbers.";
                cout << "\nEnter User Name : ";
                cin >> userName;
                transform(userName.begin(), userName.end(), userName.begin(), ::tolower);

                userName = s.registerUser(userName);
                break;

            case 3:
                s.displayUsers();
                break;

            default:
                cout << "\nInvalid Choice!";
                break;
            }
        }
        else
        {
            cout << "\nWelcome! " << userName;
            cout << "\nNow, You are logged in.";

            int choice;
            cout << "\n1. Logout";
            cout << "\n2. Exit";
            cout << "\nEnter choice: ";
            cin >> choice;

            if (choice == 1)
            {
                cout << "\nLogged out Successfully!";
                isLoggedIn = false;
            }
            else
            {
                cout << "\nExited!";
                return 0;
            }
        }
    }

    return 0;
}