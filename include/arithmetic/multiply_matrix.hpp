
#pragma once
#include "../core/class.hpp"
#include "../core/constructor.hpp"
#include "../core/destructor.hpp"
#include "../core/error_codes.hpp"



MATRIX *MultiplyMatrix(MATRIX *A, MATRIX *B)
{

    // check if the product of matrices is defined or not

    // the product of 2 matrices are defined if the columns of the first
    // matrix is equal to the rows of the second matrix
    if (A->GetCols() != B->GetRows())
    {
        return new MATRIX(1, 1, 0.0000, CustomErrorCode::ERROR__MATRIX_CANNOT_BE_MULTIPLIED);
    }

    // create a var to hold the no. of rows and no. of cols of the
    // matrix which is the resultant of the product of the matrix A and
    // matrix B
    size_t ResultantMatrixRows = A->GetRows();
    size_t ResultantMatrixCols = B->GetCols();

    size_t SharedDimension = A->GetCols();

    // create a new matrix to hold the product of the matrix A and matrix B
    MATRIX *result = new MATRIX(ResultantMatrixRows, ResultantMatrixCols, 0.0000);

    // multiply the matrices
    // outer loop (i) to iterate over the rows
    for (int i = 0; i < ResultantMatrixRows; i++)
    {

        // inner loop (j) to iterate over the rows
        for (int j = 0; j < ResultantMatrixCols; j++)
        {

            // variable to set the elements of the multiplied matrix
            double MultipliedSum = 0.0000;

            // =============================================================
            // NOTE
            // =============================================================
            // inner loop (k) to iterate over the common dimension of
            // both the matrices (common dimension = A->cols, B->rows)
            // [order of A : m x n], [order of B : n x p],
            // [common dimension] = n
            // you can use any of the common dimension of both the matrices
            // i.e you can use either A->cols or B->rows to loop over the
            // elements for the k-th nested loop, im using A->cols
            
            for (int k = 0; k < SharedDimension; k++)
            {

                double a_ik = A->GetMatrixElement(i, k);
                double b_kj = B->GetMatrixElement(k, j);
                double multiplied = (a_ik * b_kj);
                MultipliedSum += multiplied;

            }
            result->SetMatrixElement(i, j, MultipliedSum);
        }
    }

    // return the resultant matrix
    return result;
}