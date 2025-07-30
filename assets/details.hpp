#pragma once
#include "../matxlib.hpp"
#include "configurations.hpp"

namespace configs
{
    void details()
    {
        static bool ALREADY_PRINTED = false;
        if (ALREADY_PRINTED)
            return;

        std::cout << R"(

   _____ ______   ________  _________   ___    ___ ___       ___  ________     
  |\   _ \  _   \|\   __  \|\___   ___\|\  \  /  /|\  \     |\  \|\   __  \    
  \ \  \\\__\ \  \ \  \|\  \|___ \  \_|\ \  \/  / | \  \    \ \  \ \  \|\ /_   
   \ \  \\|__| \  \ \   __  \   \ \  \  \ \    / / \ \  \    \ \  \ \   __  \  
    \ \  \    \ \  \ \  \ \  \   \ \  \  /     \/   \ \  \____\ \  \ \  \|\  \ 
     \ \__\    \ \__\ \__\ \__\   \ \__\/  /\   \    \ \_______\ \__\ \_______\
      \|__|     \|__|\|__|\|__|    \|__/__/ /\ __\    \|_______|\|__|\|_______|
                                       |__|/ \|__|                             


               ________  ________  ________                                   
              |\   ____\|\   __  \|\   __  \                                  
  ____________\ \  \___|\ \  \|\  \ \  \|\  \                                 
 |\____________\ \  \    \ \   ____\ \   ____\                                
 \|____________|\ \  \____\ \  \___|\ \  \___|                                
                 \ \_______\ \__\    \ \__\                                   
                  \|_______|\|__|     \|__|                                   

)";

        const int IWIDTH = CONST_WIDTH;

        auto print_separator = [IWIDTH]()
        {
            std::cout << "+" << std::string(IWIDTH - 2, '=') << "+\n";
        };

        auto print_rows_desc = [IWIDTH](const std::string &label, const std::string &value)
        {
            std::cout << "| " << label;
            int padding = IWIDTH - 4 - label.length() - value.length();
            std::cout << std::string(padding > 0 ? padding : 0, ' ') << value << " |\n";
        };

        auto print_wrapped = [IWIDTH](const std::string &text)
        {
            const int inner_width = IWIDTH - 4;
            for (size_t i = 0; i < text.length(); i += inner_width)
            {
                std::string line = text.substr(i, inner_width);
                int padding = inner_width - line.length();
                std::cout << "| " << line << std::string(padding, ' ') << " |\n";
            }
        };

        print_separator();
        print_separator();
        print_wrapped(MATXLIB_CPP_DESCRIPTION);

        const std::string CompileTime = __DATE__ + std::string(" ") + __TIME__;
        const int WIDTH = CONST_WIDTH;

        auto print_row = [WIDTH](const std::string &label, const std::string &value)
        {
            std::cout << "| " << label;
            int padding = WIDTH - 4 - label.length() - value.length();
            std::cout << std::string(padding > 0 ? padding : 0, ' ') << value << " |\n";
        };

        std::cout << "+" << std::string(WIDTH - 2, '=') << "+\n";
        print_row("LIBRARY NAME :", MATXLIB_CPP_NAME);
        std::cout << "+" << std::string(WIDTH - 2, '=') << "+\n";
        print_row("VERSION :", MATXLIB_CPP_VERSION);
        std::cout << "+" << std::string(WIDTH - 2, '=') << "+\n";
        print_row("LIBRARY AUTHOR :", MATXLIB_CPP_AUTHOR);
        std::cout << "+" << std::string(WIDTH - 2, '=') << "+\n";
        print_row("GITHUB REPO LINK :", MATXLIB_CPP_GITHUB);
        std::cout << "+" << std::string(WIDTH - 2, '=') << "+\n";
        print_row("COMPILED DATETIME :", CompileTime);
        std::cout << "+" << std::string(WIDTH - 2, '=') << "+\n";

        std::string compiler;
#if defined(__clang__)
        compiler = "Clang/LLVM";
#elif defined(__GNUC__) || defined(__GNUG__)
        compiler = "GCC";
#elif defined(_MSC_VER)
        compiler = "MSVC";
#else
        compiler = "Unknown";
#endif
        print_row("COMPILER USED : ", compiler);
        std::cout << "+" << std::string(WIDTH - 2, '=') << "+\n";

        std::string cpp_version;
#if __cplusplus == 199711L
        cpp_version = "C++98/03";
#elif __cplusplus == 201103L
        cpp_version = "C++11";
#elif __cplusplus == 201402L
        cpp_version = "C++14";
#elif __cplusplus == 201703L
        cpp_version = "C++17";
#elif __cplusplus == 202002L
        cpp_version = "C++20";
#elif __cplusplus > 202002L
        cpp_version = "C++23 or newer";
#else
        cpp_version = "Unknown";
#endif
        print_row("C++ STANDARD :", cpp_version);
        std::cout << "+" << std::string(WIDTH - 2, '=') << "+\n";

        std::string os;
#if defined(_WIN32)
        os = "Windows";
#elif defined(__linux__)
        os = "Linux";
#elif defined(__APPLE__)
        os = "macOS";
#else
        os = "Unknown";
#endif
        print_row("OS (OPERATING SYSTEM) DETECTED : ", os);

        std::cout << "+" << std::string(WIDTH - 2, '=') << "+\n";
        print_row("NOTE : ", MATXLIB_CPP_NOTE);
        std::cout << "+" << std::string(WIDTH - 2, '=') << "+\n";
        std::cout << "+" << std::string(WIDTH - 2, '=') << "+\n";
        ALREADY_PRINTED = true;
    }
}