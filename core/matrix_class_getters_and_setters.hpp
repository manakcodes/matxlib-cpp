#include "matrix_class.hpp"
#include "matrix_class_error_codes.hpp"

#pragma once

// ===============
// GETTER for rows
// ===============
size_t MATRIX::GetRows() const
{
    return this->rows;
}

// ==================
// GETTER for columns
// ==================
size_t MATRIX::GetCols() const
{
    return this->cols;
}

// ========================================
// GETTER for [i][j] - th element of matrix
// ========================================
double MATRIX::GetMatrixElement(size_t RowIndex, size_t ColIndex) const
{
    if (RowIndex < this->rows && ColIndex < this->cols)
    {
        return this->matrix[RowIndex][ColIndex];
    }
    return DBL_MAX;
}

// ========================================
// SETTER for [i][j] - th element of matrix
// ========================================
void MATRIX::SetMatrixElement(size_t RowIndex, size_t ColIndex, double element)
{
    if (RowIndex < this->rows && ColIndex < this->cols)
    {
        this->matrix[RowIndex][ColIndex] = element;
    }
    else
    {
        this->matrix[RowIndex][ColIndex] = DBL_MAX;
    }
}