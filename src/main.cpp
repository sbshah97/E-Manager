#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<fstream>
#include<string>
using namespace std;

class acc {
    private:
        long int accnum1;
        string pswd1;
        int cash1;
    public:
        //void get_data();
        //void display_data(); //only for debugging

void get_data() {

        //Input cash nad password from user
        cout<<"Enter cash to deposit initially (min 500):";
        cin>>cash1;
        cout<<"Enter your account password:";
        cin>>pswd1;

        //Generating account no
        ifstream f;
        f.open("Acc_no.txt",ios::in);
        int i;
        f>>accnum1;
        accnum1++;
        f.close();

        //Outputting account number
        ofstream f1;
        f1.open("Acc_no.txt",ios::out);
        f1 << accnum1;
        f1.close();

        cout << "Account no generated:" << accnum1 << endl;

        cout << "Account created successfully";
    }

void display_data() {
    ifstream f2;
    f2.open("bankaccounts.txt",ios::in);

    while(f2.read((char*)this,sizeof(this))){   //f2.read((char*)&n,sizeof(n));
        cout<<endl<<"Account number:"<<this->accnum1<<" ";
        cout<<"Cash in account:"<<this->cash1;
        }
    f2.close();

    }

}n;

void newAccount();
void editAccount(int, string);

void admin(int, string);
void client(int, string);

char name[256];

void welcome();
void bank_display();

void bank_functions(int);

int main() {

    welcome();

    //Inputting user's name to greet the user.

    cin.getline (name,256);
    cout << "Good day to you, " << name << endl;
    printf("\n");

    //Start banking functions
    bank_display();

    //Choose options
    int choice;
    int accnum;
    string pswd;
    cin >> choice;
    printf("\n");

    bank_functions(choice);

    return 0;
}

void welcome() {
    //Welcome Screen
    cout << "Hello and Welcome to E- Manager" << endl;
    cout << "Please enter your name below" << endl;
}

void bank_display() {
    cout << "Enter any of the numbers go ahead" << endl;
    cout << "What would you like to do from the following options:" << endl;
    cout << "1. Create new account" << endl;
    cout << "2. Edit existing account" << endl;
    cout << "3. Exit" << endl;

}

void bank_functions(int choice) {
	int accnum;
	string pswd;
    //Use of switch for any one of the options
    switch(choice) {

        //Case to create new account
        case 1:
            newAccount();
            break;


        //Case to edit existing account
        case 2:
            cout << "Enter the account number: " << endl;
            cin >> accnum;

            //Default account number set up.
            if(accnum == 123456) {
                wrongpswd:
                cout << "Enter your account's password" << endl;
                cin >> pswd;
                if (pswd == "nitk2015") {
                    printf("\n");
                    editAccount(accnum,pswd);
                    }
                else {
                    cout << "Wrong Password entered" << endl;
                    cout << "Try again" << endl;
                    printf("\n");
                    goto wrongpswd;
                    }
                }

            //In case account number doesn't match with the file
            else {
                cout << "Account not found. Create a new account" << endl;
                }
            break;

        //Case to exit the program
        case 3:
            exit(0);
    }

}

//Function to add new account
void newAccount() {
        cout<<"*** Welcome to new account creation ***";
        n.get_data();
        ofstream f;
        f.open("bankaccounts.txt",ios::app);
        f.write((char*)&n,sizeof(n));
        f.close();
        n.display_data(); //Only for debugging

}

//Function to edit existing account
void editAccount(int accnum, string pswd) {

    again1:
    //Account access options
    cout << "Enter the number corresponding to ";
    cout << "one of the following options" << endl;
    cout << "1. Admin access" << endl;
    cout << "2. Client access" << endl;

    int choice;
    cin >> choice;

    switch(choice) {

        //Admin access option
        case 1:
            cout << "You have chosen admin access for your account" << endl;
            admin(accnum, pswd);
            break;
        //Client access option
        case 2:
            cout << "You have chosen client access for your account" << endl;
            client(accnum ,pswd);
            break;
        //None of the above options
        default:
            cout << "Please select a valid option" << endl;
            goto again1;

        }
}

//Function to give admin access over an account
void admin(int accnum, string pswd) {

    again2:
    cout << "Welcome " << name << " to your account number " << accnum << endl;
    cout << "Select any one of the following options" << endl;
    cout << "1. View Account Details" << endl;
    cout << "2. Add Money to Account" << endl;
    cout << "3. Remove Money from Account" << endl;
    cout << "4. Exit" << endl;

    int n;
    cin >> n;

    switch (n) {

        //Account Viewing
        case 1:
            cout << "Here are the details of your account" << endl;
            //Add code to show Account Details

            break;

        //Account money addition
        case 2:
            cout << "Here are the details of your account" << endl;
            //Add code to show Account Details

            //Add code to add money to the account
            int addmoney;
            cout << "Enter the amount of money to add to your account" << endl;
            cin >> addmoney;

            break;

        //Account money withdrawal
        case 3:
            cout << "Here are the details of your account" << endl;
            //Add code to show Account Details

            //Add code to subtract money from account
            int submoney;
            cout << "Enter the amount of money to be removed from your account" << endl;
            cin >> submoney;

            break;

        //Exit statement
        case 4:
            exit(0);

        //None of the above options
        default:
            cout << "Please select a valid option" << endl;
            goto again2;
    }

}

//Function to give client access over an account
void client(int accnum, string pswd) {
    again3:
    cout << "Welcome " << name << " to your account number" << endl;
    cout << "Select any one of the following options" << endl;
    cout << "1. View Account Details" << endl;
    cout << "2. Add spending to Account" << endl;
    cout << "3. Exit" << endl;

    int n;
    cin >> n;

    switch(n) {

        //Account Viewing
        case 1:
            cout << "Here are the details of your account" << endl;
            //Add code to show Account Details

            break;

        //Account spending
        case 2:
            cout << "Here are the details of your account" << endl;
            //Add code to show Account Details

            //Add code to spend money from account
            int spendmoney;
            cout << "Enter the amount of money to be spent from your account" << endl;
            cin >> spendmoney;

            break;

        //Exit from account
        case 3:
            exit(0);

        //None of the above options
        default:
            cout << "Please select a valid option" << endl;
            goto again3;
    }
}
