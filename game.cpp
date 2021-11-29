#include "game.hpp"

void Game::menuArt()
{
    std::cout<<"            _.------.                        .----.__            \n";
    std::cout<<"            /         \\_.       ._           /---.__  \\          \n";
    std::cout<<"           |  O    O   |\\___  //|          /       `\\ |         \n";
    std::cout<<"           |  .vvvvv.  | )   `(/ |         | o     o  \\|         \n";
    std::cout<<"           /  |     |  |/      \\ |  /|   ./| .vvvvv.  |\\         \n";
    std::cout<<"          /   `^^^^^'  / _   _  `|_ ||  / /| |     |  | \\        \n";
    std::cout<<"        ./  /|         | O)  O   ) \\|| //' | `^vvvv'  |/\\\\       \n";
    std::cout<<"       /   / |         \\        /  | | ~   \\          |  \\\\      \n";
    std::cout<<"       \\  /  |        / \\ Y   /'   | \\     |          |   ~      \n";
    std::cout<<"        `'   |  _     |  `._/' |   |  \\     7        /           \n";
    std::cout<<"          _.-'-' `-'-'|  |`-._/   /    \\ _ /    .    |           \n";
    std::cout<<"     __.-'            \\  \\   .   / \\_.  \\ -|_/\\/ `--.|_          \n";
    std::cout<<"  --'                  \\  \\ |   /    |  |              `-        \n";
    std::cout<<"                        \\uU \\UU/     |  /   :F_P:                \n";
    std::cout<<"     ___   _______  ______    _______  ______   _______  ___      ___    \n";   
    std::cout<<"|   | |   _   ||    _ |  |       ||      | |       ||   |    |   |       \n";
    std::cout<<"|   | |  |_|  ||   | ||  |    ___||  _    ||    ___||   |    |   |       \n";
    std::cout<<"|   | |       ||   |_||_ |   |___ | | |   ||   |___ |   |    |   |       \n";
    std::cout<<"|   | |       ||    __  ||    ___|| |_|   ||    ___||   |___ |   |___    \n";
    std::cout<<"|   | |   _   ||   |  | ||   |___ |       ||   |___ |       ||       |   \n";
    std::cout<<"|___| |__| |__||___|  |_||_______||______| |_______||_______||_______|   ";
}
bool Game::mainMenu()
{
    while(1)
    {
        std::string input;
        std::cout << "\n\t\t----------------------------" << std::endl;
        std::cout << "\n\t\t      Main Menu   " << std::endl;
        std::cout << "\n\t\t----------------------------" << std::endl;
        std::cout << "\t\t  1. Start Game" << std::endl;
        std::cout << "\t\t  2. Quit" << std::endl;
        std::cout << "\n\t\t----------------------------" << std::endl;
        std::cout << "\t  Enter: " << std::endl;
        std::getline(std::cin, input);
        switch(verifyIntInput(input))
        {
        case 1: return true;
        case 2: return false;
        default: cls(); std::cout<<"Invalid option Try again\n"; break;
        }
    }
}

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
	player->setPlayerName(playerName);
	std::cout<<"Ah your name is "<< player->getPlayerName() << ". I've heard great things about you.\n";
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
	std::cout<<"Lets begin with your training "<< player->getPlayerName()<<std::endl;
}

