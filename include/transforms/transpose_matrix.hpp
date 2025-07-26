#include "../core/class.hpp"
#include "../core/constructor.hpp"
#include "../core/destructor.hpp"
#include "../core/error_codes.hpp"

#pragma once

/***********************************************************************
 * @brief RETURNS a `POINTER` to a new `MATRIX` object representing the
 * transpose of the `matrix` of the current `MATRIX` object
 *
 * @return MATRIX * (`POINTER` to a new `MATRIX` object)
 *
 * @file transforms/transpose_matrix.hpp
 **********************************************************************/
MATRIX *MATRIX::GetTransposeMatrix()
{
    // create a new matrix to hold the transpose of the input matrix

    int TransposedMatrixRows = this->GetCols();
    int TransposedMatrixCols = this->GetRows();

    // create a new matrix to hold the transpose of the input matrix
    MATRIX *transposed = new MATRIX(TransposedMatrixRows, TransposedMatrixCols, 0.0000);

    for (int i = 0; i < TransposedMatrixRows; i++)
    {
        for (int j = 0; j < TransposedMatrixCols; j++)
        {
            double element = this->GetMatrixElement(j, i);
            transposed->SetMatrixElement(i, j, element);
        }
    }

    // return the transposed matrix
    return transposed;
}
