cmake_minimum_required(VERSION 3.23)
project(Library)

set(CMAKE_CXX_STANDARD 23)

add_executable(Library
        source/RenterManager.cpp
        source/RentManager.cpp
        source/BookManager.cpp
        source/Rent.cpp
        source/Book.cpp
        source/Repository.cpp
        source/RenterType.cpp
        source/Renter.cpp

        include/BookManager.h
        include/RenterManager.h
        include/RentManager.h
        include/Rent.h
        include/Book.h
        include/Repository.h
        include/RenterType.h
        include/Renter.h

        main.cpp)
