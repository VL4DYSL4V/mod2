cmake_minimum_required(VERSION 3.17)
project(list)

set(CMAKE_CXX_STANDARD 20)

add_executable(list
        collection/LinkedList.cpp
        collection/ArrayList.cpp
        collection/TreeSet.cpp
        exception/IndexOutOfBoundsException.cpp
        main.cpp)