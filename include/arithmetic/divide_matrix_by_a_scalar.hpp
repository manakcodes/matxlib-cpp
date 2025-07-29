#pragma once
#include "../core/class.hpp"
#include "../core/constructor.hpp"
#include "../core/destructor.hpp"
#include "../core/error_codes.hpp"

/***************************************************************************
 * @brief INPUTS a `POINTER` to a `MATRIX` object then divides all the
 * elements of the `matrix` by a constant k
 *
 * @param A `POINTER` to the `MATRIX` object (required type -> MATRIX *)
 * @param k the constant value to be divided with all elements of the
 * `matrix` (required type -> double)
 * @return MATRIX * (`POINTER` to a new `MATRIX` object)
 *
 * @note if the user passed k = 0.000, then the fn() will RETURN n new `MATRIX` object with
 * - `rows = 1`
 * - `cols = 1`
 * `all elements set to 0.0000`
 * `ERROR_CODE = ERROR__ZERO_DIVISION_ERROR`
 *
 * @file arithmetic/divide_matrix_by_a_scalar.hpp
 **************************************************************************/
MATRIX *DivideMatrixByAScalar(MATRIX *A, double k)
{
    // divide every element of the matrix A by a scalar k
    // and return it

    // first check for 0 division error

    if (k == 0.0000)
    {
        int error_code = CustomErrorCode::ERROR__ZERO_DIVISION_ERROR;
        return MATRIX::INVALID_MATRIX(error_code);
    }

    // create a new matrix of the same dimensions of the matrix passed
    // to the fn
    MATRIX *result = new MATRIX(A->GetRows(), A->GetCols(), 0.00);

    int iRows = A->GetRows();
    for (int i = 0; i < iRows; i++)
    {
        int iCols = A->GetCols();
        for (int j = 0; j < iCols; j++)
        {
            result->SetMatrixElement(i, j, A->GetMatrixElement(i, j) / k);
        }
    }
    return result;
}