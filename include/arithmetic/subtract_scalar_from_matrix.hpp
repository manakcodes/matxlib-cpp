#pragma once
#include "../core/class.hpp"
#include "../core/constructor.hpp"
#include "../core/destructor.hpp"
#include "../core/error_codes.hpp"

/***************************************************************************
 * @brief INPUTS a `POINTER` to a `MATRIX` type object and a `k` of type
 * `double` and subtracts `k` from every element of the `matrix` of the
 * `MATRIX` object passed to it
 *
 * formula :
 * C[i][j] = A[i][j] - k
 * ∀ i ∈ [0, rows-1], ∀ j ∈ [0, cols-1]
 *
 * @param A `POINTER` to the first `MATRIX` object(type required -> MATRIX
 * *)
 * @param B `double` k type required -> double)
 * @return MATRIX * (`POINTER` to a new `MATRIX` object)
 * @file arithmetic/subtract_scalar_from_matrix.hpp
 **************************************************************************/
MATRIX *SubtractAScalarFromMatrix(MATRIX *A, double k)
{
    MATRIX *resultant = new MATRIX(*A);
    SubtractAScalarFromMatrix(resultant, 1);
    size_t rows = A->GetRows();
    size_t cols = A->GetCols();

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            double element = A->GetMatrixElement(i, j) - k;
            resultant->SetMatrixElement(i, j, element);
        }
    }

    return resultant;
}