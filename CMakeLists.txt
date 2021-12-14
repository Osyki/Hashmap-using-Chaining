cmake_minimum_required(VERSION 3.20)
project(ch9_hashmap_chaining2)

set(CMAKE_CXX_STANDARD 14)

add_executable(ch9_hashmap_chaining2 main.cpp iterator.h const_iterator.h Hash_Table_Chain.h hash.h Person.cpp Person.h Test_Map_to_string.cpp Test_Person.cpp)
