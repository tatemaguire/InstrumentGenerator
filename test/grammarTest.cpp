#include <iostream>
#include <vector>
#include <random>

#include "../source/grammar.hpp"

int main(int argc, char* argv[]) {

    Grammar<size_t> A;
    A.addEntry(0, 10);
    A.addEntry(1, 1);
    A.addEntry(2, 10);

    std::cout << A << std::endl;
    std::vector<int> results(3);

    std::random_device rd;
    std::default_random_engine re(rd());

    for (int i = 0; i < 20; i++) {
        results[A(re)]++;
    }

    std::cout << "results:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << i << ": " << results[i] << std::endl;
    }

    return 0;
}