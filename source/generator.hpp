#pragma once

#include <string>
#include <random>

struct Instrument {
    std::string name;
};

class Generator {
private:
    uint32_t seed;
    std::default_random_engine re;
public:
    Generator();
    // Generator(uint32_t seed);

    std::string generate_instrument(float rarity);
};