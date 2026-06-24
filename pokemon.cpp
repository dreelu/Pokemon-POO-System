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
    public:
        std::vector<Attack>attacks;
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
            int i {1};

            for (Attack a : attacks) {
                std::cout << '[' << i <<"]\nName: " << a.name << '\n' << "Type: " << a.type << '\n' << "Damage: " << a.damage << '\n' << "Minimum Level: " << a.minLevel << '\n';
            }

            std::cout << "\n================================\n";
        }

        void takeDamage(int damage, std::string damageType) {
            if ((type == "water" && damageType == "eletric") || (type == "eletric" && damageType == "fire") || (type == "eletric" && damageType == "fire")) {
                damage *= 1.15;
                std::cout << "It's a strong attack!\n";
            }

            hp -= damage;
        }

        bool isAlive() {
            if (hp > 0) {
               return true;
            } else {
                return false;
            }
        }

        virtual void attack(Pokemon* target) = 0;

        void info() {
            std::cout << "\n============Info============\n";

            std::cout << "Name: " << name << '\n' << "Type: " << type << '\n' << "Level: " << level << '\n' << "HP: " << hp << '\n';

            std::cout << "\n============================\n";
        }
};

class FirePokemon : public Pokemon {
    public:
        void attack(Pokemon* target) override {
            listAttacks();
            std::cout << "[0] Leave\n";
            int i{0};
            std::cin >> i;

            target->takeDamage(attacks[i].damage, attacks[i].type);
        }
};

class WaterPokemon : public Pokemon {
    public:
        void attack(Pokemon* target) override {
            // call listAttacks() inside this function causes an segment fault. WHy?
            // listAttacks();
            // std::cout << "[0] Leave\n";

            int i{0};
            std::cin >> i;

            target->takeDamage(attacks[i].damage, attacks[i].type);
        }
};

class EletricPokemon : public Pokemon {
    public:
        void attack(Pokemon* target) override {
            listAttacks();
            std::cout << "[0] Leave\n";
            int i{0};
            std::cin >> i;

            target->takeDamage(attacks[i].damage, attacks[i].type);
        }
};

class NormalPokemon : public Pokemon {
    public:
        void attack(Pokemon* target) override {
            listAttacks();
            std::cout << "[0] Leave\n";
            int i{0};
            std::cin >> i;

            target->takeDamage(attacks[i].damage, attacks[i].type);
        }
};

int main() {
    WaterPokemon eevee;
    eevee.constructor("eevee", "water", 10, 31);
    eevee.learnAttack("hydro bomb", "water", 5, 10);

    FirePokemon charmander;
    charmander.constructor("charmander", "fire", 10, 31);

    eevee.attack(&charmander);

    if (charmander.isAlive() == 0) {
        std::cout << "The pokemon have fainted.\n";
    } else {
        std::cout << "Charmander is alive\n";
    }



    
    // int op{0};
    // switch (op) {
    //     case 3: //Atacar
             
    //     default:
    //         break;
    // }

}