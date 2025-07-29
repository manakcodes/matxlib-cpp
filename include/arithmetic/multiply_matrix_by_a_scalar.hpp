#pragma once
#include "../core/class.hpp"
#include "../core/constructor.hpp"
#include "../core/destructor.hpp"
#include "../core/error_codes.hpp"

/***************************************************************************
 * @brief INPUTS a `POINTER` to a `MATRIX` object then multiplies all the
 * elements of the `matrix` by a constant k
 *
 * @param A `POINTER` to the `MATRIX` object (required type -> MATRIX *)
 * @param k the constant value to be multiplied with all elements of the `
 * matrix` (required type -> double)
 *
 * @return MATRIX * (`POINTER` to a new `MATRIX` object)
 *
 * @file arithmetic/multiply_matrix_by_a_scalar.hpp
 **************************************************************************/
MATRIX *MultiplyMatrixByAScalar(MATRIX *A, double k)
{
    // multiply every element of the matrix A by a scalar k
    // and return it

    // create a new matrix of the same dimensions of the matrix passed
    // to the fn
    MATRIX *result = new MATRIX(A->GetRows(), A->GetCols(), 0.00);

    int iRows = A->GetRows();
    for (int i = 0; i < iRows; i++)
    {
        int iCols = A->GetCols();
        for (int j = 0; j < iCols; j++)
        {
            result->SetMatrixElement(i, j, A->GetMatrixElement(i, j) * k);
        }
    }
    return result;
}