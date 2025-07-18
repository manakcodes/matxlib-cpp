#include "class.hpp"
#include "error_codes.hpp"
#pragma once

// ===================================================
// DESTRUCTOR
// ===================================================
// deallocates the memory allocated by the constructor
// ===================================================
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
