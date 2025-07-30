#include "class.hpp"
#include "error_codes.hpp"
#include "../../assets/details.hpp"
#pragma once

/***********************************************************************
 * @brief (PARAMETERIZED CONSTRUCTOR)
 * constructs a new `MATRIX` object
 * initializes a `MATRIX` object with the specified number of `rows` and
 * `columns` and all elements of the `MATRIX` are initialized to the
 * given `InitialValue` and sets the `ERROR_CODE` of the MATRIX object
 * to the specified `ERROR CODE`
 *
 * @param rows number of rows of the `MATRIX` (type required ->
 * `size_t`)
 * @param cols number of columns of the `MATRIX` (type required ->
 * `size_t`)
 * @param InitialValue initial value of the all elements of the MATRIX
 * (type required -> `double`)
 * @param ErrorCode ERROR_CODE of the `MATRIX` object (1 = SUCCESS)
 * (type required -> `int`)
 *
 * @note this is the most complete constructor, other constructors
 * delegate to it
 *
 * @file core/constructors.hpp
 **********************************************************************/
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
    configs::details();
}

/***********************************************************************
 * @brief (DEFAULT CONSTRUCTOR)
 * constructs a new MATRIX object
 *
 * initializes a `MATRIX` object with number of `rows = 1` and
 * number `columns = 1` and all the elements of the MATRIX are
 * initialized to `0.0000` and sets the `ERROR_CODE = SUCCESS` of the
 * `MATRIX` object
 *
 * @note this constructor indirectly calls the most complete
 * constructor i.e `MATRIX(size_t rows, size_t cols, double
 * InitialValue, int ErrorCode);` with values `rows = 1`, `cols = 1`, `InitialValue = 0.0000` , `ERROR_CODE = SUCCESS = 1`
 *
 * @file core/constructors.hpp
 **********************************************************************/
MATRIX::MATRIX()
    : MATRIX(1, 1, 0.0000, CustomErrorCode::SUCCESS) {}

/***********************************************************************
 * @brief  (PARAMETERIZED CONSTRUCTOR)
 * constructs a new `MATRIX` object
 *
 * initializes a `MATRIX` object with the specified number of `rows` and
 * `columns` and all elements of the MATRIX are initialized to 0.0000
 * and sets the `ERROR_CODE` of the MATRIX object to `SUCCESS`
 *
 * @param rows number of rows of the MATRIX (type required -> `size_t`)
 * @param cols number of columns of the MATRIX (type required -> `size_t`)
 *
 * @note this constructor indirectly calls the most complete
 * constructor i.e `MATRIX(size_t rows, size_t cols, double
 * InitialValue, int ErrorCode)` with values `rows = rows`, `cols = cols`, `InitialValue = 0.0000` , `ERROR_CODE = SUCCESS = 1`
 *
 * @file core/constructors.hpp
 **********************************************************************/
MATRIX::MATRIX(size_t rows, size_t cols)
    : MATRIX(rows, cols, 0.0000, CustomErrorCode::SUCCESS)
{
}

/***********************************************************************
 * @brief  (PARAMETERIZED CONSTRUCTOR)
 * constructs a new `MATRIX` object
 *
 * initializes a `MATRIX` object with the specified number of `rows` and
 * `columns` and all elements of the `MATRIX` are initialized to the
 * given `InitialValue` and sets the `ERROR_CODE` of the MATRIX object
 * to `SUCCESS`
 *
 * @param rows number of rows of the `MATRIX` (type required ->
 * `size_t`)
 * @param cols number of columns of the `MATRIX` (type required ->
 * `size_t`)
 * @param InitialValue initial value of the all elements of the
 * `MATRIX` (type required -> `double`)
 *
 * @note this constructor indirectly calls the most complete
 * constructor i.e `MATRIX(size_t rows, size_t cols, double
 * InitialValue, int ErrorCode)` with values `rows = rows`, `cols = cols`, `InitialValue = InitialValue` , `ERROR_CODE = SUCCESS = 1`
 *
 * @file core/constructors.hpp
 **********************************************************************/
MATRIX::MATRIX(size_t rows, size_t cols, double InitialValue)
    : MATRIX(rows, cols, InitialValue, CustomErrorCode::SUCCESS)
{
}

/***********************************************************************
 * @brief (COPY CONSTRUCTOR)
 * constructs a new `MATRIX` object as a deep copy of from other
 * `MATRIX` object
 *
 * performs a deep copy of the `MATRIX` data, ensuring that the new
 * object has its own separate memory and does not share data with the
 * original`MATRIX` object
 *
 * @param other reference to the other `MATRIX` object
 *
 * @file core/constructors.hpp
 **********************************************************************/
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
