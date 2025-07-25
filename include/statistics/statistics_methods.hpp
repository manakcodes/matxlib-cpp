#include "../core/class.hpp"
#include "../core/constructor.hpp"
#include "../core/destructor.hpp"
#include "../core/error_codes.hpp"

#pragma once

/***********************************************************************
 * @brief RETURNS a `POINTER` to a new `MATRIX` object where each row
 * contains the maximum element of the corresponding row from the
 * `matrix` of the current `MATRIX` object
 *
 * @details The returned `MATRIX` object has:
 * - `rows` = number of rows of the current `matrix`
 * - `cols` = 1
 * - each element at [i][0] = max value of the i-th row of the `matrix`
 * of the current `MATRIX` object
 *
 * @return MATRIX * (`POINTER` to the new `MATRIX` object)
 **********************************************************************/
MATRIX *MATRIX::GetMaxOfEachRow()
{
    MATRIX *RowMaxArray = new MATRIX(this->GetRows(), 1, 0.0000, CustomErrorCode::SUCCESS__ROW_MAX_PARAMETERS);

    for (size_t i = 0; i < this->rows; i++)
    {
        double RowMax = this->matrix[i][0];

        for (size_t j = 0; j < this->cols; j++)
        {
            if (RowMax < this->matrix[i][j])
            {
                RowMax = this->matrix[i][j];
            }
        }
        RowMaxArray->SetMatrixElement(i, 0, RowMax);
    }
    return RowMaxArray;
}

/***********************************************************************
 * @brief RETURNS a `POINTER` to a new `MATRIX` object where each row
 * contains the minimum element of the corresponding row from the
 * `matrix` of the current `MATRIX` object
 *
 * @details The returned `MATRIX` object has:
 * - `rows` = number of rows of the current `matrix`
 * - `cols` = 1
 * - each element at [i][0] = min value of the i-th row of the `matrix`
 * of the current `MATRIX` object
 *
 * @return MATRIX * (`POINTER` to the new `MATRIX` object)
 **********************************************************************/
MATRIX *MATRIX::GetMinOfEachRow()
{
    MATRIX *RowMinArray = new MATRIX(this->GetRows(), 1, 0.0000, CustomErrorCode::SUCCESS__ROW_MIN_PARAMETERS);

    for (size_t i = 0; i < this->rows; i++)
    {
        double RowMin = this->matrix[i][0];

        for (size_t j = 0; j < this->cols; j++)
        {
            if (RowMin > this->matrix[i][j])
            {
                RowMin = this->matrix[i][j];
            }
        }
        RowMinArray->SetMatrixElement(i, 0, RowMin);
    }
    return RowMinArray;
}

/***********************************************************************
 * @brief RETURNS a `POINTER` to a new `MATRIX` object where each row
 * contains the maximum element of the corresponding column from the
 * `matrix` of the current `MATRIX` object
 *
 * @details The returned `MATRIX` object has:
 * - `rows` = number of columns of the current matrix
 * - `cols` = 1
 * - each element at [i][0] = max value of the i-th column of the
 * current matrix
 *
 * @return MATRIX * (`POINTER` to the new `MATRIX` object)
 **********************************************************************/
MATRIX *MATRIX::GetMaxOfEachColumn()
{
    MATRIX *ColumnMaxArray = new MATRIX(cols, 1, 0.0000, CustomErrorCode::SUCCESS__COLUMN_MAX_PARAMETERS);

    for (size_t j = 0; j < this->cols; j++)
    {
        double ColMax = this->matrix[0][j];

        for (size_t i = 1; i < this->rows; i++)
        {
            if (ColMax < this->matrix[i][j])
            {
                ColMax = this->matrix[i][j];
            }
        }
        ColumnMaxArray->SetMatrixElement(j, 0, ColMax);
    }
    return ColumnMaxArray;
}

/***********************************************************************
 * @brief RETURNS a `POINTER` to a new `MATRIX` object where each row
 * contains the minimum element of the corresponding column from the
 * `matrix` of the current `MATRIX` object
 *
 * @details The returned `MATRIX` object has:
 * - `rows` = number of columns of the current matrix
 * - `cols` = 1
 * - each element at [i][0] = min value of the i-th column of the
 * current matrix
 *
 * @return MATRIX * (`POINTER` to the new `MATRIX` object)
 **********************************************************************/
