cmake_minimum_required(VERSION 3.25)
project(SubwayLineMS)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SubwayLineMS
        input.txt
        Line.h
        Station.h
        VertexNode.cpp
        VertexNode.h)
