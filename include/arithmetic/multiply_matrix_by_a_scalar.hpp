
#pragma once
#include "../core/class.hpp"
#include "../core/constructor.hpp"
#include "../core/destructor.hpp"
#include "../core/error_codes.hpp"

MATRIX *MultiplyMatrixByAScalar(MATRIX *A, int k)
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