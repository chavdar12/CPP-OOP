#include "Player.h"

#include <iostream>
#include "DesertEagle.h"
#include "Glock.h"

void Player::buyPistol(const PistolType pistolType, const int damagePerRound, const int clipSize,
                       const int remainingAmmo)
{
    if (PistolType::DESERT_EAGLE == pistolType)
    {
        _pistol = new DesertEagle(damagePerRound, clipSize, remainingAmmo);
    }
    else if (PistolType::GLOCK == pistolType)
    {
        _pistol = new Glock(damagePerRound, clipSize, remainingAmmo);
    }
    else
    {
        std::cout << "Received unsupported PistolType!\n";
    }
}
