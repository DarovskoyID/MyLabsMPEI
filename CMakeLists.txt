cmake_minimum_required(VERSION 3.28)
project(unit_dll CXX)

set(CMAKE_CXX_STANDARD 17)

# --- Выбор имени и исходников в зависимости от платформы ---
if(WIN32)
    set(DLL_NAME "unit_dll_W")
    set(SRC_FILE "unit_dll_W.cpp")
    set(HEADER_FILE "unit_dll_W.h")
elseif(APPLE)
    set(DLL_NAME "unit_dll_M")
    set(SRC_FILE "unit_dll_M.cpp")
    set(HEADER_FILE "unit_dll_M.h")
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

# --- Сборка динамической библиотеки ---
add_library(${DLL_NAME} SHARED
        ${SRC_FILE}
        ${HEADER_FILE}
)

set_target_properties(${DLL_NAME} PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# --- Сборка тестового приложения ---
add_executable(main_test
        mainDynImport.cpp
)

target_link_libraries(main_test PRIVATE ${DLL_NAME})
