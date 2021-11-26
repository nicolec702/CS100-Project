

#include "WeaponsFiles/weapons.hpp"
#include "WeaponsFiles/weaponBehavior.hpp"
#include "WeaponsFiles/longSword.hpp"
#include "WeaponsFiles/dagger.hpp"
#include "WeaponsFiles/staff.hpp"
#include "WeaponsFiles/broom.hpp"
#include "CharacterFiles/attribute.hpp"
#include "CharacterFiles/attributeBehavior.hpp"
#include "CharacterFiles/wizard.hpp"
#include "CharacterFiles/rogue.hpp"
#include "CharacterFiles/bob.hpp"
#include "CharacterFiles/knight.hpp"
#include "CharacterFiles/attackCharacter.hpp"
#include "CharacterFiles/character.hpp"
#include "CharacterFiles/playableCharacter.hpp"
#include "CharacterFiles/npAttackCharacter.hpp"


#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]){
        std::cout<<"\n\nHELLO PLAYER, WELCOME TO A REALM OF ADVENTURE AND MYSTERY\n";
        std::string playerName, weaponName; 
        int playerType, weaponType;

        printf("ENTER YOUR NAME: ");
        std::cin>>playerName;
        printf("WHAT KIND OF HERO ARE YOU?\n1. A WIZARD \n2. A KNIGHT \n3. A ROGUE\n4. A BOB\nENTER CHOICE: ");
        std::cin>>playerType;

        printf("WHAT WEAPON WILL YOU CHOOSE?\n1. STAFF \n2. LONGSWORD \n3. DAGGERS\n4. BROOM\nENTER CHOICE: ");
        std::cin>>weaponType;
        printf("GIVE YOUR WEAPON A NAME: ");
        std::cin>>weaponName;

        PlayableCharacter player1(playerType, playerName, weaponType, weaponName);
        //PlayableCharacter player2(4,"BOBBY",4,"BOOBY GO BOOM");

        NPAttackCharacter player2(4, "NPC", 4, "BOOMBOOM", 1);

        std::cout << std::setw(80) << std::setfill('-') << "" << std::endl;
        std::cout<<player1.getName()<< "'S BASE STATS: \n";
        player1.printVitals();

        std::cout << std::setw(80) << std::setfill('-') << "" << std::endl;
        std::cout<<player2.getName()<< "'S BASE STATS: \n";
        player2.printVitals();

        printf("\nBATTLE BEGINS\n");
        //std::cout << std::setw(80) << std::setfill('-') << "" << std::endl;
        bool defeated = false;
        while(defeated == false)
        {
                std::cout << std::setw(60) << std::setfill('-') << "" << std::endl;
                std::cout<<player1.getName()<<"'S TURN\n";
                player1.selectMove();
                defeated = player2.takeDamage(player1.getDamagaGiven());
                if(defeated == false) {
                        std::cout << std::setw(60) << std::setfill('-') << "" << std::endl;
                        std::cout<<player2.getName()<<"'S TURN\n";
                        player2.selectMove();
                        defeated = player1.takeDamage(player2.getDamagaGiven());
                }
                std::cout << std::setw(60) << std::setfill('-') << "" << std::endl;
                player1.currentStats();
                std::cout << std::setw(60) << std::setfill('-') << "" << std::endl;
                player2.currentStats();

        }

}