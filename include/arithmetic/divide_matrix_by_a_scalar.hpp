
#pragma once
#include "../core/class.hpp"
#include "../core/constructor.hpp"
#include "../core/destructor.hpp"
#include "../core/error_codes.hpp"

MATRIX *DivideMatrixByAScalar(MATRIX *A, int k)
{
    // divide every element of the matrix A by a scalar k
    // and return it

    // first check for 0 division error

    if (k == 0.0000)
    {
        int error_code = CustomErrorCode::ERROR__ZERO_DIVISION_ERROR;
        return new MATRIX(1, 1, 0.0000, error_code);
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