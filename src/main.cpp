#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

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
    
    return 0;
}
