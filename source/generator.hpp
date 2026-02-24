#pragma once

#include <string>
#include <random>

struct Instrument {
    std::string name = "Guitar";
};

class Generator {
private:
    typedef std::random_device::result_type seed_type;

    seed_type seed;
    std::default_random_engine re;
public:
    Generator();
    Generator(seed_type seed);

    Instrument generate_instrument(unsigned char rarity);
};