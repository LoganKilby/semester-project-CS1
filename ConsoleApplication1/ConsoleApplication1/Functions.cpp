#include "Functions.h"
#include "GlobalConstants.h"
#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>

using namespace std;

string OpenFileName = "";

void Banner(string message) {
	string unpause;
	cout << endl << endl << "\t*****" << endl;
	cout << "\t" << message << endl;
	cout << "\t*****" << endl << endl;
	cout <<"\tENTER to Continue";
	cin.ignore();
	getline(cin, unpause);
}

void initArray(string array[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; i < COLS; i++) {
			array[i][j] = "";
		}
	}
}

int firstAvailableRow(const string array[ROWS][COLS]) {
	int count = 0;
	while (array[count][FNAME] != "") {
		count++;
	}
	return count;
}

void enterPlayers(string array[ROWS][COLS]) {
	string fName, lName, jerseyNum = "";
	int currRow = firstAvailableRow(array);
	while (fName != "Exit") {
		cout << "Enter Player First Name: ";
		cin >> fName;
		if (fName != "Exit") {
			cout << "Enter Players Last Name ";
			cin >> lName;
			cout << "Enter Players Jersey Number: ";
			cin >> jerseyNum;

			array[currRow][FNAME] = fName;
			array[currRow][LNAME] = lName;
			array[currRow][JNUM] = jerseyNum;
			currRow++;
		}
	}
}

int displayMenu() {
	system("CLS");
	
	int option;
	cout << endl << "\tWelcome to My Team Application" << endl << endl;
		cout << "\t1 ... Initialize Application" << endl;
		cout << "\t2 ... Load Data from File" << endl;
		cout << "\t3 ... Enter New Player" << endl;
		cout << "\t4 ... Display ALL Players" << endl;
		cout << "\t5 ... Display ONE Player" << endl;
		cout << "\t6 ... Sort Players by Last Name" << endl;
		cout << "\t7 ... Save Data to File" << endl;
		cout << "\t8 ... Application Status" << endl;
		cout << "\t9 ... Exit Application" << endl;
		cout << "\n\tChoose: ";
		cin >> option;
		cout << endl;
		return option;
}

void saveData(const string array[ROWS][COLS]) {
	ofstream outFile;
	string filename;
	int lastValidRow = firstAvailableRow(array);
	cout << "Enter the name of file for saving all data: ";
	cin >> filename;
	outFile.open(filename);

	while (!outFile) {
		cout << "Could not create file. Enter the name of file for saving all data: ";
		cin >> filename;
		outFile.open(filename);
	}

	if (lastValidRow > 0) {
		for (int i = 0; i < lastValidRow; i++) {
			outFile << array[i][FNAME] << " " << array[i][LNAME] << " " << array[i][JNUM] << endl;
		}
	}
	outFile.close();
	Banner("Data Saved to " + filename);

}

void loadData(string array[ROWS][COLS]) {
	ifstream inFile;
	string filename;
	int rowCount = 0;
	string fname, lname, jerseyNum;

	cout << "Enter the name of the input file: ";
	cin >> filename;
	inFile.open(filename);
	OpenFileName = filename;

	while (!inFile) {
		cout << "File NOT found. Make sure the file is in this location: ..\\semester-project-CS1\\ConsoleApplication1\\ConsoleApplication1" << endl <<  "Enter the name of the input file: ";
		cin >> filename;
		inFile.open(filename);
	}

	while (rowCount < ROWS && inFile >> fname) {
		inFile >> lname;
		inFile >> jerseyNum;

		array[rowCount][FNAME] = fname;
		array[rowCount][LNAME] = lname;
		array[rowCount][JNUM]  = jerseyNum;
		rowCount++;
	}
	inFile.close();
	if (rowCount > 99) {
		Banner("Too many players stored. Please delete a player to make room.");
	}
	Banner("Data Loaded from file: " + filename + "\n\t    Records Loaded: " + to_string(rowCount));
}

void displayAll(const string array[ROWS][COLS]) {
	int lastRecord = firstAvailableRow(array);
	string unpause;
	cout << endl << endl << "List of All Players" << endl;
	cout << "********************" << endl;
	
	for (int i = 0; i < lastRecord; i++) {
		cout << array[i][FNAME] << " " << array[i][LNAME] << " " << array[i][JNUM] << endl;
	}
	cout << "********************" << endl << endl;
	cout << "Enter E to Exit : ";
	cin >> unpause;
}

void displayAppStatus(const string array[ROWS][COLS]) {
	system("CLS");
	cout << endl << "\tRecord Count: " << firstAvailableRow(array) << endl;
	cout << "\tOpen File Name: " << OpenFileName << endl;
	Banner("Application Status");
}

void displaySelected(const string array[ROWS][COLS]) {
	string lastName;
	int currentRow = 0;
	cout << "Enter player to display(last name, must be exact match): ";
	cin >> lastName;

	while (lastName != array[currentRow][LNAME]) {
		currentRow++;
	}

	cout << endl << array[currentRow][FNAME] << "\t" << array[currentRow][LNAME] << ":\t" << array[currentRow][JNUM] << endl;
	Banner("");
}

void swapRecords(string array[ROWS][COLS], int index) {
	string tmpFNAME = array[index][FNAME];
	string tmpLNAME = array[index][LNAME];
	string tmpJNUM  = array[index][JNUM];

	array[index][FNAME] = array[index + 1][FNAME];
	array[index][LNAME] = array[index + 1][LNAME];
	array[index][JNUM]  = array[index + 1][JNUM];

	array[index + 1][FNAME] = tmpFNAME;
	array[index + 1][LNAME] = tmpLNAME;
	array[index + 1][JNUM]  = tmpJNUM;
}

void sortArray(string array[ROWS][COLS]) {
	int endOfData = firstAvailableRow(array);
	for (int i = 0; i < endOfData; i++) {
		for (int j = 0; j < endOfData - 1; j++){
			if (array[j][LNAME] > array[j + 1][LNAME]) {
				swapRecords(array, j);
			}
		}
	}
	Banner("Data Sorted by Last Name: " + to_string(endOfData) + " Records  ");
}