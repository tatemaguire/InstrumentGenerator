# Instrument Generator
By Tate Maguire for CMPM147 at UCSC

This program generates instrument names that are affected by the rarity level from user input.

# How to Use
1. **Clone** the Repository
2. **Build** using CMake
```sh
cmake -B build
cmake --build build
```
3. **Run**
```sh
build/InstrumentGenerator <rarity 0-1>
```

# Sample Output
| Rarity | Output |
| - | - |
| 0 | `Sharp copper keyboard` |
| 0.1 | `Squeaky copper guitar` |
| 0.2 | `Flat wooden bass guitar` |
| 0.3 | `Sweet copper viola` |
| 0.4 | `Sweet stone bass guitar` |
| 0.5 | `Loud stone violin` |
| 0.6 | `Loud iron upright bass` |
| 0.7 | `Supersonic holographic saxophone` |
| 0.8 | `Beautiful ceramic saxophone` |
| 0.9 | `Magical rainbow triangle` |
| 1 | `Beautiful diamond choir` |
