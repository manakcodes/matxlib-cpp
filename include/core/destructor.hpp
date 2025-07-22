#include "class.hpp"
#include "error_codes.hpp"
#pragma once

/***********************************************************************
 * @brief DESTRUCTOR for the MATRIX class
 *
 * deallocates the dynamically allocated memory used by the
 * `matrix` member (a `POINTER` to a 2D array of type `double`)
 *
 * ensures that no memory leaks occur when a `MATRIX` object is
 * destroyed
 *
 * @file core/destructor.hpp
 **********************************************************************/
MATRIX::~MATRIX()
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
}
