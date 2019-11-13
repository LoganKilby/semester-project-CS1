#include "Functions.h"

int DisplayMenu() {
	int num;
	cout << "\n\nWelcome to My Team Application\n\n";
	cout << "1 . . . Initialize Application" << endl;
	cout << "2 . . . Load Data" << endl;
	cout << "3 . . . Enter New Player(s)" << endl;
	cout << "4 . . . Display ALL Players" << endl;
	cout << "5 . . . Display ONE Player" << endl;
	cout << "6 . . . Sort Players by Last Name" << endl;
	cout << "9 . . . Exit Application" << endl;

	cout << "\nChoose: ";
	cin >> num;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignoring an unlimited amount of whitespace characters from the input buffer. Is this a good idea?
	
	return num;
}