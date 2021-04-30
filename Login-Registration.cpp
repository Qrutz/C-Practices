#include <iostream>
#include<fstream>
#include<string>

using namespace std;


bool isLoggedIn(){
	string username, password, un, pw;


	cout << "enter username "; cin >> username; 
	cout << "enter password "; cin >> password;


	/*Looks through current folder if account exists */
	ifstream read("data\\" + username + ".txt");
	getline(read, un);
	getline(read, pw);

	if(un == username && pw == password) {
		return true;
	}
	else {
		return false;
	}

}


int main()
{
    int choice;

    cout << "1: Register\n2: Login\nYour choice: "; cin>> choice;

    if (choice == 1) {
    	string username, password;

    	cout << "Select a username: "; cin >> username;
    	cout << "Select a password: "; cin >> password;


    	/*Creates file with account details to be stored in curr folder */
    	ofstream file;
    	file.open("data\\" + username + ".txt");

    	file << username << endl << password;

    	file.close();

    	main();
    }
    else if (choice == 2){
    	bool status = isLoggedIn();

    	if (!status){
    		cout << "False login" << endl;
    		system("PAUSE");
    		return 0;
    	}
    	else {
    		cout << "Succesfully logged in!" << endl;
    		return 1;
    	}
    }
}