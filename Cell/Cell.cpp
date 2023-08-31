#include "Cell.h"

#include <sstream>
#include <stdexcept>

Cell::Cell(const std::string& s) : m_value(s) {}
void Cell::setStringValue(const std::string& s) { m_value = s;}
std::string Cell::getStringValue() const { return m_value; }
int Cell::getIntValue() const {
    std::stringstream ss(m_value);
    int res = 0;
    ss >> res;
    if (ss.fail()) {
        throw std::ios_base::failure("Fail convert value to int");
    }
    return res;

}
double Cell::getDoubleValue() const {
    std::stringstream ss(m_value);
    double res = 0;
    ss >> res;
    if (ss.fail()) {
        throw std::ios_base::failure("Fail convert value to double");
    }
    return res;
}
bool Cell::isEmpty() const { return m_value == ""; }
