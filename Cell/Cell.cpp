#include "Cell.h"

#include <sstream>
#include <stdexcept>
#include <ostream>

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
        throw std::ios_base::failure("Fail covert value to duble");
    }
    return res;
}
bool Cell::isEmpty() const { return m_value == ""; }
Cell::operator int() const { return getIntValue(); }
Cell::operator double() const { return getDoubleValue(); }
Cell& Cell::operator++() {
    try {
        int num = getIntValue();
        setStringValue(std::to_string(++num));
    }
    catch(std::ios_base::failure& o) {}
    return *this;
}
Cell Cell::operator++(int) {
    Cell tmp(*this);
    tmp;
     ++(*this);
    return tmp;
}
Cell& Cell::operator--() {
    try {
        int num = getIntValue();
        setStringValue(std::to_string(--num));
    }
    catch(std::ios_base::failure& o) {}
    return *this;
}
Cell Cell::operator--(int) {
     Cell tmp(*this);
     tmp;
     --(*this);
    return tmp;
}
std::ostream& operator<<(std::ostream& in, const Cell& cell) {
    in << cell.getStringValue();
    return in;
}
Cell operator+(const Cell& a, const Cell& b) {
    Cell tmp(std::to_string((a.getIntValue() + b.getIntValue())));
    return tmp;
}
Cell operator+(const Cell& a, const int b) { return Cell(std::to_string(a.getIntValue() + b)); }
Cell operator+(const int a, const Cell& b) { return  b + a; }
