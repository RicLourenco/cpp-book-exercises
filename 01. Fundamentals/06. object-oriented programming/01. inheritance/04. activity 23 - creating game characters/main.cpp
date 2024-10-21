#include "character.h"

int main()
{
    Position position { "Enemy castle" };
    Spell spell("Fireball");
    Hero hero;
    Enemy enemy;

    hero.moveTo(position);
    enemy.moveTo(position);

    hero.castSpell(spell);
    enemy.swingSword();


    return 0;
}