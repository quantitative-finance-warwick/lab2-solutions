#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "compare_files.hpp"

void compare_files(const std::string &file1, const std::string &file2)
{
    std::ifstream file1_stream(file1);
    std::ifstream file2_stream(file2);

    if (!file1_stream.is_open())
        throw std::runtime_error("compare_files: Failed to open file: " + file1);

    if (!file2_stream.is_open())
        throw std::runtime_error("compare_files: Failed to open file: " + file2);

    std::string line_file1, line_file2;
    size_t line_number = 0;

    while (true)
    {
        std::getline(file1_stream, line_file1);
        std::getline(file2_stream, line_file2);
        line_number++;

        if (file1_stream.eof() && file2_stream.eof())
            break;

        if (file1_stream.eof())
        {
            std::ostringstream error_message;
            error_message << "compare_files: " << file1 << " ended at line " << line_number << " but " << file2 << " continues" << std::endl;
            throw std::runtime_error(error_message.str());
        }

        if (file2_stream.eof())
        {
            std::ostringstream error_message;
            error_message << "compare_files: " << file2 << " ended at line " << line_number << " but " << file1 << " continues" << std::endl;
            throw std::runtime_error(error_message.str());
        }

        if (line_file1 != line_file2)
        {
            std::ostringstream error_message;
            error_message << "compare_files: The files differ at line " << line_number << std::endl;
            error_message << "Where " << file1 << " is: " << line_file1 << std::endl;
            error_message << "Where " << file2 << " is: " << line_file2 << std::endl;
            throw std::runtime_error(error_message.str());
        }
    }
}
