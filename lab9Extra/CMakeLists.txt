cmake_minimum_required(VERSION 3.26)
project(lab9Extra)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab9Extra main.cpp
        Account.cpp
        Account.h
        Customer.cpp
        Customer.h
        Bank.cpp
        Bank.h)
