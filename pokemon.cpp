#include <iostream>
#include <vector>

class Attack {
    public:
        std::string name;
        std::string type;
        int damage;
        int minLevel;
};

class Pokemon {
    private:
        std::string name;
        std::string type;
        int level;
        int hp;
        std::vector<Attack>attacks;
    public:
        void constructor(std::string nameP, std::string typeP, int levelP, int hpP) {
            name = nameP;
            type = typeP;
            level = levelP;
            hp = hpP;
        }

        void learnAttack(std::string nameA, std::string typeA, int damageA, int minLevelA) {

            // 
            if (attacks.size() >= 4) {
                std::cout << "Você já tem 4 ataques.\n";
                return;
            }

            // 
            if (level < minLevelA) {
                std::cout << "Não foi possível aprender o ataque. O nível do pokemon (" << level << ") não atende é inferior ao nível mínimo (" << minLevelA  << ")\n";
            }

            Attack attk;
            attk.name = nameA;
            attk.type = typeA;
            attk.damage = damageA;
            attk.minLevel = minLevelA;

            attacks.push_back(attk);
        }

        void listAttacks() {

            std::cout << "\n============Attacks============\n";

            for (Attack a : attacks) {
                std::cout << "Name: " << a.name << '\n' << "Type: " << a.type << '\n' << "Damage: " << a.damage << '\n' << "Minimum Level: " << a.minLevel << '\n';
            }

            std::cout << "\n================================\n";
        }

        void takeDamage(int damage) {
            hp-=damage;
        }

        //Maybe a bool func would be bether. Also, remove the couts.
        void isAlive() {
            if (hp > 0) {
               std::cout << "The pokemon stil alive.\n";
               std::cout << "The pokemon has " << hp << "HP remaining.\n";
            } else {
                std::cout << "The pokemon have fainted.\n";
            }
        }

        virtual void attack() = 0;

        void info() {
            std::cout << "\n============Info============\n";

            std::cout << "Name: " << name << '\n' << "Type: " << type << '\n' << "Level: " << level << '\n' << "HP: " << hp << '\n';

            std::cout << "\n============================\n";
        }
};

class FirePokemon : public Pokemon {
    void attack() override {
        return;
    }
};

class WaterPokemon : public Pokemon {
    void attack() override {
        return;
    }
};

class EletricPokemon : public Pokemon {
    void attack() override {
        return;
    }
};

class NormalPokemon : public Pokemon {
    void attack() override {
        return;
    }
};

int main() {
    NormalPokemon eevee;
    eevee.constructor("eevee", "normal", 10, 31);
    eevee.learnAttack("takle", "normal", 5, 10);
    eevee.listAttacks();
    eevee.info();
    eevee.takeDamage(31);
    eevee.isAlive();
}