#include "../Spreadsheet/Spreadsheet.h"

#include <iostream>

using namespace std;

int main() {
    Cell cell1("20");
    Cell cell2("21");
   try {
     cout << (12.45 + cell1 ) << endl;
   }
   catch(const std::exception& a) {
     cout << a.what() << endl;    
   }
}
