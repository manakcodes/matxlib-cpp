#pragma once
#include "../core/class.hpp"
#include "../core/constructor.hpp"
#include "../core/destructor.hpp"
#include "../core/error_codes.hpp"

/***********************************************************************
 * @brief RETURNS a `POINTER` to a new `MATRIX` object representing the
 * sparse form of the current matrix, if sparse conversion is possible
 *
 * If the current `MATRIX` object cannot be converted to a sparse
 * matrix (e.g., if it has too many non-zero elements), then this
 * method returns a new `MATRIX` object with :
 * - `rows = 1`
 * - `cols = 1`
 * - all elements set to `0.0000`
 * - `ERROR_CODE = ERROR__NOT_A_SPARSE_MATRIX`
 *
 * @return MATRIX * (`POINTER` to a new `MATRIX` object)
 *
 * @file transforms/sparse_matrix.hpp
 **********************************************************************/
MATRIX *MATRIX::GetSparseMatrix()
{

    // create a var to hold the no. of zero elements
    int zero_count = 0;

    // create a var to hold the total no. of elements
    int total_elements = (this->GetRows() * this->GetCols());

    for (int i = 0; i < this->GetRows(); i++)
    {
        for (int j = 0; j < this->GetCols(); j++)
        {
            if (std::fabs(this->GetMatrixElement(i, j)) < EPSILON)
            {
                zero_count++;
            }
        }
    }

    // create a var to count the number of non zero elements
    int non_zero_count = (this->GetRows() * this->GetCols()) - (zero_count);

    if (!(zero_count > (total_elements / 2)))
    {

        int error_code = CustomErrorCode::ERROR__NOT_A_SPARSE_MATRIX;
        return MATRIX::INVALID_MATRIX(error_code);
    }

    // define the no. of rows and no. of cols a sparse matrix will have

    // no. of rows in a sparse matrix is equal to the no. of non 0 elements
    size_t SparseMatrixRows = (total_elements - zero_count);

    // there are always 3 cols in a sparse matrix and they are
    // [row_index] [cols_index] [element]
    size_t SparseMatrixCols = 3;

    // allocate the memory for the sparse matrix
    MATRIX *SparseMatrix = new MATRIX(SparseMatrixRows, SparseMatrixCols, 0.00, CustomErrorCode::SUCCESS__MATRIX_IS_SPARSE);

    // fill the sparse matrix

    // var to track the non zero elements
    int k = 0;

    // outer loop (i) to iterate over the rows
    for (int i = 0; i < this->GetRows(); i++)
    {

        // inner loop (j) to iterate over the cols
        for (int j = 0; j < this->GetCols(); j++)
        {

            // if the element is not zero
            // add its row index to the first col of the sparse matrix
            // add its col index to the second col of the sparse matrix
            // add the element to the third col of the matrix
            // then increment the tracker that counts the non zero elements

            // so that it moves 1 step ahead and now points to the second
            // row, and places the row index, col index, element in the
            // second row if next non zero element is found, and so on

            if (std::fabs(this->GetMatrixElement(i, j)) > EPSILON)
            {
                // place the non zero element row index in the first col
                SparseMatrix->SetMatrixElement(k, 0, i);

                // place the non zero element col index in the second col
                SparseMatrix->SetMatrixElement(k, 1, j);

                // place the non zero element in the third col
                SparseMatrix->SetMatrixElement(k, 2, this->GetMatrixElement(i, j));

                // increment the non zero counter so that it now points
                // to the second row
                k++;
            }
        }
    }

    // return the resultant matrix
    return SparseMatrix;
}