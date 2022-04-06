#include "pokemon.h"
#include "db_parse.h"

// takes in what world position it is
Pokemon::Pokemon()
{
    int id = rand() % 1093 + 1;

    int i;
    i = 0;
    do
    {
        i++;
    } while (pokemon[i].id != id);

    this->type = pokemon[i];

    i = 0;
    do
    {
        i++;
    } while (species[i].id != id);

    this->spc = species[i];

    this->hp = healthCalc();

    this->level = levelCalc();

    this->name = spc.identifier;
};

int Pokemon::healthCalc()
{
    return ((((this->type.base_experience) * 2 * this->level) / 100) + this->level);
};

int Pokemon::levelCalc()
{
    int16_t x, y;
    x = world.cur_idx[dim_x];
    y = world.cur_idx[dim_y];
    if (x == 199 && y == 199)
        return 1;
    else
    {
        int level = rand() % ((abs(200 - x) + abs(200 - y)) / 2) + 1;
        if (level >= 100)
            level = 100;
        return level;
    }
}
