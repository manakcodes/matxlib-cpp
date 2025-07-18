#include <iostream>
#include <iomanip>
#include <cfloat>
#include <cstdlib>

// pragma once to include .hpp files onces every include
#pragma once


#define EPSILON 1e-5

class MATRIX
{
private:
    size_t rows;
    size_t cols;
    double **matrix;
    int ERROR_CODE;

public:
    // =========================================
    // CONSTRUCTORS
    // =========================================
    // constructor body is defined in the file :
    // core/constructor.hpp
    // =========================================

    MATRIX(size_t rows, size_t cols, double InitialValue, int ErrorCode);
    MATRIX(size_t rows, size_t cols, double InitialValue);
    MATRIX(size_t rows, size_t cols);
    MATRIX();
    MATRIX(const MATRIX &other);

    // ===========================================
    // DESTRUCTOR
    // ===========================================
    // destructor is defined in the file in file :
    // core/destructor.hpp
    // ===========================================

    ~MATRIX();

    // ==============================================
    // GETTERS AND SETTERS
    // ==============================================
    // getters and setters are defined in the file :
    // getters_and_setters.hpp
    // ==============================================

    // ===================================================================
    // NO SETTER FOR ROWS AND COLS BECAUSE ONCE SET THEY CANNOT BE CHANGED
    // ===================================================================

    size_t GetRows() const;
    size_t GetCols() const;
    double GetMatrixElement(size_t RowIndex, size_t ColIndex) const;
    void SetMatrixElement(size_t RowIndex, size_t ColIndex, double element);

    // ======================================
    // I/O METHODS
    // ======================================
    // I/O methods are defined in the file :
    // io/input_output_methods.hpp
    // ======================================

    void InputMatrixRowWise();
    void InputMatrixRowWise(double *arr, size_t ArraySize);
    void InputMatrixColumnWise();
    void InputMatrixColumnWise(double *arr, size_t ArraySize);
    void PrintMatrix();
    void RandomizeMatrixDouble(double lower_limit, double upper_limit);
    void RandomizeMatrixInt(int lower_limit, int upper_limit);

    // ====================================
    // DESCRIPTIVE METHODS
    // ====================================
    // methods are defined in the file :
    // descriptive/descriptive_methods.hpp
    // ====================================

    bool IsEqualTo(MATRIX *other);
    int GetMatrixZeroElementsCount();
    int GetMatrixNonZeroElementsCount();
    int GetMatrixPositiveElementsCount();
    int GetMatrixNegativeElementsCount();
    int GetMatrixTotalElementsCount();
    double GetMatrixDensity();
    void PrintMatrixDescriptiveParameters();

    // =========================================
    // AGGREGATION METHODS
    // methods bodies are defined in the file :
    // aggregation/aggregation_methods.hpp
    // =========================================

    MATRIX *GetMaxOfEachRow();
    MATRIX *GetMinOfEachRow();
    MATRIX *GetMaxOfEachColumn();
    MATRIX *GetMinOfEachColumn();
    MATRIX *GetSumOfEachRow();
    MATRIX *GetSumOfEachColumn();
    MATRIX *GetAverageOfEachRow();
    MATRIX *GetAverageOfEachColumn();
    double GetSumOfMatrix();
    double GetMaxOfMatrix();
    double GetMinOfMatrix();
    double GetAverageOfMatrix();

    // ================================
    // SPARSE MATRIX
    // ================================
    // method is defined in the file :
    // transforms/sparse_matrix.hpp
    // ================================
    MATRIX *GetSparseMatrix();

    // ================================
    // TRANSPOSE MATRIX
    // ================================
    // method is defined in the file :
    // transforms/transpose.hpp
    // ================================

    MATRIX *GetTransposedMatrix();
};

// =====================
// OTHER MATRIX METHODS
// =====================

// ============================================
// ADD MATRIX
// ============================================
// method is defined in the file in the file :
// arithmetic/add_matrix.hpp
// ============================================

MATRIX *AddMatrix(MATRIX *A, MATRIX *B);

// ============================================
// SUBTRACT MATRIX
// ============================================
// method is defined in the file in the file :
// arithmetic/subtract_matrix.hpp
// ============================================

MATRIX *SubtractMatrix(MATRIX *A, MATRIX *B);

// ============================================
// MULTIPLY MATRIX
// ============================================
// method is defined in the file in the file :
// arithmetic/multiply_matrix.hpp
// ============================================

MATRIX *MultiplyMatrix(MATRIX *A, MATRIX *B);

// ============================================
// MULTIPLY MATRIX BY A SCALAR
// ============================================
// method is defined in the file in the file :
// arithmetic/multiply_matrix_by_a_scalar.hpp
// ============================================

MATRIX *MultiplyMatrixByAScalar(MATRIX *A, int k);

// ============================================
// DIVIDE MATRIX BY A SCALAR
// ============================================
// method is defined in the file in the file :
// arithmetic/divide_matrix_by_a_scalar.hpp
// ============================================

MATRIX *DivideMatrixByAScalar(MATRIX *A, int k);


