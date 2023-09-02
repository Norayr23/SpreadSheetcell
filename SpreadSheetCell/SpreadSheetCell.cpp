#include "SpreadSheetCell.h"

#include <cstddef>
#include <iostream>
#include <utility>

SpreadsheetCell::SpreadsheetCell(const int row, const int column) : m_col(column), m_row(row) {
    if (row <= 0 || column <= 0) {
        m_row = 0;
        m_col = 0;
        m_cell = nullptr;
        return;
    }
    m_cell = new Cell*[row];
    for (int i = 0; i < row; ++i) {
        m_cell[i] = new Cell[column];
    }
}
SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src) : SpreadsheetCell(src.getRow(), src.getColumn()) {
    for (int i = 0; i < getRow(); ++i) {
        for (int j = 0; j < getColumn(); ++j) {
             getCell(i, j)->setStringValue(src.getCell(i, j)->getStringValue());
        }
    }
}
SpreadsheetCell::SpreadsheetCell(SpreadsheetCell&& src) noexcept {
    m_cell = std::exchange(src.m_cell, nullptr);
    m_row = std::exchange(src.m_row, 0);
    m_col = std::exchange(src.m_col, 0);
}
SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& src) {
    if (getRow() == src.getRow() && getColumn() == src.getColumn()) {
        for (int i = 0; i < getRow(); ++i) {
            for(int j = 0; j < getColumn(); ++j) {
                getCell(i, j)->setStringValue(src.getCell(i, j)->getStringValue());
            }
        }
        return *this;
    }
    SpreadsheetCell tmp(src);
    std::swap(m_cell, tmp.m_cell);
    std::swap(m_col, tmp.m_col);
    std::swap(m_row, tmp.m_row);
    return *this;
}
SpreadsheetCell& SpreadsheetCell::operator=(SpreadsheetCell&& src) noexcept {
    m_cell = std::exchange(src.m_cell, nullptr);
    m_row = std::exchange(src.m_row, 0);
    m_col = std::exchange(src.m_col, 0);
    return *this;
}
void SpreadsheetCell::addRow(const int count) {
    if (count <= 0) {
        return;
    }
    int newRow = getRow() + count;
    Cell** tmp = new Cell*[newRow];
    for (int i = 0; i < newRow; ++i) {
        if (i >= getRow()) {
            tmp[i] = new Cell[getColumn()];
        }
        else {
            tmp[i] = m_cell[i];
        }        
    }
    delete [] m_cell;
    m_row = newRow;
    m_cell = tmp;
}
void SpreadsheetCell::addColumn(const int count) {
     if (count <= 0) {
        return;
    }
    int newColumn = getColumn() + count;
    for (int i = 0; i < getRow(); ++i) {
        Cell* tmp = new Cell[newColumn];
        for (int j = 0; j < getColumn(); ++j) {
            tmp[j] = m_cell[i][j];
        }
        delete [] m_cell[i];
        m_cell[i] = tmp;
    }
    m_col = newColumn;
}
void SpreadsheetCell::removeColumn(const size_t index) {
     if (index >= getColumn()) {
        return;
    }
    for (int i = 0; i < getRow(); ++i) {
        for (int j = index; j < getColumn() - 1; ++j) {
            m_cell[i][j].setStringValue(m_cell[i][j + 1].getStringValue());
        }
    }
    --m_col;
}
void SpreadsheetCell::removeRow(const size_t index) {
    if (index >= getRow()) {
        return;
    }
    delete [] m_cell[index];
    for (int i = index; i < getRow() - 1; ++i) {
        m_cell[i] = m_cell[i + 1];
    }
    m_cell[getRow() - 1] = nullptr;
    --m_row;
}
const Cell* SpreadsheetCell::getCell(const size_t row, const size_t column) const {
    return static_cast<const Cell*>(const_cast<SpreadsheetCell&>(*this).getCell(row, column));
}
Cell* SpreadsheetCell::getCell(const size_t row, const size_t column)  {
    if (row > getRow() || column > getColumn()) {
        return nullptr;
    }
    return m_cell[row] + column;
    
}
void SpreadsheetCell::setCell(const size_t row,  const size_t col, const Cell& cell) {
     if (row >= getRow() || col >= getColumn()) {
        return;
    }
     m_cell[row][col] = cell;
}
void SpreadsheetCell::setCell(const size_t row, const size_t col, const std::string& str) {
    if (row >= getRow() || col >= getColumn()) {
        return;
    }
    m_cell[row][col].setStringValue(str);
}
int SpreadsheetCell::getRow() const { return m_row; }
int SpreadsheetCell::getColumn() const { return m_col; }
void SpreadsheetCell::print() const {
    for (int i = 0; i < getRow(); ++i) {
        for (int j = 0; j < getColumn(); ++j) {
            if (m_cell[i][j].isEmpty()) {
                std::cout << ". ";
            }
            else {
                std::cout << m_cell[i][j].getStringValue() << " ";
            }
        }
        std::cout  << std::endl;
    }
    std::cout << std::endl;
}
void SpreadsheetCell::clear() {
     for (int i = 0; i < getRow(); ++i) {
      delete [] m_cell[i];
    }
    delete [] m_cell;
    m_cell = nullptr;
    m_col = 0;
    m_row = 0;
}
SpreadsheetCell::~SpreadsheetCell() {
    clear();
}
