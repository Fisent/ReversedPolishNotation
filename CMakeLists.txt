cmake_minimum_required(VERSION 3.6)
project(ReversedPolishNotation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp CNodes/CNode.cpp CNodes/CNode.h CTree.cpp CTree.h CNodes/CNodeValue.cpp CNodes/CNodeValue.h CNodes/CNodeOperator.cpp CNodes/CNodeOperator.h)
add_executable(ReversedPolishNotation ${SOURCE_FILES})