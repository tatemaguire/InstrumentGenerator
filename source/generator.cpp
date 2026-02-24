#include <random>
#include <string>

#include "generator.hpp"

std::random_device::result_type random_seed() {
    std::random_device rd;
    return rd();
}

Generator::Generator():
    seed(random_seed()),
    re(seed)
{}

Generator::Generator(seed_type seed):
    seed(seed),
    re(seed)
{}

Instrument Generator::generate_instrument(unsigned char rarity) {
    Instrument result = {"picolo"};
    return result;
}