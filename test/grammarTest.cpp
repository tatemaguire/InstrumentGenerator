#include "../source/grammar.hpp"

int main(int argc, char* argv[]) {

    Grammar<float> A;
    A.addEntry(4.5, 3);
    A.addEntry(3.9, 12);

    return 0;
}