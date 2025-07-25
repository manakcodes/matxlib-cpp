#include "../core/class.hpp"
#include "../core/constructor.hpp"
#include "../core/destructor.hpp"
#include "../core/error_codes.hpp"

#pragma once

/***********************************************************************
 * @brief RETURNS the number of zero elements present in the `matrix`
 * of current `MATRIX` object
 *
 * @return int
 **********************************************************************/
int MATRIX::GetMatrixZeroElementsCount()
{
    int ZeroCount = 0;
    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            if (std::fabs(this->matrix[i][j]) < EPSILON)
            {
                ZeroCount++;
            }
        }
    }
    return ZeroCount;
}

/***********************************************************************
 * @brief RETURNS the number of non zero elements present in the
 * `matrix` of current `MATRIX` object
 *
 * @return int
 **********************************************************************/
int MATRIX::GetMatrixNonZeroElementsCount()
{
    int TotalElements = this->rows * this->cols;
    int ZeroElements = this->GetMatrixZeroElementsCount();
    return (TotalElements - ZeroElements);
}

/***********************************************************************
 * @brief RETURNS the number of positive elements present in the
 * `matrix` of current `MATRIX` object
 *
 * @return int
 **********************************************************************/
int MATRIX::GetMatrixPositiveElementsCount()
{
    int PositiveCount = 0;
    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            if (this->matrix[i][j] > 0)
            {
                PositiveCount++;
            }
        }
    }
    return PositiveCount;
}

/***********************************************************************
 * @brief RETURNS the number of negative elements present in the
 * `matrix` of current `MATRIX` object
 *
 * @return int
 **********************************************************************/
int MATRIX::GetMatrixNegativeElementsCount()
{
    int NegativeCount = 0;
    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            if (this->matrix[i][j] < 0)
            {
                NegativeCount++;
            }
        }
    }
    return NegativeCount;
}

/***********************************************************************
 * @brief RETURNS the total number of elements present in the
 * `matrix` of current `MATRIX` object
 *
 * @return int
 **********************************************************************/
int MATRIX::GetMatrixTotalElementsCount()
{
    return (this->rows * this->cols);
}

/***********************************************************************
 * @brief RETURNS the density of the `matrix` of current `MATRIX` object
 * `matrix density = non zero elements count / total elements count`
 * @return double
 **********************************************************************/
double MATRIX::GetMatrixDensity()
{
    return (double)(this->GetMatrixNonZeroElementsCount()) / (double)(this->GetMatrixTotalElementsCount());
}

/***********************************************************************
 * @brief PRINTS the descriptive parameters of the `matrix` of the
 * current `MATRIX` object
 * `descriptive parameters : `
 * -`number of total elements`
 * -`number of zero elements`
 * -`number of non zero elements`
 * -`number of positive elements`
 * -`number of negative elements`
 * -`matrix density`
 *
 * @return void
 **********************************************************************/
void MATRIX::PrintMatrixDescriptiveParameters()
{
    std::cout << "{total elements count : " << this->GetMatrixTotalElementsCount() << "}\n";
    std::cout << "{zero elements count : " << this->GetMatrixZeroElementsCount() << "}\n";
    std::cout << "{non zero elements count : " << this->GetMatrixNonZeroElementsCount() << "}\n";
    std::cout << "{positive elements count : " << this->GetMatrixPositiveElementsCount() << "}\n";
    std::cout << "{negative elements count : " << this->GetMatrixNegativeElementsCount() << "}\n";
    std::cout << "{matrix density : " << std::setprecision(4) << this->GetMatrixDensity() << "}\n";
}