#ifndef SPREADSHEETCELL_H
#define SPREADSHEETCELL_H

#include "../Cell/Cell.h"
#include <cstddef>

class SpreadsheetCell {
public:
    SpreadsheetCell() : m_cell{}, m_row{}, m_col{} {}
    SpreadsheetCell(const int row, const int column);
    SpreadsheetCell(const SpreadsheetCell& src);
    SpreadsheetCell(SpreadsheetCell&& src) noexcept;
    SpreadsheetCell& operator=(const SpreadsheetCell& src);
    SpreadsheetCell& operator=(SpreadsheetCell&& src) noexcept;
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
    ~SpreadsheetCell();
private:
    Cell** m_cell;
    int m_row;
    int m_col;    
};

#endif