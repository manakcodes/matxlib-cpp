<link rel="stylesheet" href="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/devicon.min.css">

<p align="center">
  <img src="assets/matxlib-cpp.jpg" alt="matxlib-cpp"/>
</p>

# `matxlib-cpp`

> A lightweight, minimal C++ library for matrix abstractions, arithmetic, and analytical utilities.

## 📦 About

`matxlib-cpp` is a **header-only matrix library** built in `C++`. It's written from scratch as a personal project to understand how such libraries work under the hood. It supports basic matrix creation, manipulation, and arithmetic, descriptive and statistical operations.

⚠️ **NOTE** : This library is made for learning purposes and doesn't guarantee high performance or full numerical stability like professional libraries.

---

📌 Features

- 📐 Matrix Construction: basic creation, initialization, and memory management
- ➕ Arithmetic Operations: element-wise and scalar operations (add, subtract, multiply, divide)
- 📊 Descriptive Statistics: mean, min, max, sum, and other aggregations
- 🔁 Transformations: transpose, sparse matrix representation, etc.
- 🧠 Utility Functions: clean utility wrappers, macros and ERROR_CODES.
- 🖨️ Input/Output: easy matrix display and input
- 📂 Modular Design: every operation is split into clear, reusable headers
- ⚙️ Self-contained: no external dependencies

---

## ⚙️ Library Requirements

- C++ Compiler with support for C++11 or higher (e.g., g++, clang++, or MSVC)
- Make (optional) if using the provided Makefile
- Git to clone the repository (or download ZIP manually)

No external libraries or dependencies are required — it’s built with standard `C++` only.

---

## 🏗️ Tools And Tech Used:

<p align="left">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/cplusplus/cplusplus-original.svg" width="60" alt="g++" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/git/git-original.svg" width="60" alt="Git" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/github/github-original.svg" width="60" alt="GitHub" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/bash/bash-original.svg" width="60" alt="Bash" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/vscode/vscode-original.svg" width="60" alt="VS Code" />
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/xcode/xcode-original.svg" width="60" alt="Xcode" />
</p>

---

## 🛠️ Project Setup (First-Time Use):

1. Open your terminal (or command prompt).

2. Navigate to the directory where you want to place the project (e.g., Desktop).

   ```bash
   cd ~/Desktop
   ```

3. Paste the following command in the terminal (or command prompt):

   ```bash
   git clone https://github.com/manakcodes/matxlib-cpp.git
   ```

4. Include the following header in your C++ program to use the library (or adjust the path accordingly).

   ```cpp
   #include "matxlib-cpp/matxlib.hpp"
   ```

5. You can use the library in your C++ programs like you normally do in any code editor or IDE (e.g., VSCode, CLion, Vim, Atom etc.).

---

## 🐙 Every Time You Start a New Project:

After the first-time setup, follow these steps each time you use the library in a new C++ project:

1. Make sure your project file (e.g., your_file.cpp) is in the same directory level or you correctly reference the path to the library (or adjust the path accordingly).

2. Include the following header:

   ```cpp
   #include "matxlib-cpp/matxlib.hpp"
   ```

3. Compile with g++ or your preferred compiler. If needed, link any required flags or paths:

   ```bash
   g++ main.cpp -o main
   ```

   ```bash
   ./main
   ```

4. You’re good to go !

---

## 📁 EXAMPLES

```cpp
#include "matxlib-cpp/matxlib.hpp"

int main() {
    size_t rows = 3;
    size_t cols = 3;
    MATRIX* m = new MATRIX(rows, cols);
    m->RandomizeMatrixInt(1, 10);
    m->PrintMatrix();
    delete m;
    return 0;
}
```

```bash

+------------+------------+------------+
| 5.0000     | 1.0000     | 6.0000     |
+------------+------------+------------+
| 5.0000     | 9.0000     | 6.0000     |
+------------+------------+------------+
| 7.0000     | 8.0000     | 10.0000    |
+------------+------------+------------+
```

more examples soon to be added in a dedicated examples/ folder.

---

## ❓ Why It Exists

I built `matxlib-cpp` simply because I wanted to create my own matrix library from scratch - as a fun learning project to explore C++ and better understand how things work under the hood.

---

## 📁 Directory Structure

```bash
.
├── assets  # <-- ASCII art, configuration macros, and images
│   ├── configurations.hpp
│   ├── details.hpp
│   ├── matxlib-cpp-ascii.jpg
│   └── matxlib-cpp.jpg
├── include  # <-- core library headers
│   ├── arithmetic  # <-- arithmetic operations on matrices
│   │   ├── add_a_scalar_to_matrix.hpp
│   │   ├── add_matrix.hpp
│   │   ├── divide_matrix_by_a_scalar.hpp
│   │   ├── multiply_matrix_by_a_scalar.hpp
│   │   ├── multiply_matrix_element_wise.hpp
│   │   ├── multiply_matrix.hpp
│   │   ├── subtract_matrix.hpp
│   │   └── subtract_scalar_from_matrix.hpp
│   ├── core  # <-- MATRIX class, ctor/dtor, accessors, etc
│   │   ├── class.hpp
│   │   ├── constructor.hpp
│   │   ├── destructor.hpp
│   │   ├── error_codes.hpp
│   │   └── getters_and_setters.hpp
│   ├── descriptive  # <-- descriptive statistics and summaries
│   │   └── descriptive_methods.hpp
│   ├── io  # <-- Input/Output utilities
│   │   └── input_output_matrix.hpp
│   ├── statistics  # <-- statistical functions
│   │   └── statistics_methods.hpp
│   ├── transforms  # <-- MATRIX transformations
│   │   ├── sparse_matrix.hpp
│   │   └── transpose_matrix.hpp
│   └── utility  # <-- miscellaneous utilities
│       └── utility_matrix.hpp
├── LICENSE  # <-- LICENSE
├── Main.cpp  # <-- Main
├── Makefile  # <-- Makefile
├── matxlib.hpp  # <-- ** MAIN INCLUDE HEADER **
├── README.md  # <-- you are here :)
└── test.cpp  # <-- tester file

10 directories, 28 files
```

---

## 🪪 LICENSE

This project is licensed under the MIT License - see [LICENSE](https://github.com/manakcodes/matxlib-cpp/blob/c6b3246dca12c712395c963e9df49b016b3fdd8b/LICENSE) for details.