MATRIX *MATRIX::GetMinOfEachColumn()
{
    MATRIX *ColumnMinArray = new MATRIX(cols, 1, 0.0000, CustomErrorCode::SUCCESS__COLUMN_MIN_PARAMETERS);

    for (size_t j = 0; j < this->cols; j++)
    {
        double ColMin = this->matrix[0][j];

        for (size_t i = 1; i < this->rows; i++)
        {
            if (ColMin > this->matrix[i][j])
            {
                ColMin = this->matrix[i][j];
            }
        }
        ColumnMinArray->SetMatrixElement(j, 0, ColMin);
    }
    return ColumnMinArray;
}

/***********************************************************************
 * @brief RETURNS a `POINTER` to a new `MATRIX` object where each row
 * contains the sum of the elements of the corresponding row from the
 * `matrix` of the current `MATRIX` object
 *
 * @details The returned `MATRIX` object has:
 * - `rows` = number of rows of the current `matrix`
 * - `cols` = 1
 * - each element at [i][0] = sum of the elements of the i-th row of
 * the `matrix`
 * of the current `MATRIX` object
 *
 * @return MATRIX * (`POINTER` to the new `MATRIX` object)
 **********************************************************************/
MATRIX *MATRIX::GetSumOfEachRow()
{

    MATRIX *RowSumMatrix = new MATRIX(this->rows, 1, 0.0000, CustomErrorCode::SUCCESS__ROW_SUM_PARAMETERS);

    double RowSum = 0.0000;

    for (size_t i = 0; i < this->rows; i++)
    {
        RowSum = 0.0000;
        for (size_t j = 0; j < this->cols; j++)
        {
            RowSum += this->matrix[i][j];
        }
        RowSumMatrix->SetMatrixElement(i, 0, RowSum);
    }

    return RowSumMatrix;
}

/***********************************************************************
 * @brief RETURNS a `POINTER` to a new `MATRIX` object where each row
 * contains the sum of the elements of the corresponding column from the
 * `matrix` of the current `MATRIX` object
 *
 * @details The returned `MATRIX` object has:
 * - `rows` = number of rows of the current `matrix`
 * - `cols` = 1
 * - each element at [i][0] = sum of the elements of the i-th column of
 * the `matrix`
 * of the current `MATRIX` object
 *
 * @return MATRIX * (`POINTER` to the new `MATRIX` object)
 **********************************************************************/
MATRIX *MATRIX::GetSumOfEachColumn()
{
    MATRIX *ColumnSumMatrix = new MATRIX(this->cols, 1, 0.000, CustomErrorCode::SUCCESS__COLUMN_SUM_PARAMETERS);

    double ColumnSum = 0.0000;

    for (size_t j = 0; j < this->cols; j++)
    {
        ColumnSum = 0.0000;
        for (size_t i = 0; i < this->rows; i++)
        {
            ColumnSum += this->matrix[i][j];
        }
        ColumnSumMatrix->SetMatrixElement(j, 0, ColumnSum);
    }

    return ColumnSumMatrix;
}

/***********************************************************************
 * @brief RETURNS a `POINTER` to a new `MATRIX` object where each row
 * contains the average of the elements of the corresponding row
 * from the `matrix` of the current `MATRIX` object
 *
 * @details The returned `MATRIX` object has:
 * - `rows` = number of rows of the current `matrix`
 * - `cols` = 1
 * - each element at [i][0] = average of the elements of the i-th
 * row of the `matrix` of the current `MATRIX` object
 *
 * @return MATRIX * (`POINTER` to the new `MATRIX` object)
 **********************************************************************/
