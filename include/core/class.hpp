#include <iostream>
#include <iomanip>
#include <cfloat>
#include <cstdlib>
#include <string>

// pragma once to include .hpp files onces every include
#pragma once

/**
 * @brief a CONSTANT for comparing double values till 4 decimal places
 * `EPSILON = 1E-5 or EPSILON = 0.00001`
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
    /*************************************
     * @var size_t MATRIX::rows
     * @brief number of rows in the matrix
     *************************************/
    size_t rows;

    /****************************************
     * @var size_t MATRIX::cols
     * @brief number of columns in the matrix
     ****************************************/
    size_t cols;

    /*******************************************************************
     * @var double** MATRIX::matrix
     * @brief `POINTER` to a dynamically allocated 2D array (matrix[row]
     * [col]) of doubles
     *******************************************************************/
    double **matrix;

    /*****************************************************************
     * @var int MATRIX::ERROR_CODE
     * @brief stores the current error status for each `MATRIX` object
     *****************************************************************/
    int ERROR_CODE;

public:
    // ================================================================== //
    // MATRIX CONSTRUCTOR
    // ================================================================== //
    // @file : core/constructors.hpp
    // ================================================================== //

    MATRIX(size_t rows, size_t cols, double InitialValue, int ErrorCode);
    MATRIX(size_t rows, size_t cols, double InitialValue);
    MATRIX(size_t rows, size_t cols);
    MATRIX();
    MATRIX(const MATRIX &other);

    // ================================================================== //
    // MATRIX DESTRUCTOR
    // ================================================================== //
    // @file : core/destructor.hpp
    // ================================================================== //

    ~MATRIX();

    // ================================================================== //
    // MATRIX GETTER AND SETTER METHODS
    // ================================================================== //
    // @file : core/getters_and_setters_matrix.hpp
    // ================================================================== //

    size_t GetRows() const;
    size_t GetCols() const;
    double GetMatrixElement(size_t RowIndex, size_t ColIndex) const;
    void SetMatrixElement(size_t RowIndex, size_t ColIndex, double element);

    // ================================================================== //
    // MATRIX I/O METHODS
    // ================================================================== //
    // @file : io/input_output_matrix.hpp
    // ================================================================== //

    void InputMatrixRowWise();
    void InputMatrixRowWise(double *arr, size_t ArraySize);
    void InputMatrixColumnWise();
    void InputMatrixColumnWise(double *arr, size_t ArraySize);

    // ================================================================== //
    // MATRIX UTILITY METHODS
    // ================================================================== //
    // @file : core/utility_methods.hpp
    // ================================================================== //

    void PrintMatrix();
    void RandomizeMatrixDouble(double lower_limit, double upper_limit);
    void RandomizeMatrixInt(int lower_limit, int upper_limit);
    bool IsEqualTo(MATRIX *other);
    static MATRIX *GetIdentityMatrix(size_t rows, size_t cols);
    static MATRIX *GetOnesMatrix(size_t rows, size_t cols);
    static MATRIX *GetZeroMatrix(size_t rows, size_t cols);
    static MATRIX *GetScalarMatrix(size_t rows, size_t cols, double k);
    static MATRIX *GetRowMatrix(size_t rows);
    static MATRIX *GetColumnMatrix(size_t columns);
    static MATRIX *GetMainDiagonalMatrix(size_t rows, size_t cols, double k);
    static MATRIX *GetAntiDiagonalMatrix(size_t rows, size_t cols, double k);
    static MATRIX *GetUpperTriangularMatrix(size_t rows, size_t cols, double k);
    static MATRIX *GetLowerTriangularMatrix(size_t rows, size_t cols, double k);

    // ================================================================== //
    // MATRIX DESCRIPTIVE METHODS
    // ================================================================== //
    // @file : descriptive/descriptive_matrix.hpp
    // ================================================================== //

    int GetMatrixZeroElementsCount();
    int GetMatrixNonZeroElementsCount();
    int GetMatrixPositiveElementsCount();
    int GetMatrixNegativeElementsCount();
    int GetMatrixTotalElementsCount();
    double GetMatrixDensity();
    bool IsSquareMatrix();
    bool IsZeroMatrix();
    bool IsOnesMatrix();
    bool IsIdentityMatrix();
    bool IsSkewSymmetricMatrix();
    bool IsSymmetricMatrix();
    bool IsInvertible();
    void PrintMatrixDescriptiveParameters();

    // ================================================================== //
    // MATRIX STATISTICAL METHODS
    // ================================================================== //
    // @file : statistics/statistics_matrix.hpp
    // ================================================================== //

    MATRIX *GetMaxOfEachRow();
    MATRIX *GetMinOfEachRow();
    MATRIX *GetMaxOfEachColumn();
    MATRIX *GetMinOfEachColumn();
    MATRIX *GetSumOfEachRow();
    MATRIX *GetSumOfEachColumn();
    MATRIX *GetAverageOfEachRow();
    MATRIX *GetAverageOfEachColumn();
    double GetMatrixDiagonalSum();
    double GetMatrixAntiDiagonalSum();
    double GetSumOfMatrix();
    double GetMaxOfMatrix();
    double GetMinOfMatrix();
    double GetAverageOfMatrix();
    double GetRangeOfMatrix();
    void PrintMatrixStatisticalParameters();

    // ================================================================== //
    // MATRIX TRANSFORM METHODS
    // ================================================================== //
    // @file : transforms/sparse_matrix.hpp
    // @file : transforms/sparse_matrix.hpp
    // ================================================================== //

    MATRIX *GetSparseMatrix();
    MATRIX *GetTransposeMatrix();
};

// ================================================================== //
// MATRIX ARITHMETIC METHODS
// ================================================================== //
// @file : arithmetic/add_matrix.hpp
// @file : arithmetic/subtract_matrix.hpp
// @file : arithmetic/multiply_matrix.hpp
// @file : arithmetic/multiply_matrix_by_a_scalar.hpp
// @file : arithmetic/divide_matrix_by_a_scalar.hpp
// ================================================================== //

MATRIX *AddMatrix(MATRIX *A, MATRIX *B);
MATRIX *AddAScalarToMatrix(MATRIX *A, double k);

MATRIX *SubtractMatrix(MATRIX *A, MATRIX *B);
MATRIX *SubtractAScalarFromMatrix(MATRIX *A, double k);

MATRIX *MultiplyMatrix(MATRIX *A, MATRIX *B);
MATRIX *MultiplyMatrixByAScalar(MATRIX *A, double k);
MATRIX *MultiplyMatrixElementWise(MATRIX *A, MATRIX *B);

MATRIX *DivideMatrixElementWise(MATRIX *A, MATRIX *B);
MATRIX *DivideMatrixByAScalar(MATRIX *A, double k);
