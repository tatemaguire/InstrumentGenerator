cmake_minimum_required(VERSION 4.2.1)

project(InstrumentGenerator)

add_executable(InstrumentGenerator)
target_sources(InstrumentGenerator
    PRIVATE
        source/main.cpp
)