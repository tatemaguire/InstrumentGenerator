#include <random>
#include <string>
#include <cmath>

#include "generator.hpp"
#include "grammar.hpp"

/////////////////////////////////////
// Helpers
/////////////////////////////////////

uint32_t random_seed() {
    std::random_device rd;
    return rd();
}

int clamp(int v, int lo, int hi) {
    if (v < lo) v = lo;
    if (v > hi) v = hi;
    return v;
}

/////////////////////////////////////
// Declarations
/////////////////////////////////////

const Grammar<std::string> instrument_type_normal = {
    {"guitar", 1},
    {"bass guitar", 1},
    {"drum kit", 1},
    {"keyboard", 1},
};
const Grammar<std::string> instrument_type_rare = {
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
const Grammar<std::string> instrument_type_epic = {
    {"theremin", 1},
    {"synthesizer", 1},
    {"drum machine", 1},
    {"harpsichord", 1},
    {"harp", 1},
    {"choir", 1},
    {"triangle", 1},
    {"bongo", 1},
};

const Grammar<std::string> instrument_material_normal = {
    {"wooden", 1},
    {"plastic", 1},
    {"copper", 1},
};
const Grammar<std::string> instrument_material_rare = {
    {"stone", 1},
    {"steel", 1},
    {"ceramic", 1},
    {"iron", 1},
};
const Grammar<std::string> instrument_material_epic = {
    {"rainbow", 1},
    {"holographic", 1},
    {"diamond", 1},
    {"edible", 1},
};

const Grammar<std::string> instrument_character_normal = {
    {"Squeaky", 1},
    {"Sharp-sounding", 1},
    {"Flat-sounding", 1},
    {"Shrill", 1},
    {"Quiet", 1},
};
const Grammar<std::string> instrument_character_rare = {
    {"Smooth-sounding", 1},
    {"Strong-sounding", 1},
    {"Loud", 1},
    {"Sweet-sounding", 1},
};
const Grammar<std::string> instrument_character_epic = {
    {"Supersonic", 1},
    {"Magical-sounding", 1},
    {"Alien", 1},
    {"Beautiful-sounding", 1},
};

/////////////////////////////////////
// Generator Class Definitions
/////////////////////////////////////

// rarity is 0-1
std::string generate_instrument(float rarity, std::default_random_engine& re) {
    int normal_weight = 100 - (200 * rarity);
    int rare_weight = 100 * (1 - 2*std::abs(rarity-0.5));
    int epic_weight = (200 * rarity) - 100;

    // clamp weights to guarantee all weights are at least 1
    normal_weight = clamp(normal_weight, 1, 100);
    rare_weight = clamp(rare_weight, 1, 100);
    epic_weight = clamp(epic_weight, 1, 100);

    // std::cout << normal_weight << std::endl;
    // std::cout << rare_weight << std::endl;
    // std::cout << epic_weight << std::endl;

    // create grammars containing nested const grammars
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

    std::string result = instrument_character(re)(re) + " " + instrument_material(re)(re) + " " + instrument_type(re)(re);
    return result;
}