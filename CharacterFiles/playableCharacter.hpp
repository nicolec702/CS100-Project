#ifndef __PLAYABLE_CHARACTER_HPP__
#define __PLAYABLE_CHARACTER_HPP__

#include "attackCharacter.hpp"
#include <string>
#include <iostream>

class PlayableCharacter: public AttackCharacter {
private:
    int exp = 0, level = 1, expNeeded = 10;
public:
    PlayableCharacter() {}
    PlayableCharacter(int characterClass, std::string playerName, int weaponClass){
        setName(playerName);
        //weapon.setName(weaponName);
        setCharacterType(characterClass);
        setWeaponType(weaponClass);
    }
        
    virtual void selectMove()
    {
        std::cout<<"\nCURRENT STAMINA: "<<stamina<<std::endl;
        std::cout<<"STAMINA NEEDED FOR SPECIAL ATTACK: "<< staminaSpecialAttack<<std::endl;
        std::cout<<"STAMINA NEEDED FOR SPECIAL MOVE: "<< staminaSpecialMove<<std::endl;

        std::cout<<"\nSELECT A MOVE FROM THE FOLLOWING: "<<std::endl;
        printf("1. DEFEND\n2. NORMAL ATTACK\n3. SPECIAL ATTACK\n4. SPECIAL MOVE\nChoose: ");
        bool valid = false;
        while(valid == false){
            int selection;
            std::cin>>selection;
            valid = true;
            switch(selection)
            {
            case 1: valid =  increaseDefense(); break; // defended this turn
            case 2: normalAttack(); break; // regular attack
            case 3: specialAttack(); break; // special attack
            case 4: specialMove(); break; // special attack
            default: valid = false; break;
            }
        }
        stamina += model.getStatminaStat()/3;
    }

    void setCharacterType(int characterClass)
    {
        switch(characterClass){
        case 1: model.setBehavior(new Wizard()); break; // Wizard model
        case 2: model.setBehavior(new Knight()); break; // Knight model
        case 3: model.setBehavior(new Rogue()); break; // Rogue model
        case 4: model.setBehavior(new Bob()); break; // Bob model
        default: break;
        }
        model.setStats(); 
        damageGiven = 0;
        hp = model.getHpStat(); defense = model.getDefenseStat();
        attack = model.getAttackStat(); stamina = model.getStatminaStat();
    }

    void setWeaponType(int weaponClass)
    {
        switch (weaponClass){
        case 1: weapon.setBehavior(new Staff()); break; // staff model 
        case 2: weapon.setBehavior(new LongSword()); break; // longsword model
        case 3: weapon.setBehavior(new Dagger()); break; // dagger model
        case 4: weapon.setBehavior(new Broom()); break; // broom model
        default: break;
        }
    }

    void victory()
    {
        exp += 5;
        if(exp > expNeeded)
        {
            level++;
            model.updatedLevel(level);
            exp-=expNeeded;
            expNeeded+=5;
        }
    }

   

};

#endif
