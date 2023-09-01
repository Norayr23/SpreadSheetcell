#include "../Spreadsheet/Spreadsheet.h"

#include <iostream>


using namespace std;

int main() {
    Spreadsheet s1(2, 2);
    s1[0][0].setStringValue("4");
    s1[0][1].setStringValue("6");
    s1[1][0].setStringValue("a");
    s1[1][1].setStringValue("b");
    Spreadsheet s2(2, 3);
    s2[0][0].setStringValue("x");
    s2[0][1].setStringValue("cc");
    s2[0][2].setStringValue("6");
    s2[1][0].setStringValue("7");
    s2[1][1].setStringValue("0.1");
    s2[1][2].setStringValue("yy");
    cout << (s1 + s2) << endl;
    
}
