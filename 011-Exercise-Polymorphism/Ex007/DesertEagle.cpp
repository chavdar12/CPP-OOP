#include "DesertEagle.h"

#include <iostream>

DesertEagle::DesertEagle(const int damagePerRound,
                         const int clipSize,
                         const int remainingAmmo) : Pistol(damagePerRound, clipSize, remainingAmmo)
{
}

bool DesertEagle::fire(PlayerVitalData& enemyPlayerData)
{
    if (0 == _currClipBullets)
    {
        reload();
        return false;
    }

    auto& [health, armor] = enemyPlayerData;
    --_currClipBullets;

    const int damageToHealth = (_damagePerRound * 3) / 4;
    const int damageToArmour = _damagePerRound - damageToHealth;

    armor -= damageToArmour;

    if (armor < 0)
    {
        health += armor;
        armor = 0;
    }

    health -= damageToHealth;

    std::cout << "Enemy left with: " << health << " health and " << armor
        << " armor\n";

    if (0 >= health)
    {
        return true;
    }

    return false;
}
