#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include "../Cell/Cell.h"
#include <cstddef>

class Spreadsheet {
public:
    Spreadsheet() : m_cell{}, m_row{}, m_col{} {}
    Spreadsheet(const int row, const int column);
    Spreadsheet(const Spreadsheet& src);
    Spreadsheet(Spreadsheet&& src) noexcept;
    Spreadsheet& operator=(const Spreadsheet& src);
    Spreadsheet& operator=(Spreadsheet&& src) noexcept;
    void addRow(const int count);
    void addColumn(const int count);
    void removeColumn(const size_t index);
    void removeRow(const size_t index);
    Cell* getCell(const size_t row, const size_t column);
    const Cell* getCell(const size_t row, const size_t column) const;
    int getRow() const;
    int getColumn() const;
    void setCell(const size_t, const size_t, const Cell&);
    void setCell( const size_t, const size_t, const std::string&);
    void print() const;
    void clear();
    ~Spreadsheet();
private:
    Cell** m_cell;
    int m_row;
    int m_col;    
};

#endif