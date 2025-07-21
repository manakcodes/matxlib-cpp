#include <iostream>
#include <iomanip>
#include <cfloat>
#include <cstdlib>

// pragma once to include .hpp files onces every include
#pragma once

/**
 * @brief a CONSTANT for comparing double values till 4 decimal places
 * `EPSILON = 1E-5 or EPSILON = 0.00001`
 *
 */
#define EPSILON 1E-5

/**
 * @class MATRIX
 * @brief a class to which represents a mathematical MATRIX
 * each MATRIX object contains :
 * -`rows`   : number of rows in the MATRIX (type -> size_t)
 * -`cols`   : number of columns in the MATRIX (type -> size_t)
 * -`matrix` : POINTER to a dynamically allocated 2D array of type DOUBLE
 *             storing MATRIX elements(type -> double **)
 * -`ERROR_CODE` : represents the ERROR_CODE of each MATRIX object (type ->
 *                 int)
 */
class MATRIX
{
private:
    /***********************************
     * @var size_t MATRIX::rows
     * @brief number of rows in the matrix
     ***********************************/
    size_t rows;

    /**************************************
     * @var size_t MATRIX::rows
     * @brief number of columns in the matrix
     **************************************/
    size_t cols;

    /**
     * @var double** MATRIX::matrix
     * @brief `POINTER` to a dynamically allocated 2D array (matrix[row]
     * [col]) of doubles
     */
    double **matrix;
    

    /**
     * @var int MATRIX::ERROR_CODE
     * @brief stores the current error status for each `MATRIX` object
     */
    int ERROR_CODE;

public:
    // ============
    // CONSTRUCTORS
    // ============

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
    MATRIX(size_t rows, size_t cols, double InitialValue, int ErrorCode);

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
    MATRIX(size_t rows, size_t cols, double InitialValue);

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
    MATRIX(size_t rows, size_t cols);

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
    MATRIX();

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
    MATRIX(const MATRIX &other);

    // ==========
    // DESTRUCTOR
    // ==========

    /***********************************************************************
     * @brief DESTRUCTOR for the MATRIX class
     *
     * deallocates the dynamically allocated memory used by the
     * `matrix` member (a `POINTER` to a 2D array of type `double`)
     *
     * ensures that no memory leaks occur when a `MATRIX` object is
     * destroyed
     *
     * @file core/destructor.hpp
     **********************************************************************/
    ~MATRIX();

    /***********************************************************************
     * @brief GETTER
     * for `rows` of the current `MATRIX` object ->
     * (RETURNS the `rows` of the current `MATRIX` object)
     *
     * @return size_t
     *
     * @file core/getters_and_setters.hpp
     **********************************************************************/
    size_t GetRows() const;

    /***********************************************************************
     * @brief GETTER
     * for `cols` of the current `MATRIX` object ->
     * (RETURNS the `cols` of the current `MATRIX` object)
     *
     * @return size_t
     *
     *@file core/getters_and_setters.hpp
     **********************************************************************/
    size_t GetCols() const;

    /***********************************************************************
     * @brief GETTER
     * for the `[i][j] - th` element of `matrix` for the current `MATRIX`
     * object
     * (RETURNS the `[i][j] - th element` of the current `MATRIX` object)
     *
     * @param RowIndex 0 based index of the row (type required -> `size_t`)
     * @param ColIndex 0 based index of the column (type required -> `size_t`)
     * @return double value at the specified index of the matrix i.e `matrix[RowIndex][ColIndex]`
     *
     * @note caller should ensure valid indices, otherwise  for invalid
     * indices the method will return `DBL_MAX`
     *
     * @file core/getters_and_setters.hpp
     **********************************************************************/
    double GetMatrixElement(size_t RowIndex, size_t ColIndex) const;

    /***********************************************************************
     * @brief SETTER
     * for the `[i][j] - th` element of `matrix` of the current `MATRIX`
     * object
     * (SETS the `[i][j] - th element` of the`matrix` of the  current
     * `MATRIX` object to the `element specified`)
     *
     * @param RowIndex 0 based index of the row (type required -> `size_t`)
     * @param ColIndex 0 based index of the column (type required ->
     * `size_t`)
     * @param element the value to be assigned at the specified index i.e `
     * [RowIndex][ColIndex] = element` (type required -> `double`) of the
     *
     * @return void
     *
     * @note caller should ensure valid indices, otherwise for invalid
     * indices the method will assign `matrix[RowIndex][ColIndex] = DBL_MAX`
     * to all the elements of the `matrix`
     *
     * @file core/getters_and_setters.hpp
     **********************************************************************/
    void SetMatrixElement(size_t RowIndex, size_t ColIndex, double element);
};