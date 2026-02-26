#pragma once

#include <vector>
#include <random>
#include <iostream>

/////////////////////////////////////
// Class Declaration
/////////////////////////////////////

template <class T>
class Grammar {
public:
    struct Entry {
        T value;
        int weight;
    };
private:
    std::vector<Entry> entries{};

    std::default_random_engine re;
    std::random_device::result_type seed;
public:
    Grammar();
    Grammar(std::initializer_list<Entry> init);

    void set_seed(std::random_device::result_type seed);
    void addEntry(T value, int weight);

    T operator()();
};

/////////////////////////////////////
// Function Definitions
/////////////////////////////////////

template<class T>
Grammar<T>::Grammar() {
    std::random_device rd;
    seed = rd();
}

template<class T>
Grammar<T>::Grammar(std::initializer_list<Entry> init):
    Grammar()
{
    entries = init;
}

template<class T>
void Grammar<T>::set_seed(std::random_device::result_type num) {
    seed = num;
}

template<class T>
void Grammar<T>::addEntry(T value, int weight) {
    Entry e{value, weight};
    entries.push_back(e);
}

