#pragma once

class CustomErrorCode
{
public:
    static const int SUCCESS = 0;
    static const int ERROR__MATRIX_DIMENSIONS_MISMATCH_ERROR = -1001;
    static const int ERROR__NOT_A_SPARSE_MATRIX = -1002;
    static const int ERROR__MATRIX_CANNOT_BE_MULTIPLIED = -1003;
    static const int ERROR__ZERO_DIVISION_ERROR = -1004;
    static const int ERROR__INVALID_ROWS_AND_COLUMNS = -1005;
    static const int SUCCESS__MATRIX_IS_SPARSE = 1001;
    static const int SUCCESS__ROW_MIN_PARAMETERS = 1002;
    static const int SUCCESS__ROW_MAX_PARAMETERS = 1003;
    static const int SUCCESS__COLUMN_MAX_PARAMETERS = 1004;
    static const int SUCCESS__COLUMN_MIN_PARAMETERS = 1005;
    static const int SUCCESS__ROW_SUM_PARAMETERS = 1006;
    static const int SUCCESS__COLUMN_SUM_PARAMETERS = 1007;
    static const int SUCCESS__ROW_AVERAGE_PARAMETERS = 1006;
    static const int SUCCESS__COLUMN_AVERAGE_PARAMETERS = 1007;

    static void PRINT_ERROR_CODE_MESSAGE(int ERROR_CODE)
    {
        if (ERROR_CODE == ERROR__MATRIX_DIMENSIONS_MISMATCH_ERROR)
        {
            std::cout << "\n\n";
            std::cout << "\nFOR THIS OPERATION THE ROWS AND COLUMNS OF THE FIRST MATRIX MUST BE EQUAL TO THE ROWS AND COLUMNS OF THE SECOND MATRIX\n";
            std::cout << "\n\n";
        }

        if (ERROR_CODE == ERROR__MATRIX_CANNOT_BE_MULTIPLIED)
        {
            std::cout << "\n\n";
            std::cout << "\nFOR THIS OPERATIONS THE ROWS OF THE FIRST MATRIX MUST BE EQUAL TO THE COLUMNS OF THE SECOND MATRIX\n";
            std::cout << "\n\n";
        }

        if (ERROR_CODE == ERROR__NOT_A_SPARSE_MATRIX)
        {
            std::cout << "\n\n";
            std::cout << "\nINVALID MATRIX !!\n";
            std::cout << "\nFOR A MATRIX TO BE SPARSE\n";
            std::cout << "\nMORE THAN HALF OF THE ELEMENTS OF THE MATRIX MUST BE 0\n";
            std::cout << "\n\n";
        }

        if (ERROR_CODE == ERROR__ZERO_DIVISION_ERROR)
        {
            std::cout << "\n\n";
            std::cout << "\nERROR !!\n";
            std::cout << "\n\n";
        }

        if (ERROR_CODE == ERROR__INVALID_ROWS_AND_COLUMNS)
        {
            std::cout << "\n\n";
            std::cout << "\nERROR !!\n";
            std::cout << "\nROWS AND COLUMNS OF A MATRIX CANNOT BE 0\n";
            std::cout << "\n\n";
        }
    }
};
