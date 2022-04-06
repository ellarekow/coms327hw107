#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include "db_parse.h"
#include "character.h"
#include <cstdlib>

class Pokemon
{
public:
    Pokemon(int x, int y);
    std::string name;
    int hp;
    int level;
    bool isFemale;
    pokemon_db type;
    pokemon_species_db spc;

    int healthCalc();
    int levelCalc(int x, int y);
};

#endif