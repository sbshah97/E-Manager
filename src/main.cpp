#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

class acc
{//class acc open

	private:
		//declaring variables to hold credentials of a account
		long int accnum1;
		string pswd1;
		int cash1;

	public:

		void get_data()
		{//function-get_data open
			//input cash nad password from user
			cout << "Enter cash to deposit initially (min 500):";
			cin >> cash1;
			cout << "Enter your account password:";
			cin >> pswd1;

			//generate account no
			ifstream f;
			f.open("Acc_no.txt", ios::in);
			int i;
			f >> accnum1;
			accnum1++;
			f.close();

			//output account number
			ofstream f1;
			f1.open("Acc_no.txt", ios::out);
			f1 << accnum1;
			f1.close();

			cout << "Account no generated:" << accnum1 << endl;
			cout << "Account created successfully\n";

		}//function-get_data close

		void display_data()
		{//function-display_data open
			//writing to file
			ifstream f2;
			f2.open("bankaccounts.txt", ios::in | ios::binary);

			while (f2.read((char*)&n, sizeof(n)))
			{//while open
				//f2.read((char*)&n,sizeof(n));
				cout  << "Account number:" << n.accnum1 << " ";
				cout << "Cash in account:" << n.cash1 << "\n";

			}//while close
			//close filestream
			f2.close();

		}//function-display_data close

}n;//class-acc close

//array to hold name
char name[256];
//declaring the functions with respective function signatures
void newAccount();
void editAccount(int, string);
void admin(int, string);
void client(int, string);
void welcome();
void bank_display();
void bank_functions(int);

//main function to run the code
int main()
{//function-main open

	//display welcom screen
	welcome();

	//input user's name to greet the user.
	cin.getline(name, 256);
	cout << "Good day to you, " << name << endl << endl;

	//Start banking functions
	bank_display();

	int choice;//variable to hold choice
	int accnum;//variable to hold account number
	string pswd;//variable to hold password
	//readd choice
	cin >> choice;
	cout << "\n";

	bank_functions(choice);

	system("PAUSE");

	return 0;
}//function-main close

//function to handle the welcom screen
void welcome()
{//function-welcome open
	//print welcome screen
	cout << "Hello and Welcome to E- Manager" << endl;
	cout << "Please enter your name below" << endl;

}//function-welcome close

//function driving the menu
void bank_display()
{//function-bank_display open

	//print menu
	cout << "Enter any of the numbers go ahead" << endl;
	cout << "What would you like to do from the following options:" << endl;
	cout << "1. Create new account" << endl;
	cout << "2. Edit existing account" << endl;
	cout << "3. Exit" << endl;

}//function-bank_display close

//function handling funtionalies of the menu
void bank_functions(int choice)
{//function-bank_functions open

	//display menu
	bank_display();
	//Use of switch for any one of the options
	switch (choice)
	{//switch open
		//case to create new account
		case 1:
			newAccount();
			break;

		//case to edit existing account
		case 2:
			cout << "Enter the account number: " << endl;
			int accnum;
			cin >> accnum;

			//Default account number set up.
			if (accnum == 123456)
			{//if1 open

			wrongpswd://labelling code snippet
				string pswd;
				cout << "Enter your account's password" << endl;
				cin >> pswd;
				if (pswd == "nitk2015")
				{//if2 open

					printf("\n");
					editAccount(accnum, pswd);

				}//if2 close
				else
				{//else2 open

					cout << "Wrong Password entered" << endl;
					cout << "Try again" << endl;
					printf("\n");
					goto wrongpswd;

				}//else2 close

			}//if1 close

			//handling the case of account number not matching with the file
			else
			{//else1 open

				cout << "Account not found. Create a new account" << endl;

			}//else1 close
			break;

		//case to exit the program
		case 3:
			exit(0);

	}//switch close

}//function-bank_functions close

