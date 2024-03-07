#include <iostream>
#include <conio.h>
#include "bridge.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool yesNo(){
    setTextColor(33);
    cout << endl << "Continue? (y/n) :";
    char yesOrNo;
    yesOrNo = getch();
    resetColor();
    return (yesOrNo == 'y' || yesOrNo == 'Y');
}

char numberToLetter(int number) {
    return static_cast<char>('A' + number);
}