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

TEST_CASE("Check ex4 output", "[compare_output]")
{
    const std::filesystem::path root = PROJECT_ROOT_DIR;

    const std::filesystem::path cmd = root / "build" / "tests" / "test_ex4";
    const std::filesystem::path actual = root / "tests" / "IO" / "ex4_actual.txt";
    const std::filesystem::path expected = root / "tests" / "IO" / "ex4_5_output.txt";

    REQUIRE_NOTHROW(capture_output(cmd.string(),  actual.string()));
    REQUIRE_NOTHROW(compare_files(actual.string(), expected.string()));
}


TEST_CASE("Check ex5 output", "[compare_output]")
{
    const std::filesystem::path root = PROJECT_ROOT_DIR;

    const std::filesystem::path cmd = root / "build" / "tests" / "test_ex5";
    const std::filesystem::path actual = root / "tests" / "IO" / "ex5_actual.txt";
    const std::filesystem::path expected = root / "tests" / "IO" / "ex4_5_output.txt";

    REQUIRE_NOTHROW(capture_output(cmd.string(),  actual.string()));
    REQUIRE_NOTHROW(compare_files(actual.string(), expected.string()));
}
