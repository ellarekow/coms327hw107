#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include "db_parse.h"
#include "character.h"
#include <cstdlib>
#include <stdint.h>

class Pokemon
{
public:
    Pokemon();
    std::string name;
    int hp;
    int level;
    int attack;
    int defense;
    int speed;
    int specialA;
    int specialD;
    bool isFemale;
    pokemon_db type;
    pokemon_species_db spc;

    int healthCalc(int base);
    int otherStat(int base);
    int levelCalc();
};

#endif