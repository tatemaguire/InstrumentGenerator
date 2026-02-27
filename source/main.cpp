#include <iostream>
#include <string>
#include <random>

#include "generator.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <rarity 0-1>" << std::endl;
        return 1;
    }

    float rarity = std::stof(argv[1]);

    std::random_device rd;
    std::default_random_engine re(rd());

    std::string instr = generate_instrument(rarity, re);

    std::cout << instr << std::endl;

    return 0;
}