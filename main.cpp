#include <iostream>
//#include <fstream> 
#include <conio.h>
//#include <stdlib.h>
#include <iomanip>
//#include <ctime>
//#include <string.h>
#include "bridge.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;

void home ();
int options();
void actions(int& opt);

bool flag = true;

int main (void) {

	while(flag) {
        home();
	}

	cout << " Good Bye!" << endl;
    cin.get();
}

void home () {
	logoArt();
	int opt = options();
	if (opt <= 2) {
		actions(opt);
	} else if (opt > 2) {
		cout << endl << "!!! Enter Valid option !!!" << endl;
		cin.get();
	    system("cls");
	}
}

int options() {
	setTextColor(36);
	cout << "1. Play"<< endl;
	cout << "2. Customize"<< endl;
	cout << "0. Exit"<< endl;
	resetColor();
	cout << "Enter one option: ";

	int ch = getch();
    int selectedOption = ch - '0';
	return selectedOption;
} 

void actions(int& opt) {
	switch(opt) {
		case 1: 
            cout <<"Player vs Player";
			if(yesNo()){
            initializeGame();}
			system("cls");
			break;
		case 2:
            cout <<"Change Colors";
			if(yesNo()){
			}
			system("cls");
			break;
	    case 0:
		    flag = false;
	}
}

