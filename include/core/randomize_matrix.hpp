#include "../core/class.hpp"
#include "../core/constructor.hpp"
#include "../core/destructor.hpp"
#include "../core/error_codes.hpp"
#pragma once

// ===========================================================
// METHOD to fill the matrix with random values within the
// LowerLimit and UpperLimit passed
// ===========================================================
void MATRIX::RandomizeMatrixDouble(double lower_limit, double upper_limit)
{
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

void MATRIX::RandomizeMatrixInt(int lower_limit, int upper_limit)
{
    static bool seeded = false;
    if (!seeded)
    {
        srand(static_cast<unsigned>(time(nullptr)));
        seeded = true;
    }

    if (lower_limit >= upper_limit)
    {
        int abs_val = std::abs(upper_limit);
        lower_limit = -abs_val;
        upper_limit = abs_val;
    }

    for (size_t i = 0; i < this->rows; ++i)
    {
        for (size_t j = 0; j < this->cols; ++j)
        {
            int random_value = lower_limit + (rand() % (upper_limit - lower_limit + 1));
            this->matrix[i][j] = static_cast<double>(random_value);
        }
    }
}