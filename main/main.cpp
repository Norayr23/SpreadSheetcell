#include "../SpreadSheetCell/SpreadSheetCell.h"

#include <iostream>

using namespace std;

int main() {
    SpreadsheetCell ob;
    ob.addRow(2); // ավելացնում է երկու տող

Cell* c = ob.getCell(1, 1); // nullptr, աղյուսակն ունի երկու տող, բայց չունի սյունակներ
//cout << c->getStringValue(); // runtime error, dereferencing a nullptr

ob.addColumn(2); // ավելացնում է երկու սյունակ
ob.print();
// այս կետում աղյուսակն ունի այս տեսքը
/*-------
|   |   |
 -------
|   |   |
 -------*/

ob.getCell(1, 1)->getStringValue(); // վերադարձնում է դատարկ տող
ob.setCell(0, 0, "hello");
ob.setCell(0, 1, "3.14");
ob.setCell(1, 1, "val");
ob.print();
/* այս կետում աղյուսակն ունի այս տեսքը
 ---------------------
| "hello"  | "3.14"  |
 ---------------------
|          | "val"   |
 ---------------------*/

cout << ob.getCell(0, 0)->getStringValue() << endl; // տպում է "hello"
cout << ob.getCell(1, 0)->getStringValue() << endl; // տպում է ""
Cell* cell = ob.getCell(1, 1);
cout << cell->getStringValue(); // տպում է "val"
cell->setStringValue("new");
ob.print();
// այս կետում աղյուսակն ունի այս տեսքը
 /*---------------------
| "hello"  | "3.14"  |
 ---------------------
|          | "new"   |
 ---------------------*/

//double v = cell->getDoubleValue(); // runtime error: չի կարող կոնվերտացնել "new" բառը դեպի double
double v2 = ob.getCell(0, 1)->getDoubleValue(); 
cout << v2 << endl;; // տպում է 3.14

Cell* intCell = ob.getCell(1, 0); // վերադարձնում է ցուցիչ դատարկ տող պարունակող cell-ի վրա
// intCell-ը կհղվի այս cell-ին (նկարում նշված է x նշանով)
ob.print();
 /*---------------------
| "hello"  | "3.14"  |
 ---------------------
|    x     | "new"   |
 ---------------------*/

intCell->setStringValue("99");
ob.print();
// այս կետում աղյուսակն ունի այս տեսքը
/* ---------------------
| "hello"  | "3.14"  |
 ---------------------
|   "99"   | "new"   |
 ---------------------*/

cout << ob.getCell(1, 0)->getIntValue() << endl;; // կտպի 99
cout << intCell->getStringValue() << endl; // կտպի "99"
//cout << ob.getCell(0, 0)->getIntValue(); // runtime error, չի կոնվերտացվում "hello"-ն դեպի int
}
