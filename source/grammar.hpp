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

    std::default_random_engine re;
    std::random_device::result_type seed;
public:
    Grammar();
    Grammar(std::initializer_list<Entry> init);

    void set_seed(std::random_device::result_type seed);
    std::random_device::result_type get_seed();
    void addEntry(T value, int weight);

    T operator()();

    std::string to_string() const;
};

template<class T>
std::ostream& operator<<(std::ostream& os, const Grammar<T>& gram);

/////////////////////////////////////
// Function Definitions
/////////////////////////////////////

template<class T>
Grammar<T>::Grammar() {
    std::random_device rd;
    seed = rd();
    re.seed(seed);
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
    re.seed(seed);
}

template<class T>
std::random_device::result_type Grammar<T>::get_seed() {
    return seed;
}

template<class T>
void Grammar<T>::addEntry(T value, int weight) {
    Entry e{value, weight};
    entries.push_back(e);
}

template<class T>
T Grammar<T>::operator()() {
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