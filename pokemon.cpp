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

        void info() {
            std::cout << "\n============Info============\n";

            std::cout << "Name: " << name << '\n' << "Type: " << type << '\n' << "Level: " << level << '\n' << "HP: " << hp << '\n';

            std::cout << "\n============================\n";
        }
};

int main() {
    Pokemon eevee;
    eevee.constructor("eevee", "normal", 10, 31);
    eevee.learnAttack("takle", "normal", 5, 10);
    eevee.listAttacks();
    eevee.info();
}