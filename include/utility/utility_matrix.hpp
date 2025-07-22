#include "../core/class.hpp"
#include "../core/constructor.hpp"
#include "../core/destructor.hpp"
#include "../core/error_codes.hpp"
#pragma once

/***********************************************************************
 * @brief fills the `matrix` of current `MATRIX` object with the random
 * values of type `double` within the range specified in the method
 *
 * @param lower_limit min value of random double value (type required ->
 * `double`)
 * @param upper_limit max value of random double value (type required ->
 * `double`)
 *
 * @return void
 * @file io/input_output_methods.hpp
 **********************************************************************/
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

/***********************************************************************
 * @brief fills the `matrix` of current `MATRIX` object with the random
 * values of type `int` within the range specified in the method
 *
 * @param lower_limit min value of random int value (type required ->
 * `int`)
 * @param upper_limit max value of random int value (type required ->
 * `int`)
 *
 * @return void
 * @file io/input_output_methods.hpp
 **********************************************************************/
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

MATRIX *MATRIX::INVALID_MATRIX(int ERROR_CODE)
{
    if (ERROR_CODE == -1001 ||
        ERROR_CODE == -1002 ||
        ERROR_CODE == -1003 ||
        ERROR_CODE == -1004 ||
        ERROR_CODE == -1005)
    {
        return new MATRIX(1, 1, 0.0000, ERROR_CODE);
    }
    else
    {
        abort();
    }
}

/***********************************************************************
 * @brief PRINTS the `matrix` of the current `MATRIX` object in a
 * formatted grid-like manner upto 4 decimal places
 *
 * @return void
 *
 * @note in case of printing a sparse matrix (if created by the
 * `GetSparseMatrix()` method) then this method PRINTS the first
 * column and second column as `int` not as `double`
 * @file io/input_output_methods.hpp
 **********************************************************************/
void MATRIX::PrintMatrix()
{

    if (this->ERROR_CODE == CustomErrorCode::SUCCESS__ROW_MAX_PARAMETERS ||
        this->ERROR_CODE == CustomErrorCode::SUCCESS__ROW_MIN_PARAMETERS ||
        this->ERROR_CODE == CustomErrorCode::SUCCESS__COLUMN_MAX_PARAMETERS ||
        this->ERROR_CODE == CustomErrorCode::SUCCESS__COLUMN_MIN_PARAMETERS ||
        this->ERROR_CODE == CustomErrorCode::SUCCESS__ROW_SUM_PARAMETERS ||
        this->ERROR_CODE == CustomErrorCode::SUCCESS__COLUMN_SUM_PARAMETERS ||
        this->ERROR_CODE == CustomErrorCode::SUCCESS__ROW_AVERAGE_PARAMETERS ||
        this->ERROR_CODE == CustomErrorCode::SUCCESS__COLUMN_AVERAGE_PARAMETERS)
    {
        std::string flag = "";
        if (this->ERROR_CODE == CustomErrorCode::SUCCESS__ROW_MAX_PARAMETERS)
        {
            flag = "MAX OF ROW";
        }
        if (this->ERROR_CODE == CustomErrorCode::SUCCESS__COLUMN_MAX_PARAMETERS)
        {
            flag = "MAX OF COLUMN";
        }

        if (this->ERROR_CODE == CustomErrorCode::SUCCESS__ROW_MIN_PARAMETERS)
        {
            flag = "MIN OF ROW";
        }

        if (this->ERROR_CODE == CustomErrorCode::SUCCESS__COLUMN_MIN_PARAMETERS)
        {
            flag = "MIN OF COLUMN";
        }
        if (this->ERROR_CODE == CustomErrorCode::SUCCESS__ROW_SUM_PARAMETERS)
        {
            flag = "SUM OF ROW";
        }

        if (this->ERROR_CODE == CustomErrorCode::SUCCESS__COLUMN_SUM_PARAMETERS)
        {
            flag = "SUM OF COLUMN";
        }
        if (this->ERROR_CODE == CustomErrorCode::SUCCESS__ROW_AVERAGE_PARAMETERS)
        {
            flag = "AVERAGE OF ROW";
        }
        if (this->ERROR_CODE == CustomErrorCode::SUCCESS__COLUMN_AVERAGE_PARAMETERS)
        {
            flag = "AVERAGE OF COLUMN";
        }

        for (size_t l = 0; l < this->cols; l++)
        {
            std::cout << "+-------------------------";
        }
        std::cout << std::endl;

        for (size_t i = 0; i < this->rows; i++)
        {
            std::cout << "| "
                      << std::left << std::setw(10) << flag
                      << std::right << " " << i + 1 << " : "
                      << std::fixed << std::setprecision(4)
                      << this->matrix[i][0]
                      << " |" << std::endl;

            for (size_t l = 0; l < this->cols; l++)
            {
                std::cout << "+-------------------------";
            }
            std::cout << std::endl;
        }
        return;
    }

    if (this->ERROR_CODE != CustomErrorCode::SUCCESS &&
        this->ERROR_CODE != CustomErrorCode::SUCCESS__MATRIX_IS_SPARSE)
    {
        CustomErrorCode::PRINT_ERROR_CODE_MESSAGE(this->ERROR_CODE);
        return;
    }

    std::cout << "\n";

    for (size_t i = 0; i < this->cols; i++)
    {
        std::cout << "+------------";
    }
    std::cout << "+\n";

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            std::cout << "| ";

            if (this->ERROR_CODE == CustomErrorCode::SUCCESS__MATRIX_IS_SPARSE)
            {
                if (j == 0 || j == 1)
                {
                    int index_val = static_cast<int>(matrix[i][j]);
                    std::cout << std::left << std::setw(11) << index_val;
                }
                else
                {
                    std::cout << std::left << std::setw(11) << std::fixed
                              << std::setprecision(4) << matrix[i][j];
                }
            }
            else
            {
                std::cout << std::left << std::setw(11) << std::fixed
                          << std::setprecision(4) << matrix[i][j];
            }
        }

        std::cout << "|\n";

        for (size_t j = 0; j < this->cols; j++)
        {
            std::cout << "+------------";
        }
        std::cout << "+\n";
    }
}

bool MATRIX::HasSameOrder(MATRIX *A, MATRIX *B)
{
    return ((A->GetRows() == B->GetRows()) && (A->GetCols() == B->GetCols()));
}

/***********************************************************************
 * @brief INPUTS a `POINTER` to an object of type `MATRIX` and check if
 * it is equal to the current `MATRIX` object
 *
 * @param other `POINTER` to an object of type `MATRIX` (type required
 * -> `MATRIX`)
 *
 * @return `true`:
 *    - both matrices have the same number of rows and columns, and
 *    - each element [i][j] in both matrices is equal
 *
 * @return `false` otherwise
 *
 * @file io/input_output_methods.hpp
 **********************************************************************/
bool MATRIX::IsEqualTo(MATRIX *other)
{
    if (this->rows == other->rows && this->cols == other->cols)
    {
        for (size_t i = 0; i < this->rows; i++)
        {
            for (size_t j = 0; j < this->cols; j++)
            {
                if (std::fabs(this->matrix[i][j] - other->matrix[i][j]) > EPSILON)
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

MATRIX *MATRIX::GetIdentityMatrix(size_t rows, size_t cols)
{
    MATRIX *matrix = new MATRIX(rows, cols);

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (i == j)
            {
                matrix->SetMatrixElement(i, j, 1.0000);
            }
            else
            {
                matrix->SetMatrixElement(i, j, 0.0000);
            }
        }
    }
    return matrix;
}