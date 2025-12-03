cmake_minimum_required(VERSION 3.28)
project(untitled CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled
        main.cpp
        List.h
        Queue.h
        ListChar.h
        ListInt.h
        QueueInt.h
        QueueChar.h
        ListChar.cpp
        ListInt.cpp
        QueueChar.cpp
        QueueInt.cpp
)
