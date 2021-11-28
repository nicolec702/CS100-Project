#ifndef __GAME_HPP__
#define __GAME_HPP__

#ifdef __unix__
# include <unistd.h>
#define sleep(x) usleep(1000 *(x))
#elif _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#elif __APPLE__
# include <unistd.h>
#define sleep(x) usleep(1000 *(x))
#endif

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

#include <sstream>
#include <iomanip>
#include <algorithm>

class Game{
private:
    PlayableCharacter *player;
public:
    Game(){}
    void playerSelection();
    void BatlleScene(NPAttackCharacter* npc);

    //----------
    void cls(){ std::cout << "\033[2J\033[1;1H"; }
    bool verifyStringInput( std::string input);
    int verifyIntInput(std::string input);
    //----------
    void typingEffect(std::string str);


};
/*
void Game::playerSelection()
{
    std::string playerName = "0", intInput = "-1";//characterType = "-1", weaponType = "-1";
    bool validated = false;
    Attribute model;
    player = new PlayableCharacter();

	std::cout<<"Welcome young warrior, remind me of your name again.\n";
	while(!verifyStringInput(playerName))
	{
		std::cout<<"\tEnter name: ";
		std::getline(std::cin, playerName);
		if(!verifyStringInput(playerName))
			std::cout<<"\tThat is an invalid name, try again.\n";
	}
	cls();
	player->setName(playerName);
	std::cout<<"Ah your name is "<< player->getName() << ". I've heard great things about you.\n";
	while(verifyIntInput(intInput) == -1 || validated == false)
	{
		std::cout<<"What kind of warrior are you?\n";
		std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;
		std::cout<<"\t[1] Wizard\n\t[2] Knight\n\t[3] Rogue\n\t[4] Bob\n";
		std::cout<<"\tEneter choice: ";
		std::getline(std::cin, intInput);
		if(verifyIntInput(intInput)<1 || verifyIntInput(intInput)>4)
		{
				std::cout<<"\tInvalid input. Try again\n";
				validated = false;
		}
		else{
			cls();
			int characterType = verifyIntInput(intInput);
			switch(characterType)
			{
			case 1: model.setBehavior(new Wizard()); break;
			case 2: model.setBehavior(new Knight()); break;
			case 3: model.setBehavior(new Rogue()); break;
			case 4: model.setBehavior(new Bob()); break;
			default: break;
			}
			model.setStats();
			model.printBaseStats();
			std::cout<<"Are you sure you want to be a "<< model.getModelType() <<"? [1] yes [2] no\n Enter: ";
			std::getline(std::cin, intInput);
			if(verifyIntInput(intInput) == 1)
			{
				cls();
				player->setCharacterType(characterType);
				cls();
               			 while(validated==false)
                		{
                    			std::cout<<"What weapon do you use?\n";
                    			std::cout<<"\t[1] Staff\n\t[2] Longsword\n\t[3] Dagger\n\t[4] Broom\n";
                    			std::cout<<"\tEneter choice: ";
                    			std::getline(std::cin, intInput);
                    			if(verifyIntInput(intInput)<1 || verifyIntInput(intInput)>4)
		            		{
				        	std::cout<<"\tInvalid input. Try again\n";
				        	validated = false;
		            		}
                    			else 
                    			{ 
                        			player ->setWeaponType(verifyIntInput(intInput));
    			                    	validated = true;
                    			}
                		}
			}
			else cls();
		}
	}

	std::cout<<"Lets begin with your training "<< player->getName()<<std::endl;
}

void Game::BatlleScene(NPAttackCharacter* npc){

	std::cout << std::setw(80) << std::setfill('-') << "" << std::endl;
        std::cout<<player->getName()<< "'S BASE STATS: \n";
        player->printVitals();

        std::cout << std::setw(80) << std::setfill('-') << "" << std::endl;
        std::cout<<npc->getName()<< "'S BASE STATS: \n";
        npc->printVitals();

        printf("\nBATTLE BEGINS\n");
        //std::cout << std::setw(80) << std::setfill('-') << "" << std::endl;
        bool defeated = false;
        while(defeated == false)
        {
                std::cout << std::setw(60) << std::setfill('-') << "" << std::endl;
                std::cout<<player->getName()<<"'S TURN\n";
                player->selectMove();
                defeated = npc->takeDamage(player->getDamagaGiven());
                if(defeated == false) {
                        std::cout << std::setw(60) << std::setfill('-') << "" << std::endl;
                        std::cout<<npc->getName()<<"'S TURN\n";
                        npc->selectMove();
                        defeated = player->takeDamage(npc->getDamagaGiven());
				}
                std::cout << std::setw(60) << std::setfill('-') << "" << std::endl;
                player->currentStats();
                std::cout << std::setw(60) << std::setfill('-') << "" << std::endl;
                npc->currentStats();

        }
}


//----------------
int Game::verifyIntInput(std::string input) // returns -1 if inproper input
{
    // erasing whitespace incase user enters " 1" instead of "1" by mistake
	input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
	bool isNumber = true;
	int x;
	for (int i = 0; i < input.length(); i++) // checking each character in string
		if (!isdigit(input[i])) isNumber = false; // checking if all characters input are digits

	if (isNumber == true) // if string is an integer
	{
		std::stringstream num(input);
		num >> x; // storing string to an int
	}
	else x = -1; // if string is not an int return value of -2
	return x;
}

bool Game::verifyStringInput(std::string input)
{
    bool isValid = true;
	if (isalpha(input[0])) // checking is name starts with a letter
	{
		for (int unsigned i = 0; i < input.length(); i++)
			if (!(isalnum(input[i]) || isspace(input[i]))) // checking is name is only alphanumeric and white space
				isValid = false;
	}
	else isValid = false;
	return isValid;
}

void typingEffect(std::string str) {
    for (int i = 0; i < str.size(); i++) {
        std::cout << str[i];
        sleep(9);
    }
}
*/
#endif
