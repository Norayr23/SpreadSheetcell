#include "../SpreadSheetCell/SpreadSheetCell.h"

#include <iostream>

using namespace std;

int main() {
    SpreadsheetCell s1(10, 10);
    s1.setCell(5, 5, "0");
    s1.print();
    s1.addColumn(2);
    s1.print();
    s1.removeRow(5);
    s1.print();
    s1.addRow(4);
    s1.print();
    s1.removeColumn(1);
    s1.print();

    SpreadsheetCell s2 = move(s1);
    s2.print();
    s1 = s2;
    s1.print();
}