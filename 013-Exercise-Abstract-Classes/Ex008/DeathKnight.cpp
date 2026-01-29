#ifndef DEATH_KNIGHT_H
#define DEATH_KNIGHT_H

#include <iostream>

#include "DeathKnight.h"

DeathKnight::DeathKnight(const std::string& name,
                         const int maxMana,
                         const int baseManaRegenRate)
    : Hero(name, maxMana, baseManaRegenRate)
{
}

void DeathKnight::castSpell(const SpellType spell)
{
    if (_currMana < _spells[spell].manaCost)
    {
        std::cout << _name << " - not enough mana to cast " << _spells[spell].name << '\n';
    }
    else
    {
        _currMana -= _spells[spell].manaCost;
        std::cout << _name << " casted " << _spells[spell].name << " for " <<
            _spells[spell].manaCost << " mana" << '\n';

        if (SpellType::ULTIMATE == spell)
        {
            std::cout << _name << " casted " << _spells[BASIC].name << " for 0 mana" << '\n';
        }
    }
}

void DeathKnight::regenerateMana()
{
    _currMana += _manaRegenRate;

    if (_currMana > _maxMana)
    {
        _currMana = _maxMana;
    }
}


#endif
