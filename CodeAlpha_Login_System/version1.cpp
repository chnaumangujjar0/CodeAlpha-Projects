#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class User
{
public:
    string userName;
    string password;

public:
    User(string userName, string password) : userName(userName), password(password) {}
};
class AuthSystem
{
private:
    vector<User> users;

public:
    string registerUser(string userName)
    {
        bool exist = true;
        string password;
        while (true)
        {

            for (User &u : users)
            {
                if (userName == u.userName)
                {
                    exist = false;
                    cout << "\n This username already exist.";
                    cout << "\n Try a different username";
                    break;
                }
            }
            if (!exist)
            {
                cout << "\n Enter User Name";
                cin >> userName;
                transform(userName.begin(), userName.end(), userName.begin(), ::tolower);
                exist = true;
            }
            else
            {
                cout << "\n Enter Password : ";
                cin >> password;
                users.push_back(User(userName, password));
                cout << "\n Account Created Successfully!";
                cout << "\n Now, You can login with username.";
                return userName;
            }
        }
    }
    bool loginUser(string userName, string password)
    {

        for (User &u : users)
        {
            if (userName == u.userName && password == u.password)
            {

                return true;
            }
        }

        return false;
    }
    void displayUsers()
    {
        int id = 0;
        for (User &u : users)
        {
            id++;
            cout << "\n ID : " << id;
            cout << "\n User Name : " << u.userName;
            cout << "\n --------------------";
        }
    }
};
int main()
{
    AuthSystem s;
    string userName;
    string password;
    bool isLoggedIn = false;
    cout << " ------- Login System -------";

    while (true)
    {
        if (!isLoggedIn)
        {
            int choice;
            cout << "\n 1. Login";
            cout << "\n 2. Sign Up";
            cout << "\n 3. Display Users";
            cout << "\n Enter Choice : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "\n Enter User Name : ";
                cin >> userName;
                transform(userName.begin(), userName.end(), userName.begin(), ::tolower);
                cout << "\n Enter Password : ";
                cin >> password;
                if (s.loginUser(userName, password))
                {
                    isLoggedIn = true;
                }
                else
                {
                    cout << "\n Incorrect exist name or password!";
                }
                break;
            case 2:
                cout << "\n User Name must contain letter and numbers.";
                cout << "\n Enter User Name : ";
                cin >> userName;
                transform(userName.begin(), userName.end(), userName.begin(), ::tolower);
                userName = s.registerUser(userName);
                break;
            case 3:
                s.displayUsers();
                break;
            default:
                cout << "\n Invalid Choice!";
                break;
            }
        }
        else
        {
            cout << "\n Welcome! " << userName;
            cout << "\n Now, You are logged in.";
            int choice;
            cout << "\n 1. logout";
            cout << "\n 2. Exit";
            cout << "\n Enter choice : ";
            cin >> choice;
            if (choice == 1)
            {
                cout << "\n Logged out Successfully!";
                isLoggedIn = false;
            }
            else
            {
                cout << "\n Exited!";
                return 0;
            }
        }
    }

    return 0;
}