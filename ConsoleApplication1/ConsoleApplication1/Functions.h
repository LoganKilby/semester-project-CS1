#pragma once

#include <string>
#include "GlobalConstants.h"
using namespace std;

int displayMenu();
void enterPlayers(string array[ROWS][COLS]);
void initArray(string array[ROWS][COLS]);
int firstAvailableRow(const string array[ROWS][COLS]);
void saveData(const string array[ROWS][COLS]);
void loadData(string array[ROWS][COLS]);
void displayAll(const string array[ROWS][COLS]);
void displayAppStatus(const string array[ROWS][COLS]);
void displaySelected(const string array[ROWS][COLS]);
void sortArray(string array[ROWS][COLS]);
void swapRecords(string array[ROWS][COLS], int index);
void Banner(string message);