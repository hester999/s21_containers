cmake_minimum_required(VERSION 3.26)
project(s21_containers)

set(CMAKE_CXX_STANDARD 17)

add_executable(s21_containers main.cpp
        s21_containers.h
        s21_queue.h
        s21_queue.tpp)
