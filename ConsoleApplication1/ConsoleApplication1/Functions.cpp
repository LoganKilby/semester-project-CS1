#include "Functions.h"

int DisplayMenu() {
	int num;
	cout << "\n\nWelcome to My Team Application\n\n";
	cout << "1 ... Initialize Application\n2 ... Load Data\n3 ... Enter New Player\n4 ... Display ALL Players\n5 ... Display ONE Player\n6 ... Sort Players by Last Name\n9 ... Exit Application" << endl;
	cout << "\nChoose: ";
	cin >> num;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //this is the only fix I could find to clear the entire input buffer and not have issues. I'm sure there's a simpler solution. -Logan
	return num;
}