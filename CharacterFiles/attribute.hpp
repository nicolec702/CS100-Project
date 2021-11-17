
#ifndef __ATTRIBUTE_HPP__
#define __ATTRIBUTE_HPP__

class Attribute {
    private:
        double hp;
        double max_hp;
        double defense;
        double attack;
        double stamina;
        double max_stamina;
    public:
        Attribute() {}
        Attribute(double hp, double defense, double attack, double stamina) { 
            this->hp = this->max_hp = hp;
            this->defense = defense;
            this->attack = attack;
            this->stamina = this->max_stamina = stamina;
        }
        double getHp() const { return hp; }
        void setHp(double hp) { this->hp = hp;}
        double getDefense() const { return defense; }
        void setDefense(double defense) { this->defense = defense; }
        double getAttack() const { return attack; }
        void setAttack(double attack) { this->attack = attack; }
        double getStamina() const { return stamina; }
        void setStamina(double stamina) { this->stamina = stamina; }

        
};

#endif