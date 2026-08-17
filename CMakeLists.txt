cmake_minimum_required(VERSION 3.16)

project(course_planner VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(course_planner_lib
    src/all_of_rule.cpp
    src/any_of_rule.cpp
    src/eligibility_checker.cpp
    src/has_completed_unit_rule.cpp
    src/planned_unit.cpp
    src/student.cpp
    src/unit.cpp
)

target_include_directories(course_planner_lib PUBLIC src)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(course_planner_lib PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
    target_compile_options(course_planner_lib PRIVATE /W4)
endif()

add_executable(course_planner src/main.cpp)
target_link_libraries(course_planner PRIVATE course_planner_lib)

enable_testing()

add_executable(course_planner_tests tests/eligibility_checker_tests.cpp)
target_link_libraries(course_planner_tests PRIVATE course_planner_lib)
add_test(NAME eligibility_checker COMMAND course_planner_tests)
