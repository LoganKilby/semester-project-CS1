#include "Functions.h"

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
					cout << '\t' << "Enter the player's first and last name: ";
					getline(cin, new_player_name);
				
					if (new_player_name == "^") {
						cout << '\n' << player_map.size() << " player(s) have been added:" << endl;
						for (auto const& x : player_map) { 
							cout << x.first << " : " << x.second << endl;
							output_file << x.first << " : " << x.second << endl; // @ref this output should probably be formated for reading from file
						}

						output_file.close();

					} else {
						cout << '\t' << "Enter the player's jersey number: ";
						cin >> new_player_number;
						cin.clear();
						cin.ignore(1000, '\n');

						pair<map<string, int>::iterator, bool> checker; //using the built-in boolean return value to check for insert failure
						checker = player_map.insert(pair<string, int>(new_player_name, new_player_number));
						if (checker.second == false) {
							cout << "Error. This player has already been entered." << endl;

						} else {
							player_map.insert(pair<string, int>(new_player_name, new_player_number));

						}

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


