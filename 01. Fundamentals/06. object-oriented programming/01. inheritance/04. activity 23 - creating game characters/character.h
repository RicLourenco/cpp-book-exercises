#include <iostream>
#include <string>

struct Position
{
    std::string positionIdentifier;
};

class Character
{
    public:
        void moveTo(Position newPosition) {
            position = newPosition;
            std::cout << "Moved to position: "
                << position.positionIdentifier << std::endl;
        }

    private:
        Position position;
};

class Spell
{
    public:
        Spell(std::string name) : d_name(name) { }

        std::string name() const {
            return d_name;
        }

    private:
        std::string d_name; 
};

class Hero : public Character
{
    public:
        void castSpell(Spell spell) {
            std::cout << "Hero casts spell: " << spell.name() << std::endl;
        }
};

class Enemy : public Character
{
    public:
        void swingSword() {
            std::cout << "Enemy swings sword" << std::endl;
        }
};