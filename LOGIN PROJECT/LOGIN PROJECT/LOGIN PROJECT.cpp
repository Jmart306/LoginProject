#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isLoggedIn()
{
	string username, password, usna, pawo; // USNA = username , PAWO = password

	cout << "Enter Username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;
	// SEE IF THE INFO YOU ENTERED MATCHES UP WITH PREVIOUS INFO
	ifstream read(username + ".txt"); // GET INFO FROM CREATED FILE FROM BEFORE
	getline(read, usna);
	getline(read, pawo);

	if (usna == username && pawo == password) {
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int choice;

	cout << "Register: 1(DO THIS FIRST!) " << endl;
	cout << "Login : 2  " << endl;
	cout << "Your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		string username, password;
		//SET THE LOGIN INFORMATION
		cout << "Select a username: ";
		cin >> username;
		cout << "Select a password: ";
		cin >> password;
		//MAKE A FILE CONTAINING THE INFORMATION TO DETERMINE LOGIN STATUS
		ofstream file;
		file.open(username + ".txt");

		file << username << endl << password;
		file.close();
		main(); // GO BACK TO STARTING SCREEN AFTER LOGINING IN
	}
	else if (choice == 2)
	{
		bool loginStatus = isLoggedIn();

		if (!loginStatus)
		{
			cout << "Wrong Login!" << endl;
			system("pause");
			return 0;
		}
		else
		{
			cout << "Succesfully logged in! " << endl;
			system("pause");
			return 1;
		}

	}
}