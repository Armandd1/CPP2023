cmake_minimum_required(VERSION 3.26)
project(lab07)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab07 main.cpp
        answer.cpp
        answer.h
        question.cpp
        question.h
        quiz.cpp
        quiz.h
        quizgame.cpp
        quizgame.h)
