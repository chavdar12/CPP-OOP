#ifndef DEATHKNIGHT_H_
#define DEATHKNIGHT_H_

#include "Hero.h"

class DeathKnight : public Hero
{
public:
    DeathKnight() = delete;

    DeathKnight(const std::string& name,
                const int maxMana,
                const int baseManaRegenRate);

    ~DeathKnight() override = default;

    void castSpell(const SpellType spell) override;

    void regenerateMana() override;

private:
    void generateSpells() override
    {
        _spells = {
            {"Death Coil", 75},
            {"Animate Dead", 200}
        };
    }
};

#endif /* DEATHKNIGHT_H_ */
