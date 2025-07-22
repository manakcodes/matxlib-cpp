#include "class.hpp"
#include "error_codes.hpp"

#pragma once

/***********************************************************************
 * @brief GETTER
 * for `rows` of the current `MATRIX` object ->
 * (RETURNS the `rows` of the current `MATRIX` object)
 *
 * @return size_t
 *
 * @file core/getters_and_setters.hpp
 **********************************************************************/
size_t MATRIX::GetRows() const
{
    return this->rows;
}

/***********************************************************************
 * @brief GETTER
 * for `cols` of the current `MATRIX` object ->
 * (RETURNS the `cols` of the current `MATRIX` object)
 *
 * @return size_t
 *
 *@file core/getters_and_setters.hpp
 **********************************************************************/
size_t MATRIX::GetCols() const
{
    return this->cols;
}

/***********************************************************************
 * @brief GETTER
 * for the `[i][j] - th` element of `matrix` for the current `MATRIX`
 * object
 * (RETURNS the `[i][j] - th element` of the current `MATRIX` object)
 *
 * @param RowIndex 0 based index of the row (type required -> `size_t`)
 * @param ColIndex 0 based index of the column (type required -> `size_t`)
 * @return double value at the specified index of the matrix i.e `matrix[RowIndex][ColIndex]`
 *
 * @note caller should ensure valid indices, otherwise  for invalid
 * indices the method will return `DBL_MAX`
 *
 * @file core/getters_and_setters.hpp
 **********************************************************************/
double MATRIX::GetMatrixElement(size_t RowIndex, size_t ColIndex) const
{
    if (RowIndex < this->rows && ColIndex < this->cols)
    {
        return this->matrix[RowIndex][ColIndex];
    }
    return DBL_MAX;
}

/***********************************************************************
 * @brief SETTER
 * for the `[i][j] - th` element of `matrix` of the current `MATRIX`
 * object
 * (SETS the `[i][j] - th element` of the`matrix` of the  current
 * `MATRIX` object to the `element specified`)
 *
 * @param RowIndex 0 based index of the row (type required -> `size_t`)
 * @param ColIndex 0 based index of the column (type required ->
 * `size_t`)
 * @param element the value to be assigned at the specified index i.e `
 * [RowIndex][ColIndex] = element` (type required -> `double`) of the
 *
 * @return void
 *
 * @note caller should ensure valid indices, otherwise for invalid
 * indices the method will assign `matrix[RowIndex][ColIndex] = DBL_MAX`
 * to all the elements of the `matrix`
 *
 * @file core/getters_and_setters.hpp
 **********************************************************************/
void MATRIX::SetMatrixElement(size_t RowIndex, size_t ColIndex, double element)
{
    if (RowIndex < this->rows && ColIndex < this->cols)
    {
        this->matrix[RowIndex][ColIndex] = element;
    }
    else

        for (size_t i = 0; i < this->rows; i++)
        {
            for (size_t j = 0; j < this->cols; j++)
            {
                this->matrix[i][j] = DBL_MAX;
            }
        }
}
