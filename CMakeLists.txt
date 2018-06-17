cmake_minimum_required(VERSION 3.9)
project(trade_2017)

set(CMAKE_CXX_STANDARD 11)

add_executable(trade_2017
        src/main.cpp
        src/Bot.cpp
        src/Bot.hpp
        src/Stats.hpp
        src/Stats.cpp
        src/Bollinger.cpp
        src/Bollinger.hpp
        src/MarketPlace.cpp
        src/MarketPlace.hpp
        src/parser/Parser.cpp
        src/parser/Parser.hpp)
