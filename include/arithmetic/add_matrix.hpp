#pragma once
#include "../core/class.hpp"
#include "../core/constructor.hpp"
#include "../core/destructor.hpp"
#include "../core/error_codes.hpp"

/***************************************************************************
 * @brief INPUTS two `POINTERS` to `MATRIX` objects and performs element
 * wise addition of the `matrix` of both the `MATRIX` objects and RETURNS a
 * `POINTER` to a new `MATRIX` object
 *
 * formula :
 * C[i][j] = A[i][j] + B[i][j]
 * ∀ i ∈ [0, rows-1], ∀ j ∈ [0, cols-1]
 *
 * @param A `POINTER` to the first `MATRIX` object(type required -> MATRIX
 * *)
 * @param B `POINTER` to the second `MATRIX` object (type required ->
 * MATRIX *)
 * @return MATRIX * (`POINTER` to a new `MATRIX` object)
 *
 * @note if the rows and columns of `matrix` of first `MATRIX` object is
 * not equal to the rows and columns of the `matrix` of the second `MATRIX`
 * object then the fn() RETURNS a `POINTER` to a new `MATRIX` object with :
 * -`rows = 1`
 * -`cols = 1`
 * -`all elements set to 0.0000`
 * -`ERROR_CODE = ERROR__MATRIX_DIMENSIONS_MISMATCH_ERROR`
 *
 * @file arithmetic/add_matrix.hpp
 **************************************************************************/
MATRIX *AddMatrix(MATRIX *A, MATRIX *B)
{
    // if the dimensions of both matrices are not equal
    // print a message
    if (!(MATRIX::HasSameOrder(A, B)))
    {
        // return a 0 matrix of order 1x1 with
        // Error Code = INVALID MATRIX DIMENSIONS
        int error_code = CustomErrorCode::ERROR__MATRIX_DIMENSIONS_MISMATCH_ERROR;
        return MATRIX::INVALID_MATRIX(error_code);
    }

    // create a matrix to hold the sum of the matrix A and matrix B
    MATRIX *result = new MATRIX(A->GetRows(), A->GetCols());

    // add the corresponding elements of the matrix
    // outer loop (i) to iterate over the rows
    for (int i = 0; i < A->GetRows(); i++)
    {

        // inner loop (j) to iterate over the cols
        for (int j = 0; j < A->GetCols(); j++)
        {
            int element = A->GetMatrixElement(i, j) + B->GetMatrixElement(i, j);
            result->SetMatrixElement(i, j, element);
        }
    }

    // return the resultant matrix
    return result;
}