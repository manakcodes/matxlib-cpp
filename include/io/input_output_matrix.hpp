#include "../core/class.hpp"
#include "../core/constructor.hpp"
#include "../core/destructor.hpp"
#include "../core/error_codes.hpp"
#pragma once

/***********************************************************************
 * @brief prompts the user to INPUT the elements of `matrix` (row wise)
 * of the current `MATRIX` object
 *
 * @return void
 *
 * @file io/input_output_methods.hpp
 **********************************************************************/
void MATRIX::InputMatrixRowWise()
{
    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

/***********************************************************************
 * @brief INPUTS a `POINTER` to an array of type `double` and its size
 *        then populates the `matrix` of current `MATRIX` object from
 *        that array `(row wise)`
 *
 * @param arr `POINTER` to an array of type `double` (type required ->
 * `double *`)
 * @param ArraySize size of the array (type required -> `size_t`)
 *
 * @return void
 *
 * @file io/input_output_methods.hpp
 **********************************************************************/
void MATRIX::InputMatrixRowWise(double *arr, size_t ArraySize)
{
    if (ArraySize == (this->rows * this->cols))
    {
        int index = 0;
        for (size_t i = 0; i < this->rows; i++)
        {
            for (size_t j = 0; j < this->cols; j++)
            {
                this->matrix[i][j] = arr[index++];
            }
        }
    }

    else
    {
        std::cout << "INVALID ARRAY SIZE" << std::endl;
        return;
    }
}

/***********************************************************************
 * @brief prompts the user to INPUT the elements of `matrix` (columns
 * wise) of the current `MATRIX` object
 *
 * @return void
 *
 * @file io/input_output_methods.hpp
 **********************************************************************/
void MATRIX::InputMatrixColumnWise()
{
    for (size_t j = 0; j < this->cols; j++)
    {
        for (size_t i = 0; i < this->rows; ++i)
        {
            std::cin >> matrix[i][j];
        }
    }
}

/***********************************************************************
 * @brief INPUTS a `POINTER` to an array of type `double` and its size
 *        then populates the `matrix` of current `MATRIX` object from
 *        that array `(column wise)`
 *
 * @param arr `POINTER` to an array of type `double` (type required ->
 * `double *`)
 * @param ArraySize size of the array (type required -> `size_t`)
 *
 * @return void
 * @file io/input_output_methods.hpp
 **********************************************************************/
void MATRIX::InputMatrixColumnWise(double *arr, size_t ArraySize)
{
    if (ArraySize == (this->rows * this->cols))
    {
        int index = 0;
        for (size_t j = 0; j < this->cols; j++)
        {
            for (size_t i = 0; i < this->rows; ++i)
            {
                this->matrix[i][j] = arr[index++];
            }
        }
    }
    else
    {
        std::cout << "INVALID ARRAY SIZE" << std::endl;
        return;
    }
}
