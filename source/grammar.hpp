#pragma once

#include <vector>
#include <random>
#include <iostream>
#include <string>

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
public:
    Grammar();
    Grammar(std::initializer_list<Entry> init);

    void addEntry(T value, int weight);

    T operator()(std::default_random_engine& re) const;

    std::string to_string() const;
};

template<class T>
std::ostream& operator<<(std::ostream& os, const Grammar<T>& gram);

/////////////////////////////////////
// Function Definitions
/////////////////////////////////////

template<class T>
Grammar<T>::Grammar() {}

template<class T>
Grammar<T>::Grammar(std::initializer_list<Entry> init)
{
    entries = init;
}

template<class T>
void Grammar<T>::addEntry(T value, int weight) {
    Entry e{value, weight};
    entries.push_back(e);
}

template<class T>
T Grammar<T>::operator()(std::default_random_engine& re) const {
    int sum = 0;
    for (const Entry& e : entries) {
        sum += e.weight;
    }

    std::uniform_int_distribution<int> dist{1, sum};
    int choice = dist(re);

    T result;
    int currentSum = 0;
    for (const Entry& e : entries) {
        currentSum += e.weight;
        if (currentSum >= choice) {
            result = e.value;
            break;
        }
    }

    return result;
}

template<class T>
std::string Grammar<T>::to_string() const {
    std::string result = "Size: " + std::to_string(entries.size()) + "\n";
    for (const Entry& e : entries) {
        result += "\tVal: " + std::to_string(e.value) + "\tWeight: " + std::to_string(e.weight) + "\n";
    }
    return result;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const Grammar<T>& gram) {
    return os << gram.to_string();
}