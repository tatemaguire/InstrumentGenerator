cmake_minimum_required(VERSION 4.2.1)

project(InstrumentGenerator)

# Libraries

add_library(Generator)
target_sources(Generator
    PRIVATE
        source/generator.cpp
    PUBLIC
        source/generator.hpp
)

# Test Executable

add_executable(GrammarTest)
target_sources(GrammarTest PRIVATE test/grammarTest.cpp)

# Main Executable

add_executable(InstrumentGenerator)
target_sources(InstrumentGenerator PRIVATE source/main.cpp)
target_link_libraries(InstrumentGenerator PRIVATE Generator)