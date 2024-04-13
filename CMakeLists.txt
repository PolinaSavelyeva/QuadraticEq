cmake_minimum_required(VERSION 3.10)
project(QuadraticEq)

set(CMAKE_C_STANDARD 11)

add_library(quadratic_equation STATIC src/quadratic_equation.c)	
target_include_directories(quadratic_equation PUBLIC src)
target_link_libraries(quadratic_equation m)
target_compile_options(quadratic_equation PRIVATE -Wall -g)

add_executable(test_quadratic_equation tests/test_quadratic_equation.c)
target_link_libraries(test_quadratic_equation quadratic_equation)
enable_testing()
add_test(NAME Tests COMMAND test_quadratic_equation)

add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --verbose)
add_custom_target(memcheck 
    COMMAND valgrind --leak-check=full -s ./test_quadratic_equation)
