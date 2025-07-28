#pragma once
#include "../core/class.hpp"
#include "../core/constructor.hpp"
#include "../core/destructor.hpp"
#include "../core/error_codes.hpp"

/***************************************************************************
 * @brief INPUTS two `POINTERS` to `MATRIX` objects and performs element
 * wise multiplication of the `matrix` of both the `MATRIX` objects and
 * RETURNS a `POINTER` to a new `MATRIX` object.
 *
 * formula :
 * C[i][j] = A[i][j] * B[i][j]
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
MATRIX *MultiplyMatrixElementWise(MATRIX *A, MATRIX *B)
{
    if (!MATRIX::HasSameOrder(A, B))
    {
        int error_code = CustomErrorCode::ERROR__MATRIX_DIMENSIONS_MISMATCH_ERROR;
        return MATRIX::INVALID_MATRIX(error_code);
    }

    size_t rows = A->GetRows();
    size_t cols = A->GetCols();

    MATRIX *resultant = new MATRIX(rows, cols);

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            double element = A->GetMatrixElement(i, j) * B->GetMatrixElement(i, j);
            resultant->SetMatrixElement(i, j, element);
        }
    }
    return resultant;
}