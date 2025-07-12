#include <iostream>
#include <iomanip>
#include <cfloat>
#include <cstdlib>

// pragma once to include .hpp files onces every include
#pragma once

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
    // matrix_class_constructors.hpp
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
    // matrix_class-destructor.hpp
    // ===========================================

    ~MATRIX();

    // ==============================================
    // GETTERS AND SETTERS
    // ==============================================
    // getters and setters are defined in the file :
    // matrix_class_getters_and_setters.hpp
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
    // matrix_input_output_methods.hpp
    // ======================================

    void InputMatrixRowWise();
    void InputMatrixColumnWise();
    void PrintMatrix();
    void RandomizeMatrix(double lower_limit, double upper_limit);

    // ====================================
    // DESCRIPTIVE METHODS
    // ====================================
    // methods are defined in the file :
    // matrix_class_descriptive_methods.hpp
    // ====================================

    bool IsEqualTo(MATRIX *other);
    int GetMatrixZeroElementsCount();
    int GetMatrixNonZeroElementsCount();
    int GetMatrixPositiveElementsCount();
    int GetMatrixNegativeElementsCount();
    int GetMatrixTotalElementsCount();

    // =========================================
    // AGGREGATION METHODS
    // methods bodies are defined in the file :
    // matrix_class_aggregation_methods.hpp
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
    double GetMaxElementOfMatrix();
    double GetMinElementOfMatrix();
    double GetAverageOfMatrix();

    // ================================
    // SPARSE MATRIX
    // ================================
    // method is defined in the file :
    // INCLUDE/sparse_matrix.hpp
    // ================================
    MATRIX *GetSparseMatrix();

    // ================================
    // TRANSPOSE MATRIX
    // ================================
    // method is defined in the file :
    // INCLUDE/transpose.hpp
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
// INCLUDE/add_matrix.hpp
// ============================================

MATRIX *AddMatrix(MATRIX *A, MATRIX *B);

// ============================================
// SUBTRACT MATRIX
// ============================================
// method is defined in the file in the file :
// INCLUDE/subtract_matrix.hpp
// ============================================

MATRIX *SubtractMatrix(MATRIX *A, MATRIX *B);

// ============================================
// MULTIPLY MATRIX
// ============================================
// method is defined in the file in the file :
// INCLUDE/multiply_matrix.hpp
// ============================================

MATRIX *MultiplyMatrix(MATRIX *A, MATRIX *B);

// ============================================
// MULTIPLY MATRIX BY A SCALAR
// ============================================
// method is defined in the file in the file :
// INCLUDE/multiply_matrix_by_a_scalar.hpp
// ============================================

MATRIX *MultiplyMatrixByAScalar(MATRIX *A, int k);

// ============================================
// DIVIDE MATRIX BY A SCALAR
// ============================================
// method is defined in the file in the file :
// INCLUDE/divide_matrix_by_a_scalar.hpp
// ============================================

MATRIX *DivideMatrixByAScalar(MATRIX *A, int k);