void Game::BatlleScene(NPAttackCharacter* npc){

	std::cout << std::setw(80) << std::setfill('-') << "" << std::endl;
    std::cout<<player->getPlayerName()<< "'S BASE STATS: \n";
    player->printVitals();

    std::cout << std::setw(80) << std::setfill('-') << "" << std::endl;
    std::cout<<npc->getName()<< "'S BASE STATS: \n";
    npc->printVitals();

    printf("\nBATTLE BEGINS\n");
    bool defeated = false;
    while(defeated == false)
    {
            std::cout << std::setw(60) << std::setfill('-') << "" << std::endl;
            std::cout<<player->getPlayerName()<<"'S TURN\n";
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
    player->resetValues();
}
//////////////////////
//////////////////////
/////////////////////

void Game::tutorial() {
    Character* narrator = new Character("Narrator");
    Character* mentor = new Character("Mentor");
    std::ifstream file;
    file.open("tutorial.txt");
    if (file.fail()) {
        std::cout << "Tutorial file failed to open.\n";
        exit(1);
    }

    //populate character dialogue
    narrator->populateDialogue(file);
    mentor->populateDialogue(file);

    std::string choicePrompt;
    int choice;

    //story
    for(int i = 0; i < 3; i++)
        std::cout << narrator->nextLine() << std::endl;
    std::cin.get();

    std::cout << "\t\t" + mentor->getName() + ": " << mentor->nextLine() << std::endl;
    std::cin.get();

    std::cout << narrator->nextLine() << std::endl;
    std::cin.get();

    choicePrompt = narrator->nextLine();
    std::cout << choicePrompt << " ";
    std::cin >> choice;
    validateInput(choicePrompt, choice, 1);

    std::cout << "\t\t" + mentor->getName() + ": " << mentor->nextLine() << std::endl;
    std::cin.get();

    std::cout << narrator->nextLine() << std::endl;
    std::cin.get();

    choicePrompt = narrator->nextLine();
    std::cout << choicePrompt << " ";
    std::cin >> choice;
    validateInput(choicePrompt, choice, 2);

    std::cout << "\t\t" + mentor->getName() + ": " << mentor->nextLine() << std::endl;
    std::cin.get();

    choicePrompt = narrator->nextLine();
    std::cout << choicePrompt << " ";
    std::cin >> choice;
    validateInput(choicePrompt, choice, 3);

    std::cout << "\t\t" + mentor->getName() + ": " << mentor->nextLine() << std::endl;
    std::cin.get();

    choicePrompt = narrator->nextLine();
    std::cout << choicePrompt << " ";
    std::cin >> choice;
    validateInput(choicePrompt, choice, 4);

    std::cout << "\t\t" + mentor->getName() +": " << mentor->nextLine() << std::endl;
    std::cin.get();

    std::cout << narrator->nextLine();
    std::cin.get();
    std::cout << narrator->nextLine() << std::endl;
    std::cin.get();

    cls();    //clear screen for next scene
}

void Game::scene1() {
    Character* narrator = new Character("Narrator");
    Character* mentor = new Character("Mentor");
    NPAttackCharacter* girl = new NPAttackCharacter(1, "Little girl", 2, 10);
    Character* option1 = new Character("Option 1");
    Character* option2 = new Character("Option 2");

    std::ifstream file;
    file.open("scene1.txt");

    if (file.fail()) {
        std::cout << "Scene 1 file failed to open.\n";
        exit(1);
    }

    narrator->populateDialogue(file);
    mentor->populateDialogue(file);
    girl->populateDialogue(file);
    player->populateDialogue(file);
    option1->populateDialogue(file);
    option2->populateDialogue(file);

    std::string choicePrompt = "\t\tWhat will you choose?: ";
    std::vector<int> choice;
    int input;
    for (int i = 0; i < 2; i++) {
        std::cout << narrator->nextLine();
        std::cin.get();
    }
    for (int i = 0; i < 2; i++) {
        std::cout << narrator->nextLine() << std::endl;
        std::cin.get();
    }
   
    std::cout << "\t\t1. " << option1->nextLine() << std::endl;
    std::cout << "\t\t2. " << option2->nextLine() << std::endl;
    std::cout << "\n" << choicePrompt << " ";
    std::cin >> input;
    validateInput(choicePrompt, input, 1, 2);
    choice.push_back(input);

    switch (choice.at(0)) {
    case 1:
        for (int i = 0; i < 2; i++) {
            std::cout << narrator->nextLine();
            std::cin.get();
        }
        std::cout << std::endl;

    case 2:
        if (choice.at(0) == 2) {
            narrator->nextLine();
            narrator->nextLine();
        }
        std::cout <<"\t\t" + girl->getName() + ": " << girl->nextLine();
        std::cin.get();
        break;
    }

    std::cout << std::endl;
    std::cout << "\t\t1. " << option2->nextLine() << std::endl;
    std::cout << "\t\t2. " << option2->nextLine() << std::endl;
    std::cout << "\n" << choicePrompt << " ";
    std::cin >> input;
    validateInput(choicePrompt, input, 1, 2);
    choice.push_back(input);

    switch (choice.at(1)) {
    case 1:
        std::cout << "\t\t" + girl->getName() + ": " << girl->nextLine();
        std::cin.get();
        girl->nextLine();
        break;

    case 2:
        girl->nextLine();
        std::cout << "\t\t" + girl->getName() + ": " << girl->nextLine();
        std::cin.get();
        break;
    }

    std::cout << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << narrator->nextLine();
        std::cin.get();
    }
    
    std::cout << std::endl;
    std::cout << "\t\t1. " << option1->nextLine() << std::endl;
    std::cout << "\t\t2. " << option2->nextLine() << std::endl;
    std::cout << "\n" << choicePrompt << " ";
    std::cin >> input;
    validateInput(choicePrompt, input, 1, 2);
    choice.push_back(input);

    switch (choice.at(2)) {
    case 1:
        for (int i = 0; i < 2; i++) {
            std::cout << narrator->nextLine();
            std::cin.get();
        }
        //////////Error///////////
        std::cout << "\n\t\t" + player->getPlayerName() + ": " << player->nextLine();
        std::cin.get();
        std::cout << "\t\t\t" << player->nextLine() << std::endl;
        std::cin.get();
        std::cout << narrator->nextLine() << std::endl;
        std::cin.get();
    case 2: 
        //////////ERROR/////////////
        if (choice.at(2) == 2) {
            for(int i = 0; i < 3; i++)
                narrator->nextLine(); 
            for(int i = 0; i < 2; i++)
                player->nextLine(); 
        }
        std::cout << "\t\t" + player->getPlayerName() + ": " << player->nextLine() << std::endl;
        std::cin.get();
        std::cout << narrator->nextLine();
        std::cin.get();
        break;
    }

    std::cout << std::endl;
    std::cout << "\t\t1. " << option2->nextLine() << std::endl;
    std::cout << "\t\t2. " << option2->nextLine() << std::endl;
    std::cout << "\n" << choicePrompt << " ";
    std::cin >> input;
    validateInput(choicePrompt, input, 1, 2);
    choice.push_back(input);

    switch (choice.at(3)) {
    case 1:
        for (int i = 0; i < 3; i++) {
            std::cout << narrator->nextLine();
            std::cin.get();
        }
        std::cout << "\n\t\t" + player->getPlayerName() + ": " << player->nextLine() << std::endl;
        std::cin.get();
        break;
    case 2:
        for(int i = 0; i < 3; i++)
            narrator->nextLine(); 
        player->nextLine();

        for (int i = 0; i < 3; i++) {
            std::cout << narrator->nextLine();
            std::cin.get();
        }

        std::cout << "\n\t\t" + player->getPlayerName() + ": " << player->nextLine() << std::endl;
        std::cout << "\t\t\t" << player->nextLine() << std::endl;
        std::cout << "\t\t\t" << player->nextLine() << std::endl;
        std::cin.get();
        for (int i = 0; i < 4; i++) {
            std::cout << narrator->nextLine();
            std::cin.get();
        }
        std::cout << std::endl;
        break;
    }

    if (choice.at(3) == 1) {
        for(int i = 0; i < 7; i++)
            narrator->nextLine();
        for (int i = 0; i < 3; i++)
            player->nextLine();
    }

    for (int i = 0; i < 3; i++) {
        std::cout << narrator->nextLine();
        std::cin.get();
    }
    std::cout << std::endl;

    //INSERT BATTLE HERE
    BatlleScene(girl);

    for (int i = 0; i < 3; i++) {
        std::cout << narrator->nextLine();
        std::cin.get();
    }

    std::cout << "\n\t\t" + mentor->getName() + ": " << mentor->nextLine() << std::endl;
    std::cout << "\t\t\t" << mentor->nextLine() << std::endl; 
    std::cin.get();
    std::cout << "\t\t" + player->getPlayerName() + ": " << player->nextLine() << std::endl;
    std::cin.get();
    std::cout << "\t\t" + mentor->getName() + ": " << mentor->nextLine() << std::endl;
    std::cin.get();
    std::cout << "\t\t" + player->getPlayerName() + ": " << player->nextLine() << std::endl;
    std::cout << "\t\t\t" << player->nextLine() << std::endl;
    std::cin.get();
    std::cout << "\t\t" + mentor->getName() + ": " << mentor->nextLine() << std::endl;
    std::cout << "\t\t\t" << mentor->nextLine() << std::endl;
    std::cin.get();
    std::cout << "\t\t" + player->getPlayerName() + ": " << player->nextLine() << std::endl;
    std::cin.get();
    std::cout << "\t\t" + mentor->getName() + ": " << mentor->nextLine() << std::endl;
    std::cin.get();

    std::cout << narrator->nextLine();

    cls();
}