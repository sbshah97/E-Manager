#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;


void newAccount();
void editAccount(int, string);

int main() {

    //Welcome Screen
    for (int i = 0 ; i < 25 ; i ++)
        printf("*");
    cout << "Hello and Welcome to E- Manager" << endl;
    cout << "Please enter your name below" << endl;

    //Inputting user's name to greet the user.
    char name[256];
    cin.getline (name,256);
    cout << "Good day to you, " << name << endl;

    //Start banking functions
    again:
    cout << "Enter any of the numbers go ahead" << endl;
    cout << "What would you like to do from the following options:" << endl;
    cout << "1. Create new account" << endl;
    cout << "2. Edit existing account" << endl;
    cout << "3. Exit" << endl;

    //Choose options
    int choice;
    int accnum;
    string pswd;
    cin >> choice;

    switch(choice) {

        //Case to create new account
        case 1:
            newAccount();
            break;


        //Case to edit existing account
        case 2:
            cout << "Enter the account number: " << endl;
            if(accnum == 123456) {
                wrongpswd:
                cout << "Enter your account's password" << endl;
                cin >> pswd;
                if (pswd == "nitk2015") {
                    editAccount(accnum,pswd);
                    }
                else {
                    cout << "Wrong Password entered" << endl;
                    cout << "Try again" << endl;
                    goto wrongpswd;
                    }
                }
            else {
                cout << "Account not found. Create a new account" << endl;
                goto again;
            }
            break;

        //Case to exit the program
        case 3:
            exit(0);

        //In case none of the options are entered
        default:
            cout << "Enter an appropriate choice" <<
            goto again;
    }

    return 0;
}

//Function to add new account
void newAccount() {
    
}

//Function to edit existing account
void existingAccount(int accnum, string pswd) {

}
