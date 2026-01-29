#ifndef DRAWRANGER_H_
#define DRAWRANGER_H_

#include "Hero.h"

class DrawRanger : public Hero
{
public:
    DrawRanger() = delete;

    DrawRanger(const std::string& name,
               const int maxMana,
               const int baseManaRegenRate);

    ~DrawRanger() override = default;

    void castSpell(const SpellType spell) override;

    void regenerateMana() override;

private:
    void generateSpells() override
    {
        _spells = {
            {"Silence", 90},
            {"Charm", 150}
        };
    }
};

#endif /* DRAWRANGER_H_ */
