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

    // double check this logic
    i = 0;
    do
    {
        i++;
    } while (species[i].id != type.id);

    // i = 0;
    // do
    // {
    //     i++;
    // } while (stats[i].id != type.id);

    int base = 15;

    if (stats[i].base_stat != 0)
    {
        base = stats[i].base_stat;
    }

    this->spc = species[i];

    this->hp = healthCalc(base);

    this->level = levelCalc();

    this->name = spc.identifier;
};

int Pokemon::healthCalc(int base)
{
    return ((((base)*2 * this->level) / 100) + this->level);
};

int Pokemon::levelCalc()
{
    int16_t x, y;
    x = world.cur_idx[dim_x];
    y = world.cur_idx[dim_y];
    if (x == 200 && y == 200)
        return 1;
    else
    {
        int lvl = rand() % ((abs(200 - x) + abs(200 - y)) / 2) + 1;
        if (lvl >= 100)
            lvl = 100;
        return lvl;
    }
}
