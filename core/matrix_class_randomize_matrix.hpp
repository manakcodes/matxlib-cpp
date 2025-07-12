#include "matrix_class.hpp"
#include "matrix_class_error_codes.hpp"
#pragma once

// ===========================================================
// METHOD to fill the matrix with random values within the
// LowerLimit and UpperLimit passed
// ===========================================================
void MATRIX::RandomizeMatrix(double lower_limit, double upper_limit)
{
    // Seed the random generator once
    static bool seeded = false;
    if (!seeded)
    {
        srand(static_cast<unsigned>(time(0)));
        seeded = true;
    }

    if (lower_limit >= upper_limit)
    {
        lower_limit = -(fabs(upper_limit));
        upper_limit = fabs(upper_limit);
    }

    for (size_t i = 0; i < this->rows; ++i)
    {
        for (size_t j = 0; j < this->cols; ++j)
        {
            double scale = rand() / (double)RAND_MAX;
            this->matrix[i][j] = lower_limit + scale * (upper_limit - lower_limit);
        }
    }
}
