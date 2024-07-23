cmake_minimum_required(VERSION 3.26)
project(COURSE_WORK)

set(CMAKE_CXX_STANDARD 17)

add_executable(COURSE_WORK main.cpp
        cl_base.cpp
        cl_base.h
        controller.cpp
        controller.h
        giver.cpp
        giver.h
        identifier.cpp
        identifier.h
        printer.cpp
        printer.h
        reader.cpp
        reader.h
        taker.cpp
        taker.h
        cl_application.cpp
        cl_application.h)
