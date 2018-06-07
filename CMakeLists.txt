cmake_minimum_required(VERSION 3.9)
project(trade_2017)

set(CMAKE_CXX_STANDARD 11)

add_executable(trade_2017
        src/Bot.cpp
        src/Bot.hpp
        src/Buy.cpp
        src/Buy.hpp
        src/MarketPlace.cpp
        src/MarketPlace.hpp
        src/parser/JsonParser.cpp
        src/parser/JsonParser.hpp)
