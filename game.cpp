#include "game.hpp"

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
	cls();
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
				else player->victory();
        }
}
