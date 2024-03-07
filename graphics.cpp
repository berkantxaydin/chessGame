#include <iostream>
#include <iomanip>
#include "bridge.h"

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::right;
using std::internal;

void setTextColor(int colorCode) {
    cout << "\033[" << colorCode << "m";
    //30-37: Black, Red, Green, Yellow, Blue, Magenta, Cyan, White
    //90-97: Bright Black, Bright Red, Bright Green, Bright Yellow, Bright Blue, Bright Magenta, Bright Cyan, Bright White
}

void resetColor() {
    cout << "\033[0m";
}

void logoArt(){
setTextColor(95);
const char* logoArt = R"(         ,....,
      ,::::::<
     ,::/^\"``.
    ,::/, `   e`.
   ,::; |        '.
   ,::|  \___,-.  c)
   ;::|     \   '-'
   ;::|      \
   ;::|   _.=`\
   `;:|.=` _.=`\
     '|_.=`   __\
     `\_..==`` /
      .'.___.-'.
     /          \
    ('--......--')
    /'--......--'\
    `"--......--")";
cout << logoArt << endl;
resetColor();}