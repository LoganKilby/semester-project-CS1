#include "Functions.h"

int DisplayMenu() {
	int num;
	cout << "\n\nWelcome to My Team Application\n\n";
	cout << "1 . . . Initialize Application\n2 . . . Load Data\n3 . . . Enter New Player\n4 . . . Display ALL Players\n5 . . . Display ONE Player\n6 . . . Sort Players by Last Name\n9 . . . Exit Application" << endl;
	cout << "\nChoose: ";
	cin >> num;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignoring an unlimited amount of whitespace characters from the input buffer. Is this a good idea?
	return num;
}