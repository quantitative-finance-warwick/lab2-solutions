#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <filesystem>

#include "compare_files.hpp"
#include "capture_output.hpp"

void test_text_input(const std::filesystem::path &my_exe, const std::filesystem::path &my_input, const std::filesystem::path &my_actual, const std::filesystem::path &my_expected)
{
    const std::filesystem::path root = PROJECT_ROOT_DIR;

    const std::filesystem::path cmd = root / "build" / "tests" / my_exe;
    const std::filesystem::path input = root / "tests" / "IO" / my_input;
    const std::filesystem::path actual = root / "tests" / "IO" / my_actual;
    const std::filesystem::path expected = root / "tests" / "IO" / my_expected;

    REQUIRE_NOTHROW(capture_output(cmd.string(), input.string(), actual.string()));
    REQUIRE_NOTHROW(compare_files(actual.string(), expected.string()));
}

TEST_CASE("Input 1", "[compare_output]")
{
    test_text_input("test_ex6", "number_summer_input1.txt", "number_summer_actual1.txt", "number_summer_output1.txt");
}

TEST_CASE("Input 2", "[compare_output]")
{
    test_text_input("test_ex6", "number_summer_input2.txt", "number_summer_actual2.txt", "number_summer_output2.txt");
}

TEST_CASE("Input 3", "[compare_output]")
{
    test_text_input("test_ex6", "number_summer_input3.txt", "number_summer_actual3.txt", "number_summer_output3.txt");
}

TEST_CASE("Input 4", "[compare_output]")
{
    test_text_input("test_ex6", "number_summer_input4.txt", "number_summer_actual4.txt", "number_summer_output4.txt");
}