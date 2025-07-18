#include "class.hpp"
#include "error_codes.hpp"
#pragma once

// =================================================================
// PARAMETERIZED CONSTRUCTOR (rows, cols, InitialValue, ERROR_CODE)
// =================================================================
// the most complete constructor (other constructors indirectly call it)
// creates an object of type MATRIX which has a matrix of size = (rows x
// columns) and all elements of matrix = InitialValue and
// ERROR_CODE = SUCCESS
// =================================================================
MATRIX::MATRIX(size_t rows, size_t cols, double InitialValue, int ERROR_CODE) : rows(rows), cols(cols), ERROR_CODE(ERROR_CODE)
{
    this->matrix = new double *[this->rows];
    for (int i = 0; i < rows; i++)
    {
        this->matrix[i] = new double[this->cols];
        for (int j = 0; j < this->cols; ++j)
        {
            this->matrix[i][j] = InitialValue;
        }
    }
}

// =================================================================
// DEFAULT CONSTRUCTOR ()
// =================================================================
// indirectly calls the most complete constructor with the values
// rows = 1, columns = 1, InitialValue = 0.0000, ERROR_CODE = SUCCESS
// (it calls the following constructor indirectly)
// MATRIX (rows, cols, InitialValue, ERROR_CODE)
// creates an object of type MATRIX which has a matrix of size = (1 x 1)
// and all the elements of the matrix are equal to 0.0000 and
// ERROR_CODE = SUCCESS
// =================================================================
MATRIX::MATRIX()
    : MATRIX(1, 1, 0.0000, CustomErrorCode::SUCCESS) {}

// =================================================================
// PARAMETERIZED CONSTRUCTOR (rows, cols)
// =================================================================
// indirectly calls the most complete constructor with the values
// rows = rows, columns = columns and InitialValue = 0 and
// ERROR_CODE = SUCCESS, (it calls the following constructor)
// indirectly :
// MATRIX (rows, columns, InitialValue, ERROR_CODE)
// creates an object of type MATRIX which has a matrix of
// size = (rows x cols)
// and all the elements of the matrix are equal to 0.0000 and
// ERROR_CODE = SUCCESS
// =================================================================
MATRIX::MATRIX(size_t rows, size_t cols)
    : MATRIX(rows, cols, 0.0000, CustomErrorCode::SUCCESS)
{
}

// =================================================================
// PARAMETERIZED CONSTRUCTOR (rows, cols, InitialValue)
// =================================================================
// indirectly calls the most complete constructor with the values
// rows = rows, columns = columns and InitialValue = InitialValue and
// ERROR_CODE = SUCCESS, (it calls the following constructor)
// indirectly :
// MATRIX (rows, columns, InitialValue, ERROR_CODE)
// creates an object of type MATRIX which has a matrix of
// size = (rows x cols)
// and all the elements of the matrix are equal to InitialValue and
// ERROR_CODE = SUCCESS
// =================================================================
MATRIX::MATRIX(size_t rows, size_t cols, double InitialValue)
    : MATRIX(rows, cols, InitialValue, CustomErrorCode::SUCCESS)
{
}

// =================================================================
// COPY CONSTRUCTOR (const MATRIX &other)
// =================================================================
// creates a new object of type MATRIX as a deep copy of another
// MATRIX object "other"
// copies the dimensions (rows, cols), the ERROR_CODE, and allocates
// new memory for the matrix elements and copies all values
// =================================================================
MATRIX::MATRIX(const MATRIX &other)
    : rows(other.rows), cols(other.cols), ERROR_CODE(other.ERROR_CODE)
{
    matrix = new double *[rows];
    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = new double[cols];
        for (size_t j = 0; j < cols; j++)
        {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}
