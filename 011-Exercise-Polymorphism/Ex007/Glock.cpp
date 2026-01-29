#include "Glock.h"

#include <iostream>

Glock::Glock(const int damagePerRound,
             const int clipSize,
             const int remainingAmmo) : Pistol(damagePerRound, clipSize, remainingAmmo)
{
}

bool Glock::fire(PlayerVitalData& enemyPlayerData)
{
    auto& [health, armor] = enemyPlayerData;

    for (unsigned i = 0; i < ROUNDS_PER_FIRE; i++)
    {
        if (0 == _currClipBullets)
        {
            reload();
            return false;
        }

        --_currClipBullets;

        const int damageToHealth = _damagePerRound / 2;
        const int damageToArmour = damageToHealth;

        armor -= damageToArmour;

        if (0 > armor)
        {
            health += armor;
            armor = 0;
        }

        health -= damageToHealth;

        std::cout << "Enemy left with: " << health << " health and " << armor << " armor\n";

        if (0 >= health)
        {
            return true;
        }
    }

    return false;
}
