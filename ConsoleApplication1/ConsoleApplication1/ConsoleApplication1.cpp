// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int DisplayMenu() {
	int num;
	cout << "\n\nWelcome to My Team Application\n\n";
	cout << "1 ... Initialize Application\n2 ... Load Data\n3 ... Enter New Player\n4 ... Display ALL Players\n5 ... Display ONE Player\n6 ... Sort Players by Last Name\n9 ... Exit Application" << endl;
	cout << "\nChoose: ";
	cin >> num;
	return num;
}

int main()
{
	int choice = 0;
	ofstream outputFile;
	string player_name;

	do {
		
		choice = DisplayMenu();

		switch (choice) {
		case 1: break;
		case 2: break;
		case 3: 
			outputFile.open("E:\\Repos\\ConsoleApplication1\\ConsoleApplication1\\player-data.txt", fstream::app); //How can I change this to work after project submission?			

			if (outputFile) {
				do {
					cout << "Please enter the player's first and last name followed by their jersey number.\nTo return to the menu, enter 'Exit': ";
					cin.ignore(); //flushing \n character from input buffer
					getline(cin, player_name);
					if (player_name == "Exit") {
						outputFile.close();
					}
					else {
						outputFile << player_name << endl;
						cout << "Player file updated.\n\n";
					}

				} while (player_name != "Exit");

			} else {
				cout << "Error: Output file 'player-data.txt' could not be found";
			}
			
			break;

		case 4: break;
		case 5: break;
		case 6: break;
		default:
			cout << "Please choose a number from the given list.";
		}
	} while (choice != 9);


	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
