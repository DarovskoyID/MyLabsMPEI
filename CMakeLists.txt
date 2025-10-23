cmake_minimum_required(VERSION 3.28)
project(unit_dll_M CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(unit_dll_M SHARED
        unit_dll_M.cpp
        unit_dll_M.h
)

set_target_properties(unit_dll_M PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

add_executable(main_test
        mainDynImport.cpp
#        main.cpp
#        unit_dll_M.cpp
#        unit_dll_M.h
)

target_link_libraries(main_test PRIVATE unit_dll_M)
