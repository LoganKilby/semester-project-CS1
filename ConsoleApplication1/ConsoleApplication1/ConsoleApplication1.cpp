#include "Functions.h"

int main()
{
	int choice;

	ofstream output_file;
	string   new_player_data;

	do {
		choice = DisplayMenu();

		switch (choice) {
		case 1: break;
		case 2: break;
		case 3: 
			output_file.open("E:\\Repos\\semester-project-CS1\\ConsoleApplication1\\ConsoleApplication1\\player-data.txt", fstream::app); //pathing will likely not exist on E:\\ after submission ... fstream::app to append to end of file instead of overwriting itwdwwwdwd	

			if (output_file.is_open()) {
				do {
					cout << "Please enter the player's first and last name followed by their jersey number.\nTo return to the menu, enter the symbol ^ : ";
					getline(cin, new_player_data);

					if (new_player_data == "^") {
						output_file.close();
					} else {
						output_file << new_player_data << endl;
						cout << "Player file updated.\n\n";
					}

				} while (new_player_data != "^");

			} else {
				cout << "Error: Output file 'player-data.txt' could not be opened";
			}

			break;

		case 4: break;
		case 5: break;
		case 6: break;
		case 9: 
			cout << "Exiting application . . .\n\n";

			break;

		default:
			cout << "Please choose a number from the given list.";
		}
	} while (choice != 9);
}
