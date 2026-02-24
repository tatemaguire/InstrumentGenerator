#include <iostream>
#include <string>

#include "generator.hpp"

std::string to_string(Instrument instrument) {
    std::string result;
    result += instrument.name;
    return result;
}

int main(int argc, char* argv[]) {

    Generator gen = Generator();
    Instrument instr = gen.generate_instrument(0);

    std::cout << to_string(instr) << std::endl;

    return 0;
}