MATRIX *MATRIX::GetAverageOfEachRow()
{
    MATRIX *RowSumMatrix = this->GetSumOfEachRow();
    RowSumMatrix->ERROR_CODE = CustomErrorCode::SUCCESS__ROW_AVERAGE_PARAMETERS;

    int rows = RowSumMatrix->GetRows();
    int cols = 1;

    for (size_t i = 0; i < rows; i++)
    {
        double element = (RowSumMatrix->GetMatrixElement(i, 0) / this->cols);
        RowSumMatrix->SetMatrixElement(i, 0, element);
    }
    return RowSumMatrix;
}

/***********************************************************************
 * @brief RETURNS a `POINTER` to a new `MATRIX` object where each row
 * contains the average of the elements of the corresponding column
 * from the `matrix` of the current `MATRIX` object
 *
 * @details The returned `MATRIX` object has:
 * - `rows` = number of rows of the current `matrix`
 * - `cols` = 1
 * - each element at [i][0] = average of the elements of the i-th
 * column of the `matrix` of the current `MATRIX` object
 *
 * @return MATRIX * (`POINTER` to the new `MATRIX` object)
 **********************************************************************/
MATRIX *MATRIX::GetAverageOfEachColumn()
{
    MATRIX *ColumnSumMatrix = this->GetSumOfEachColumn();
    ColumnSumMatrix->ERROR_CODE = CustomErrorCode::SUCCESS__COLUMN_AVERAGE_PARAMETERS;

    for (size_t i = 0; i < this->cols; i++)
    {
        double element = ColumnSumMatrix->GetMatrixElement(i, 0) / this->rows;
        ColumnSumMatrix->SetMatrixElement(i, 0, element);
    }

    return ColumnSumMatrix;
}

/***********************************************************************
 * @brief RETURNS the sum of al the elements of the `matrix` of the
 * current `MATRIX` object
 *
 * @return double
 **********************************************************************/
double MATRIX::GetSumOfMatrix()
{
    double MatrixSum = 0.0000;

    size_t rows = this->rows;
    size_t cols = this->cols;

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            MatrixSum += this->matrix[i][j];
        }
    }
    return MatrixSum;
}

/***********************************************************************
 * @brief RETURNS the element with the maximum value from the `matrix`
 * of the current `MATRIX` object
 *
 * @return double
 **********************************************************************/
double MATRIX::GetMaxOfMatrix()
{
    double MaxElement = this->matrix[0][0];

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            if (MaxElement < this->matrix[i][j])
            {
                MaxElement = this->matrix[i][j];
            }
        }
    }
    return MaxElement;
}

/***********************************************************************
 * @brief RETURNS the element with the minimum value from the `matrix`
 * of the current `MATRIX` object
 *
 * @return double
 **********************************************************************/
double MATRIX::GetMinOfMatrix()
{
    double MinElement = this->matrix[0][0];

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            if (MinElement > this->matrix[i][j])
            {
                MinElement = this->matrix[i][j];
            }
        }
    }
    return MinElement;
}

/***********************************************************************
 * @brief RETURNS average of the elements of the `matrix` of the
 * current `MATRIX` object
 *
 * @return double
 **********************************************************************/
double MATRIX::GetAverageOfMatrix()
{
    double SumOfMatrix = this->GetSumOfMatrix();
    double TotalElements = (this->rows * this->cols);
    return (SumOfMatrix / TotalElements);
}

double MATRIX::GetRangeOfMatrix()
{
    return this->GetMaxOfMatrix() - this->GetMinOfMatrix();
}
void MATRIX::PrintMatrixStatisticalParameters()
{
    this->GetMaxOfEachRow()->PrintMatrix();
    this->GetMinOfEachRow()->PrintMatrix();
    this->GetMaxOfEachColumn()->PrintMatrix();
    this->GetMinOfEachColumn()->PrintMatrix();
    this->GetAverageOfEachRow()->PrintMatrix();
    this->GetAverageOfEachColumn()->PrintMatrix();
    std::cout << "max of matrix : " << this->GetMaxOfMatrix() << std::endl;
    std::cout << "min of matrix : " << this->GetMinOfMatrix() << std::endl;
    std::cout << "range of matrix : " << this->GetRangeOfMatrix() << std::endl;
    std::cout << "avg of matrix : " << this->GetAverageOfMatrix() << std::endl;
}