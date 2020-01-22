#include <iostream>
#include <fstream>
#include <string>
#include "Functions.h"
#include "Functions.h"

using namespace std;

int main()
{
	int option = 0;
	string players[ROWS][COLS];
	initArray(players);

	do {
		option = displayMenu();
		switch(option) {
		case 1: break;
		case 2:
			initArray(players);
			loadData(players);
			break;
		case 3:
			enterPlayers(players);
			break;
		case 4:
			displayAll(players);
			break;
		case 5:
			displaySelected(players);
			break;
		case 6:
			sortArray(players);
			break;
		case 7:
			saveData(players);
			break;
		case 8:
			displayAppStatus(players);
			break;
		case 9:
			break;
		}
	} while (option > 0 && option < 9);

}


