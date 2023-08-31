#ifndef CELL_H
#define CELL_H

#include <string>

class Cell {
public:
    Cell() = default;
    explicit Cell(const std::string& s);
    void setStringValue(const std::string& s);
    std::string getStringValue() const;
    int getIntValue() const;
    double getDoubleValue() const;
    bool isEmpty() const;
private:
    std::string m_value;
};

#endif