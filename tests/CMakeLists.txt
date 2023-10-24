# expose project root directory to source code so it can find the files
add_definitions(-DPROJECT_ROOT_DIR="${CMAKE_SOURCE_DIR}")

# Executable program which generates Exercise 1 output
set(SRC_FILES_OUTPUT_GEN ${CMAKE_SOURCE_DIR}/src/exercises.c test_ex1.c)
add_executable(test_ex1 ${SRC_FILES_OUTPUT_GEN})
target_include_directories(test_ex1 PUBLIC ${CMAKE_SOURCE_DIR}/src)

# Executable program which generates Exercise 2 output
set(SRC_FILES_OUTPUT_GEN ${CMAKE_SOURCE_DIR}/src/exercises.c test_ex2.c)
add_executable(test_ex2 ${SRC_FILES_OUTPUT_GEN})
target_include_directories(test_ex2 PUBLIC ${CMAKE_SOURCE_DIR}/src)

# Executable program which generates Exercise 3 output
set(SRC_FILES_OUTPUT_GEN ${CMAKE_SOURCE_DIR}/src/exercises.c test_ex3.c)
add_executable(test_ex3 ${SRC_FILES_OUTPUT_GEN})
target_include_directories(test_ex3 PUBLIC ${CMAKE_SOURCE_DIR}/src)

# Executable program which generates Exercise 4 output
set(SRC_FILES_OUTPUT_GEN ${CMAKE_SOURCE_DIR}/src/exercises.c test_ex4.c)
add_executable(test_ex4 ${SRC_FILES_OUTPUT_GEN})
target_include_directories(test_ex4 PUBLIC ${CMAKE_SOURCE_DIR}/src)

# Executable program which generates Exercise 5 output
set(SRC_FILES_OUTPUT_GEN ${CMAKE_SOURCE_DIR}/src/exercises.c test_ex5.c)
add_executable(test_ex5 ${SRC_FILES_OUTPUT_GEN})
target_include_directories(test_ex5 PUBLIC ${CMAKE_SOURCE_DIR}/src)

# Executable program which generates Exercise 6 output
set(SRC_FILES_OUTPUT_GEN ${CMAKE_SOURCE_DIR}/src/exercises.c test_ex6.c)
add_executable(test_ex6 ${SRC_FILES_OUTPUT_GEN})
target_include_directories(test_ex6 PUBLIC ${CMAKE_SOURCE_DIR}/src)

# exercise 1 test
set(SRC_FILES check_ex1.cpp compare_files.cpp capture_output.cpp)
add_executable(check_ex1 ${SRC_FILES})
target_link_libraries(check_ex1)
target_include_directories(check_ex1 PUBLIC ${CMAKE_SOURCE_DIR}/extern/catch2)
add_test(NAME check_ex1 COMMAND check_ex1)

# exercise 2 test
set(SRC_FILES check_ex2.cpp compare_files.cpp capture_output.cpp)
add_executable(check_ex2 ${SRC_FILES})
target_link_libraries(check_ex2)
target_include_directories(check_ex2 PUBLIC ${CMAKE_SOURCE_DIR}/extern/catch2)
add_test(NAME check_ex2 COMMAND check_ex2)

# exercise 3 test
set(SRC_FILES check_ex3.cpp compare_files.cpp capture_output.cpp)
add_executable(check_ex3 ${SRC_FILES})
target_link_libraries(check_ex3)
target_include_directories(check_ex3 PUBLIC ${CMAKE_SOURCE_DIR}/extern/catch2)
add_test(NAME check_ex3 COMMAND check_ex3)

# exercise 4 and 5 test
set(SRC_FILES check_ex4_5.cpp compare_files.cpp capture_output.cpp)
add_executable(check_ex4_5 ${SRC_FILES})
target_link_libraries(check_ex4_5)
target_include_directories(check_ex4_5 PUBLIC ${CMAKE_SOURCE_DIR}/extern/catch2)
add_test(NAME check_ex4_5 COMMAND check_ex4_5)

# exercise 6 test
set(SRC_FILES check_ex6.cpp compare_files.cpp capture_output.cpp)
add_executable(check_ex6 ${SRC_FILES})
target_link_libraries(check_ex6)
target_include_directories(check_ex6 PUBLIC ${CMAKE_SOURCE_DIR}/extern/catch2)
add_test(NAME check_ex6 COMMAND check_ex6)