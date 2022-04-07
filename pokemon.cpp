#include "pokemon.h"
#include "db_parse.h"

// takes in what world position it is
Pokemon::Pokemon()
{
    int id = rand() % 1093 + 1;

    this->type = pokemon[id];

    int i;
    // double check this logic
    i = 0;
    do
    {
        i++;
    } while (species[i].id != type.id);

    this->spc = species[i];

    i = 0;
    do
    {
        i++;
    } while (stats[i].id != type.id);

    int stat_type = 0;
    do
    {
        stat_type++;
    } while (stats[i + stat_type].stat_id != 1);

    int base = stats[i + stat_type].base_stat;

    stat_type = 0;
    do
    {
        stat_type++;
    } while (stats[i + stat_type].stat_id != 2);

    base = stats[i + stat_type].base_stat;

    this->attack = otherStat(base);

    stat_type = 0;
    do
    {
        stat_type++;
    } while (stats[i + stat_type].stat_id != 3);

    base = stats[i + stat_type].base_stat;

    this->defense = otherStat(base);

    stat_type = 0;
    do
    {
        stat_type++;
    } while (stats[i + stat_type].stat_id != 4);

    base = stats[i + stat_type].base_stat;

    this->specialA = otherStat(base);

    stat_type = 0;
    do
    {
        stat_type++;
    } while (stats[i + stat_type].stat_id != 5);

    base = stats[i + stat_type].base_stat;

    this->specialD = otherStat(base);

    stat_type = 0;
    do
    {
        stat_type++;
    } while (stats[i + stat_type].stat_id != 6);

    base = stats[i + stat_type].base_stat;

    this->speed = otherStat(base);

    this->hp = healthCalc(base);

    this->level = levelCalc();

    this->name = spc.identifier;
};

int Pokemon::healthCalc(int base)
{
    int iv = rand() % 16;
    return (((((base + iv) * 2) * this->level) / 100) + this->level + 10);
};

int Pokemon::otherStat(int base)
{
    if (base == 0)
        return 0;
    int iv = rand() % 16;
    return ((((base + iv) * 2) * this->level) / 100) + 5;
}

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
