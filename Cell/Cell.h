#ifndef CELL_H
#define CELL_H

#include <string>
#include <ostream>

class Cell {
public:
    Cell() = default;
    explicit Cell(const std::string& s);
    void setStringValue(const std::string& s);
    std::string getStringValue() const;
    int getIntValue() const;
    double getDoubleValue() const;
    bool isEmpty() const;
public:
    explicit operator int() const;
    explicit operator double() const;
    Cell& operator++();
    Cell operator++(int);
    Cell& operator--();
    Cell operator--(int);    
private:
    std::string m_value;
};

std::ostream& operator<<(std::ostream&, const Cell&);
Cell operator+(const Cell&, const Cell&);
Cell operator+(const Cell&, const int);
Cell operator+(const int, const Cell&);

#endif