//function to add new account
void newAccount()
{//function-newAccount open
	//receiving credentials and creaating account through function calls
	cout << "*** Welcome to new account creation ***\n";
	n.get_data();
	ofstream f;
	f.open("bankaccounts.txt", ios::app |ios::binary);
	f.write((char*)&n, sizeof(n));
	f.close();
	n.display_data(); //Only for debugging

}//function-newAccount close

//function to edit existing account
void editAccount(int accnum, string pswd)
{//function-editAccount open
	//updating flag
	bool running = true;

	while (running)
	{//while open

		//print account access options
		cout << "Enter the number corresponding to";
		cout << "one of the following options" << endl;
		cout << "1. Admin access" << endl;
		cout << "2. Client access" << endl;

		int choice;//variable to hold choice
		//read choice
		cin >> choice;

		//switch to drive the acccount access menu
		switch (choice)
		{//switch open

			//case handling admin access option
			case 1:
				cout << "You have chosen admin access for your account" << endl;
				admin(accnum, pswd);
				running = false;
				break;

			//case handling client access option
			case 2:
				cout << "You have chosen client access for your account" << endl;
				client(accnum, pswd);
				running = false;
				break;

			//handling when none of the above options match
			default:
				cout << "Please select a valid option" << endl;
				break;

		}//switch close

	}//while close

}//function-editAccount close

//function to give admin access over an account
void admin(int accnum, string pswd)
{//function-admin open
	//updating flag
	bool running = true;

	while (running)
	{//while open

		cout
		<< "Welcome " << name << " to your account number " << accnum << endl;
		cout << "Select any one of the following options" << endl;
		cout << "1. View Account Details" << endl;
		cout << "2. Add Money to Account" << endl;
		cout << "3. Remove Money from Account" << endl;
		cout << "4. Exit" << endl;

		int n;//variable to hold choice
		//read choice
		cin >> n;

		switch (n)
		{//switch open

			//case for account Viewing
			case 1:
				cout << "Here are the details of your account" << endl;
				//Add code to show Account Details
				running = false;
				break;

			//case for account money addition
			case 2:
				cout << "Here are the details of your account" << endl;
				//Add code to show Account Details

				//Add code to add money to the account
				int addmoney;
				cout << "Enter the amount of money to add to your account" << endl;
				cin >> addmoney;
				running = false;
				break;

			//case for account money withdrawal
			case 3:
				cout << "Here are the details of your account" << endl;
				//Add code to show Account Details

				//Add code to subtract money from account
				int submoney;
				cout << "Enter the amount of money to be removed from your account" << endl;
				cin >> submoney;
				running = false;
				break;

			//case for exititng admin menu
			case 4:
				exit(0);
				break;

			//handling when none of the above options match
			default:
				cout << "Please select a valid option" << endl;
				break;

		}//switch close

	}//while close

}//function-admin close

//function to give client access over an account
void client(int accnum, string pswd)
{//function-client open

	again3://labelling code snippet
		//print menu screen
		cout << "Welcome " << name << " to your account number" << endl;
		cout << "Select any one of the following options" << endl;
		cout << "1. View Account Details" << endl;
		cout << "2. Add spending to Account" << endl;
		cout << "3. Exit" << endl;

		int n;//variable to hold choice
		//read choice
		cin >> n;

		//switch to drive the menu's functionality
		switch (n)
		{//switch open
			//case for account Viewing
			case 1:
				cout << "Here are the details of your account" << endl;
				//Add code to show Account Details
				break;

			//case fro account spending
			case 2:
				cout << "Here are the details of your account" << endl;
				//Add code to show Account Details

				//Add code to spend money from account
				int spendmoney;
				cout << "Enter the amount of money to be spent from your account" << endl;
				cin >> spendmoney;
				break;

			//case for exiting from account
			case 3:
				exit(0);
				break;

			//handling when none of the above options match
			default:
				cout << "Please select a valid option" << endl;
				goto again3;

		}//switch close

}//function-client close
