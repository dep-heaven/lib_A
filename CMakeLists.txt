cmake_minimum_required(VERSION 3.16)
project(lib_A VERSION 1.0.0 LANGUAGES CXX)

################################################################################
# Dependencies via list in file

include(FetchContent)

FetchContent_Declare(
  cmake_utilities
  GIT_REPOSITORY https://github.com/daixtrose/cmake_utilities
  GIT_TAG        main
)

# Use a custom file name for dependency files
set(REPOMAN_DEPENDENCIES_FILE_NAME "dependencies.txt" CACHE STRING "")

FetchContent_MakeAvailable(cmake_utilities)


################################################################################
# the library

add_library(${PROJECT_NAME}
    src/lib_A.cpp
)

add_library(Daixtrose::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(
    ${PROJECT_NAME} PUBLIC 
    include
    )

target_link_libraries(
    ${PROJECT_NAME} 
    PUBLIC
    $<BUILD_INTERFACE:Daixtrose::CxxFlags>
    fmt::fmt-header-only
)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME) 
    enable_testing()
    add_subdirectory(test-catch)
endif()

# Packaging omitted  