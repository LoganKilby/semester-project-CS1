#include "Functions.h"

//no longer writes to txt-file. pushes to map player_map. will add file writing next - 11/13/2019


int main()
{
	int choice;
	int new_player_number;

	ofstream output_file;
	string   new_player_data;
	string	 new_player_name;

	map<string, int> player_map;

	do {
		choice = DisplayMenu();

		switch (choice) {
		case 1: break;
		case 2: break;
		case 3: 
			output_file.open("player-data.txt", fstream::app); //fstream::app (append to end of file).

			if (output_file.is_open()) {
				do {
					cout << "\nTo return to the menu, enter the symbol ^ : " << endl;
					cout << "\t" << "Enter the player's first and last name: ";
					getline(cin, new_player_name);
				
					if (new_player_name == "^") {
						cout << '\n' << player_map.size() << " player(s) have been added";
						output_file.close();

					} else {
						cout << "\t" << "Enter the player's jersey number: ";
						cin >> new_player_number;
						cin.clear();
						cin.ignore(1000, '\n');

						player_map.insert({new_player_name, new_player_number});

					}

				} while (new_player_name != "^");

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


