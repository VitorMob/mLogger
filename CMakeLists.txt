cmake_minimum_required(VERSION 3.5)

project(mlogger VERSION 0.1)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_FLAGS "-O2 -Os -fno-stack-protector -march=native")

add_library(mlogger SHARED

        src/include/arena.hpp
        src/arena.cpp
        
        src/include/file_manager.hpp
        src/file_manager.cpp
        
        src/mlogger.cpp
        src/include/mlogger.hpp
        )

add_executable(mLoggerUnitTest unit_tests/mLoggerUnitTest.cpp )
target_link_libraries(mLoggerUnitTest mlogger)
