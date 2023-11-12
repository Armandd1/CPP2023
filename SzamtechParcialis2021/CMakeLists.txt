cmake_minimum_required(VERSION 3.26)
project(SzamtechParcialis2021)

set(CMAKE_CXX_STANDARD 23)

add_executable(SzamtechParcialis2021 main.cpp
        Video.cpp
        Video.h
        PlayList.cpp
        PlayList.h)
