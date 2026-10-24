#ifndef PLAYER_H_
#define PLAYER_H_

#include "Pistol.h"
#include "Defines.h"
#include "Structs.h"

#include <memory>

class Player {
public:
    Player(const int health,
           const int armor,
           const int playerId) : _pistol(nullptr),
                                 _vitalData(health, armor),
                                 _playerId(playerId) {
    }

    void buyPistol(const PistolType pistolType,
                   const int damagePerRound,
                   const int clipSize,
                   const int remainingAmmo);

    bool fireAtEnemry(PlayerVitalData &enemyPlayerData) {
        std::cout << "PlayerID " << _playerId << " turn:\n";

        const bool result = _pistol->fire(enemyPlayerData);

        std::cout << '\n';

        return result;
    }

    PlayerVitalData &getVitalData() {
        return _vitalData;
    }

private:
    std::unique_ptr<Pistol> _pistol;

    PlayerVitalData _vitalData;

    int _playerId;
};

#endif /* PLAYER_H_ */
