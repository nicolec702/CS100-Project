#ifndef __PLAYABLE_CHARACTER_HPP__
#define __PLAYABLE_CHARACTER_HPP__

#include "attackCharacter.hpp"
#include <string>
#include <iostream>

class PlayableCharacter: public AttackCharacter {
private:
    int exp = 0, level = 1, expNeeded = 5;
public:
    PlayableCharacter() {}
    PlayableCharacter(int characterClass, std::string playerName, int weaponClass){
        setPlayerName(playerName);
        setCharacterType(characterClass);
        setWeaponType(weaponClass);
    }
    virtual void selectMove()
    {
        bool valid = false;
        std::string intInput;
        std::cout<<"\nCURRENT MANA: "<<mana<<std::endl;
        std::cout<<"MANA NEEDED FOR SPECIAL ATTACK: "<< manaSpecialAttack<<std::endl;
        std::cout<<"MANA NEEDED FOR SPECIAL MOVE: "<< manaSpecialMove<<std::endl;
        while(valid == false)
        {
            std::cout<<"\nSELECT A MOVE FROM THE FOLLOWING: "<<std::endl;
            printf("1. DEFEND\n2. NORMAL ATTACK\n3. SPECIAL ATTACK\n4. SPECIAL MOVE\nChoose: ");
            std::getline(std::cin, intInput);
            int move = verifyIntInput(intInput);
            if(move<1 || move >4)
                std::cout<<"Invalid choice. Try again\n";
            else
            {
                switch(move){
                case 1: valid =  increaseDefense(); break; // defended this turn
                case 2: normalAttack(); valid = true; break; // regular attack
                case 3: valid = specialAttack(); break; // special attack
                case 4: valid = specialMove(); break; // special attack
                default: valid = false; break;
                }
            }

        }
        mana += model.getManaStat()/3;
    }

    bool simplerSelectMove(int move)
    {
        bool valid = false;
        switch(move){
            case 1: valid =  increaseDefense(); break; // defended this turn
            case 2: normalAttack(); valid = true; break; // regular attack
            case 3: valid = specialAttack(); break; // special attack
            case 4: valid = specialMove(); break; // special attack
            default: valid = false; break;
        }
        if(valid) mana+=model.getManaStat()/3;
        return valid;
    }

    void victory()
    {
        exp += 5;
        displayArt("victory.txt");
        std::cout<<"\t\t"<<getPlayerName()<<" had gained 5 exp points!"<<std::endl;
        if(exp >= expNeeded)
        {
            level++;
            model.updatedLevel(level);
            exp-=expNeeded;
            expNeeded+=5;
            std::cout<<"\t\t"<<getPlayerName()<<" you are now level "<< level << "!!"<<std::endl;
            printVitals();
        }
        std::cout<<"\t\t"<<"Current Level: "<< level<<std::endl;
        std::cout<<"\t\t"<<"Current EXP: "<< exp <<std::endl;
        std::cout<<"\t\t"<<"EXP To Next Level: "<< expNeeded-exp <<std::endl;
        if(hp<(hp-model.getHpStat()/4))
            hp=model.getHpStat();
        else hp+=model.getHpStat()/4;
    }

   

};

#endif
