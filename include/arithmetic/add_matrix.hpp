#include "../core/class.hpp"
#include "../core/constructor.hpp"
#include "../core/destructor.hpp"
#include "../core/error_codes.hpp"
#pragma once



// method to add 2 matrices of same order
MATRIX *AddMatrix(MATRIX *A, MATRIX *B)
{   
    // if the dimensions of both matrices are not equal
    // print a message
    if (A->GetRows() != B->GetRows() || A->GetCols() != B->GetCols())
    {
        // return a 0 matrix of order 1x1 with 
        // Error Code = INVALID MATRIX DIMENSIONS
        int error_code = CustomErrorCode::ERROR__MATRIX_DIMENSIONS_MISMATCH_ERROR;
        return new MATRIX(1, 1, 0.00, error_code);
    }

    // create a matrix to hold the sum of the matrix A and matrix B
    MATRIX *result = new MATRIX(A->GetRows(), A->GetCols());

    // add the corresponding elements of the matrix
    // outer loop (i) to iterate over the rows
    for (int i = 0 ; i < A->GetRows() ; i++) {

        // inner loop (j) to iterate over the cols
        for (int j = 0 ; j < A->GetCols() ; j++) {
            int element = A->GetMatrixElement(i, j) + B->GetMatrixElement(i, j);
            result->SetMatrixElement(i, j, element); 
        }
    }

    // return the resultant matrix
    return result;
}