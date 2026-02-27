#include <random>
#include <string>
#include <cmath>

#include "generator.hpp"
#include "grammar.hpp"

/////////////////////////////////////
// Declarations
/////////////////////////////////////

Grammar<std::string> instrument_type_normal = {
    {"guitar", 1},
    {"bass guitar", 1},
    {"drum kit", 1},
    {"keyboard", 1},
};
Grammar<std::string> instrument_type_rare = {
    {"trumpet", 1},
    {"saxophone", 1},
    {"violin", 1},
    {"viola", 1},
    {"cello", 1},
    {"upright bass", 1},
    {"flute", 1},
    {"oboe", 1},
    {"bassoon", 1},
};
Grammar<std::string> instrument_type_epic = {
    {"theremin", 1},
    {"synthesizer", 1},
    {"drum machine", 1},
    {"harpsichord", 1},
    {"harp", 1},
    {"choir", 1},
    {"triangle", 1},
    {"bongo", 1},
};

Grammar<std::string> instrument_material_normal = {
    {"wooden", 1},
    {"plastic", 1},
    {"copper", 1},
};
Grammar<std::string> instrument_material_rare = {
    {"stone", 1},
    {"steel", 1},
    {"ceramic", 1},
    {"iron", 1},
};
Grammar<std::string> instrument_material_epic = {
    {"rainbow", 1},
    {"holographic", 1},
    {"diamond", 1},
    {"edible", 1},
};

Grammar<std::string> instrument_character_normal = {
    {"Squeaky", 1},
    {"Sharp", 1},
    {"Flat", 1},
    {"Shrill", 1},
    {"Quiet", 1},
};
Grammar<std::string> instrument_character_rare = {
    {"Smooth", 1},
    {"Strong", 1},
    {"Loud", 1},
    {"Sweet", 1},
};
Grammar<std::string> instrument_character_epic = {
    {"Supersonic", 1},
    {"Magical", 1},
    {"Alien", 1},
    {"Beautiful", 1},
};

uint32_t random_seed() {
    std::random_device rd;
    return rd();
}

/////////////////////////////////////
// Generator Class Definitions
/////////////////////////////////////

Generator::Generator():
    seed(random_seed()),
    re(seed)
{}

// Generator::Generator(uint32_t seed):
//     seed(seed),
//     re(seed)
// {}

// rarity is 0-1
std::string Generator::generate_instrument(float rarity) {
    int normal_weight = 100 * (1 - rarity) + 1;
    int rare_weight = 100 * (1 - 2*std::abs(rarity-0.5)) + 1;
    int epic_weight = 100 * rarity + 1;

    // std::cout << normal_weight << std::endl;
    // std::cout << rare_weight << std::endl;
    // std::cout << epic_weight << std::endl;

    Grammar<Grammar<std::string>> instrument_character = {
        {instrument_character_normal, normal_weight},
        {instrument_character_rare, rare_weight},
        {instrument_character_epic, epic_weight},
    };
    Grammar<Grammar<std::string>> instrument_material = {
        {instrument_material_normal, normal_weight},
        {instrument_material_rare, rare_weight},
        {instrument_material_epic, epic_weight},
    };
    Grammar<Grammar<std::string>> instrument_type = {
        {instrument_type_normal, normal_weight},
        {instrument_type_rare, rare_weight},
        {instrument_type_epic, epic_weight},
    };

    std::string result = instrument_character()() + "-sounding " + instrument_material()() + " " + instrument_type()();
    return result;
}