#ifndef ARCH_MAGE_H
#define ARCH_MAGE_H

#include <iostream>

#include "Archmage.h"

Archmage::Archmage(const std::string& name,
                   const int maxMana,
                   const int baseManaRegenRate,
                   const int manaRegenModifier)
    : Hero(name, maxMana, baseManaRegenRate)
{
    _manaRegenModifier = manaRegenModifier;
}


void Archmage::castSpell(const SpellType spell)
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
            regenerateMana();
        }
    }
}

void Archmage::regenerateMana()
{
    _currMana += (_manaRegenModifier * _manaRegenRate);

    if (_currMana > _maxMana)
    {
        _currMana = _maxMana;
    }
}


#endif
