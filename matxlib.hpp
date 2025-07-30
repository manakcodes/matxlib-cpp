// to include every header once
#pragma once

// C++ std includes
#include <ctime>
#include <iostream>
#include <string>

// includes from include/core
#include "include/core/class.hpp"
#include "include/core/error_codes.hpp"
#include "include/core/constructor.hpp"
#include "include/core/destructor.hpp"
#include "include/core/getters_and_setters.hpp"
#include "include/utility/utility_matrix.hpp"

// includes from include/arithmetic
#include "include/arithmetic/add_matrix.hpp"
#include "include/arithmetic/subtract_matrix.hpp"
#include "include/arithmetic/multiply_matrix.hpp"
#include "include/arithmetic/multiply_matrix_by_a_scalar.hpp"
#include "include/arithmetic/divide_matrix_by_a_scalar.hpp"

// includes from include/transforms
#include "include/transforms/transpose_matrix.hpp"
#include "include/transforms/sparse_matrix.hpp"

// includes from include/descriptive
#include "include/descriptive/descriptive_methods.hpp"

// includes from include/statistics
#include "include/statistics/statistics_methods.hpp"

// includes from include/io
#include "include/io/input_output_matrix.hpp"

// includes from assets/
#include "assets/details.hpp"
#include "assets/configurations.hpp"
