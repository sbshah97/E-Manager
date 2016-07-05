#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<fstream>
using namespace std;

class acc
{       long int accnum1;
        string pswd1;
        int cash1;

    public:
        char name[256];
        void get_data();
        void display_data();
        long int retacc_no();
        void add_m(long int);
        void sub_m(long int);
        int ret_cash()
        {
            return cash1;
        }
}n;

long int acc::retacc_no()
{
    return accnum1;
}
void acc::get_data()
{

        cout<<"Enter cash to deposit initially (min 500):";
        cin>>cash1;
        cout<<"Enter your account password:";
        cin>>pswd1;

        //Generating account no
        ifstream f;
        f.open("Acc_no.txt",ios::in);

        f>>accnum1;
        accnum1++;
        f.close();

        ofstream f1;
        f1.open("Acc_no.txt",ios::out);
        f1<<accnum1;
        f1.close();

        cout<<"Account no generated:"<<accnum1<<endl;

        cout<<"Account created successfully";
}

void acc::display_data()
{
   
        cout<<"\nName:"<<n.name<<endl;
        cout<<endl<<"Account number:"<<n.accnum1<<endl;
        cout<<"Cash in account:"<<n.cash1;
   
}

//Member Function to add money

void acc::add_m(long int accnum)
{       fstream f2;
            f2.open("bankaccounts.txt",ios::in|ios::out);

            while(f2.read((char*)&n,sizeof(n)))
            {   if(n.retacc_no()==accnum)
                    {
                        n.display_data();
                        break;
                    }

            }


        int addmoney;
            cout << "Enter the amount of money to be added to your account" << endl;
            cin >> addmoney;
            cout<<"Amount added successfully"<<endl;
            int filepos=f2.tellg();
            n.cash1+=addmoney;
            cout<<"New account balance:"<<n.cash1;
            f2.seekp(filepos-sizeof(n),ios::beg);
            f2.write((char*)&n,sizeof(n));
            f2.close();
}

//Member Function to remove money

void acc::sub_m(long int accnum)
{       fstream f2;
            f2.open("bankaccounts.txt",ios::in|ios::out);

            while(f2.read((char*)&n,sizeof(n)))
            {   if(n.retacc_no()==accnum)
                    {
                        n.display_data();
                        break;
                    }

            }


        int submoney;
            cout << "Enter the amount of money to be removed from your account" << endl;
            cin >> submoney;
            cout<<"Amount removed successfully"<<endl;
            n.cash1-=submoney;
            cout<<"New account balance:"<<n.cash1;
            int filepos=f2.tellg();
            f2.seekp(filepos-sizeof(n),ios::beg);
            f2.write((char*)&n,sizeof(n));
            f2.close();

}

void newAccount();
void editAccount(long int, string);

void admin(long int, string);
void client(long int, string);



int main() {

    //Welcome Screen
    cout << "Hello and Welcome to E- Manager" << endl;
    cout << "Please enter your name below" << endl;

    //Inputting user's name to greet the user.

    cin.getline (n.name,256);
    cout << "Good day to you, " << n.name << endl;
    printf("\n");

    //Start banking functions
    again:
    cout << "Enter any of the numbers go ahead" << endl;
    cout << "What would you like to do from the following options:" << endl;
    cout << "1. Create new account" << endl;
    cout << "2. Edit existing account" << endl;
    cout << "3. Exit" << endl;

    //Choose options
    int choice;
    long int accnum;
    string pswd;
    cin >> choice;
    printf("\n");

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
            if(accnum == 100002) {
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
                goto again;
                }
            break;

        //Case to exit the program
        case 3:
            exit(0);

        //In case none of the options are entered
        default:
            cout << "Enter an appropriate choice" << endl;
            goto again;
    }

    return 0;
}

//Function to add new account
void newAccount()
{
        cout<<"*** Welcome to new account creation ***";
        n.get_data();
        ofstream f;
        f.open("bankaccounts.txt",ios::app);
        f.write((char*)&n,sizeof(n));
        f.close();
        n.display_data(); //Only for debugging

}

//Function to edit existing account
void editAccount(long int accnum, string pswd) {

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
void admin(long int accnum, string pswd) {

    again2:
    cout << "Welcome " << n.name << " to your account number " << accnum << endl;
    cout << "Select any one of the following options" << endl;
    cout << "1. View Account Details" << endl;
    cout << "2. Add Money to Account" << endl;
    cout << "3. Remove Money from Account" << endl;
    cout << "4. Exit" << endl;

    int n1;
    cin >> n1;

    switch (n1) {

        //Account Viewing
        case 1:
            {cout << "Here are the details of your account" << endl;
            //Add code to show Account Details
            ifstream f2;
            f2.open("bankaccounts.txt",ios::in);

            while(f2.read((char*)&n,sizeof(n)))
            {   if(accnum==n.retacc_no())
                    {
                        n.display_data();
                        break;
                    }

            }
            f2.close();
            break;
            }
        //Account money addition
        case 2:
          {
            cout << "Here are the details of your account" << endl;
            n.add_m(accnum);
            break;
          }
        //Account money withdrawal
        case 3:
        {   cout << "Here are the details of your account" << endl;
            n.sub_m(accnum);
            break;
        }
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
void client(long int accnum, string pswd) {
    again3:
    cout << "Welcome " << n.name << " to your account number" << endl;
    cout << "Select any one of the following options" << endl;
    cout << "1. View Account Details" << endl;
    cout << "2. Add spending to Account" << endl;
    cout << "3. Exit" << endl;

    int n2;
    cin >> n2;

    switch(n2) {

        //Account Viewing
        case 1:
           {
               cout << "Here are the details of your account" << endl;
            //Add code to show Account Details
            ifstream f2;
            f2.open("bankaccounts.txt",ios::in);

            while(f2.read((char*)&n,sizeof(n)))
            {   if(n.retacc_no()==accnum)
                    {
                        n.display_data();
                        break;
                    }

            }
            f2.close();
            break;
           }
        //Account spending
        case 2:
           {cout << "Here are the details of your account" << endl;
            n.sub_m(accnum);
           }
        //Exit from account
        case 3:
            exit(0);

        //None of the above options
        default:
            cout << "Please select a valid option" << endl;
            goto again3;
    }
}

