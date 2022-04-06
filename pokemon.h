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
    bool isFemale;
    pokemon_db type;
    pokemon_species_db spc;

    int healthCalc();
    int levelCalc();
};

#endif