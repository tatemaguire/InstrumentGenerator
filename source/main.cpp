#include <iostream>
#include <string>

#include "generator.hpp"

int main(int argc, char* argv[]) {

    Generator gen = Generator();
    std::string instr = gen.generate_instrument(1);

    std::cout << instr << std::endl;

    return 0;
}