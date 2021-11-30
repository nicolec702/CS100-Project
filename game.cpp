#include "game.hpp"

bool Game::mainMenu()
{
   while(1){    
    
        std::string input;
        displayArt("menuArt.txt");
        std::cout << "\n\t\t\t\t\t----------------------------" << std::endl;
        std::cout << "\n\t\t\t\t\t      Main Menu   " << std::endl;
        std::cout << "\n\t\t\t\t\t----------------------------" << std::endl;
        std::cout << "\t\t\t\t\t  1. Start Game" << std::endl;
        std::cout << "\t\t\t\t\t  2. Quit" << std::endl;
        std::cout << "\t\t\t\t\t----------------------------" << std::endl;
        std::cout << "\t\t\t\t\t  Enter: ";
        std::getline(std::cin, input);
        switch(verifyIntInput(input))
        {
        case 1: return true;
        case 2: return false;
        default: cls(); std::cout<<"Invalid option Try again\n"; break;
        }
   }
    

    cls();

}

void Game::BatlleScene(NPAttackCharacter* npc){
    bool defeated = false, valid = true;
    std::string input;
    std::cout<<"Battle Begins!"<<std::endl;
    int turn = 1;
    while(defeated == false)
    {
        std::cout<<"\t\t\t"<<player->getPlayerName()<<"\t\t\t\t"<<npc->getPlayerName()<<std::endl;
        displayArt("battleArt.txt");
        std::cout<<"\t\t\tHP:   "<<player->getHp()<<"/"<<player->getFullHealth()<<
            "\t\tHP:     "<<npc->getHp()<<"/"<<npc->getFullHealth()<<std::endl;
        std::cout<<"\t\t\tMANA: "<<player->getMana()<<"\t\t\tMANA:    "<<npc->getMana()<<std::endl;
        std::cout<<"\n\t\t1) Defend\t2)Attack\t3)Special Attack\t4)Special Move"<<std::endl;
        
        if(turn == 1)
        {
            std::cout<<"\t\tEnter: ";
            std::getline(std::cin, input);
            valid = player->selectMove(verifyIntInput(input));
            if(valid) {
                defeated = npc->takeDamage(player->getDamagaGiven());
                --turn;
                if(defeated == true)
                    player->victory();
            }
            else std::cout<<"\n\t\t\tInvalid choice. Try again";
        }
        else
        {
            npc->selectMove(1);
            ++turn;
            defeated = player->takeDamage(npc->getDamagaGiven());

        }
        std::cout<<"\n\t\t\tPRESS ENTER TO CONTINUE";
        std::cin.get();
        cls();
    }

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

    delete narrator;
    delete mentor;
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
	displayArt("littlegirl.txt");
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
	displayArt("littlegirl.txt");    
        std::cout << "\t\t" + girl->getName() + ": " << girl->nextLine();
        std::cin.get();
        girl->nextLine();
        break;

    case 2:
        girl->nextLine();
        displayArt("littlegirl.txt");
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

    displayArt("littleGirlDemon.txt");
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
    
    displayArt("mentor.txt");
    std::cout << "\n\t\t" + mentor->getName() + ": " << mentor->nextLine() << std::endl;
    std::cout << "\t\t\t" << mentor->nextLine() << std::endl; 
    std::cin.get();
    std::cout << "\t\t" + player->getPlayerName() + ": " << player->nextLine() << std::endl;
    std::cin.get();

    displayArt("mentor.txt");
    std::cout << "\t\t" + mentor->getName() + ": " << mentor->nextLine() << std::endl;
    std::cin.get();
    std::cout << "\t\t" + player->getPlayerName() + ": " << player->nextLine() << std::endl;
    std::cout << "\t\t\t" << player->nextLine() << std::endl;
    std::cin.get();

    displayArt("mentor.txt");
    std::cout << "\t\t" + mentor->getName() + ": " << mentor->nextLine() << std::endl;
    std::cout << "\t\t\t" << mentor->nextLine() << std::endl;
    std::cin.get();
    std::cout << "\t\t" + player->getPlayerName() + ": " << player->nextLine() << std::endl;
    std::cin.get();

    displayArt("mentor.txt");
    std::cout << "\t\t" + mentor->getName() + ": " << mentor->nextLine() << std::endl;
    std::cin.get();

    std::cout << narrator->nextLine();

    cls();

    delete narrator;
    delete mentor;
    delete girl;
    delete option1;
    delete option2;
}

void Game::scene2(){ 
    player->clearDialogueLines();

    Character* narrator = new Character("Narrator");
    Character* farmer = new Character("Farmer");
    Character* option1 = new Character("Option 1");
    Character* option2 = new Character("Option 2");

    std::vector<int> choice;
    int input;
    std::string choicePrompt = "\t\tWhat will you choose?: ";

    std::ifstream file;
    file.open("scene2.txt");
    if(file.fail())
       std::cout << "Scene 2 file failed to open";

    narrator->populateDialogue(file);
    option2->populateDialogue(file);

   for(int i = 0; i < 2; i++)
      std::cout << narrator->nextLine() << std::endl;

   std::cin.get();
   //std::endl;

   std::cout << "\t\t1. " << option2->nextLine() << std::endl;
   std::cout << "\n" << choicePrompt << " ";
   std::cin >> input;
   validateInput(choicePrompt, input, 1, 2);
   choice.push_back(input);

   switch(choice.at(0)){
   case 1:
	 for(int i = 0; i < 2; i++){
	    std::cout << narrator->nextLine() << std::endl;
	 }
	 for(int i = 0; i < 2; i++){
	     std::cin.get();
	     std::cout << narrator->nextLine();
	 }
	 std::cin.get();

   	std::cout << "\n\t\t1. " << option2->nextLine() << std::endl;
   	std::cout << "\t\t2. " << option2->nextLine() << std::endl;
   	std::cout << "\n" << choicePrompt << " ";
   	std::cin >> input;
   	validateInput(choicePrompt, input, 1, 2);
   	choice.push_back(input);
     	break;
   }

   file.close();

   switch(choice.at(1)){
   case 1:
	   file.open("farmerJob.txt");
	   if(file.fail())
		   std::cout << "Farmer Job file failed to open";

	   narrator->clearDialogueLines();
	   option1->clearDialogueLines();
	   option2->clearDialogueLines();
	   

	   narrator->populateDialogue(file);
	   player->populateDialogue(file);
	   farmer->populateDialogue(file);
	   option1->populateDialogue(file);
	   option2->populateDialogue(file);

	   for(int i = 0; i < 2; i++){
	   	std::cout << narrator->nextLine();
	   	std::cin.get();
	   }
	
	   displayArt("farmer.txt");
	   std::cout << "\n\t\t" + farmer->getName() + ": " << farmer->nextLine() << std::endl;
	   std::cin.get();

	   std::cout << "\t\t" + player->getPlayerName() + ": " << player->nextLine() << std::endl;
	   std::cin.get();

	   displayArt("farmer.txt");
	   std::cout << "\t\t" + farmer->getName() + ": " << farmer->nextLine() << std::endl;
	   std::cout << "\t\t\t"  << farmer ->nextLine() << std::endl;
  	   std::cin.get();
	 
	   std::cout << "\t\t" + player->getPlayerName() + ": " << player->nextLine() << std::endl;
	   std::cin.get();

	   displayArt("farmer.txt");
	   std::cout << "\t\t" + farmer->getName() + ": " << farmer->nextLine() << std::endl;
	   std::cout << "\t\t\t" << farmer->nextLine() << std::endl;
	   std::cin.get();

	   std::cout << "\t\t" + player->getPlayerName() + ": " << player->nextLine() << std::endl;
	   std::cin.get();

	   std::cout << narrator->nextLine();
	   std::cin.get();
	   
	   std::cout << narrator->nextLine() << std::endl;
	   std::cin.get();
	   std::cout << narrator->nextLine() << std::endl;

	   std::cout << "\n----------------BATTLE SEQUENCE ---------------\n" << std::endl;

	   std::cout << narrator->nextLine() << std::endl;
	   std::cin.get();
	   
	   std::cout << "\t\t" + player->getPlayerName() + ": " << player->nextLine() << std::endl;
	   std::cin.get();

	   displayArt("farmer.txt");
	   std::cout << "\t\t" + farmer->getName() + ": " << farmer->nextLine() << std::endl;
	   std::cin.get();

	    std::cout << narrator->nextLine() << std::endl;
	    std::cin.get();

	   //std::cout << std::endl;
	   std::cout << "\t\t1. " << option1->nextLine() << std::endl;
	   std::cout << "\t\t2. " << option2->nextLine() << std::endl;
	   std::cout << "\n" << choicePrompt << " ";
	   std::cin >> input;
	   validateInput(choicePrompt, input, 1, 2);
           choice.push_back(input);
		
	   switch(choice.at(2)){
           case 1:
		std::cout << "\t\t" + player->getPlayerName() + ": " << player->nextLine();
		std::cin.get();
		std::cout << "\t\t\t...";
		std::cin.get();

		player->nextLine(); player->nextLine(); narrator->nextLine(); farmer->nextLine();
		break;
	   case 2:
		player->nextLine();
		std::cout << "\t\t" + player->getPlayerName() + ": " << player->nextLine() << std::endl;
		std::cout << "\t\t\t" << player->nextLine() << std::endl;
		std::cin.get();
		std::cout << narrator->nextLine() << std::endl;
		std::cin.get();
		displayArt("farmer.txt");
		std::cout << "\t\t" + farmer->getName() + ": " << farmer->nextLine() << std::endl;
		std::cin.get();		
		break;
	   }

	   std::cout << "\t\t" + player->getPlayerName() + ": " << player->nextLine() << std::endl;
	   std::cin.get();
	   std::cout << narrator->nextLine() << std::endl;
	   std::cin.get();
	   displayArt("farmer.txt");
	   std::cout << "\t\t" + farmer->getName() + ": " << farmer->nextLine() << std::endl;
	   for(int i = 0; i < 3; i++)
	   	std::cout << "\t\t\t" << farmer->nextLine() << std::endl;
	   std::cin.get();

	   std::cout << "\t\t" + player->getPlayerName() + ": " << player->nextLine() << std::endl;
	   std::cin.get();

	   break;
	
   case 2:
	   file.open("bountyJob.txt");
	   if(file.fail())
		   std::cout << "Bounty Job File Failed to Open";

	   narrator->clearDialogueLines();
	   narrator->populateDialogue(file);

	   Character* demon = new Character("Demon");
	   demon->populateDialogue(file);

	   for(int i = 0; i < 2; i++){
		std::cout << narrator->nextLine();
		std::cin.get();
	   }
	   std::cout << std::endl;

	   std::cout << narrator->nextLine() << std::endl;
	   std::cout << narrator->nextLine() << std::endl;
	   std::cin.get();
	   
	   std::cout << narrator->nextLine();
	   std::cin.get();
	   std::cout << narrator->nextLine() << std::endl;
	   std::cin.get();

	   std::cout << narrator->nextLine();
	   std::cout << narrator->nextLine() << std::endl;
	   std::cin.get();

	   std::cout << "\n----------------BATTLE SCENE----------------------\n\n";
	
	   for(int i = 0; i < 2; i++){
	   	std::cout << narrator->nextLine();
	   	std::cout << narrator->nextLine() << std::endl;
	   	std::cin.get();
	   }

	   std::cout << narrator->nextLine();
	   std::cin.get();
	   std::cout << narrator->nextLine() << std::endl;
	   std::cin.get();

	   std::cout << "\t\t" + demon->getName() + ": " << demon->nextLine() << std::endl;
	   std::cin.get();

	   std::cout << narrator->nextLine() << std::endl;
	   std::cout << narrator->nextLine();
	   std::cin.get();

   	   break;
   }

   cls();

   delete narrator;
   delete farmer;
   delete option1;
   delete option2;

}

void Game::scene3(){
	std::ifstream file;
	file.open("scene3.txt");
	if(file.fail())
		std::cout << "Scene 3 file failed to open";
	
	Character* narrator = new Character("Narrator");
	Character* option1 = new Character("Option 1");
	Character* option2 = new Character("Option 2");

	narrator->populateDialogue(file);
	option1->populateDialogue(file);
	option2->populateDialogue(file);

	std::string choicePrompt = "\t\tWhat will you choose?: ";
	int choice;

	for(int i = 0; i < 4; i++)
		std::cout << narrator->nextLine() << std::endl;
	std::cin.get();

	std::cout << narrator->nextLine() << std::endl;
	std::cout << narrator->nextLine() << std::endl;
	std::cin.get();

	std::cout << "\t\t1. " << option1->nextLine() << std::endl;
	std::cout << "\t\t2. " << option2->nextLine() << std::endl;
	std::cout << "\n" << choicePrompt;
	std::cin >> choice;
	validateInput(choicePrompt, choice, 1,2);

	switch(choice){
	case 1:
		std::cout << narrator->nextLine() << std::endl;
		std::cin.get();
		std::cout << narrator->nextLine() << std::endl;
		std::cout << std::endl;

		narrator->nextLine(); narrator->nextLine();
		break;
         case 2:
	        narrator->nextLine(); narrator->nextLine();
		std::cout << narrator->nextLine() << std::endl;
		std::cout << narrator->nextLine() << std::endl;
		std::cin.get();
		break;
	}
	
	std::cout << "\n-------------BATTLE SCENE--------\n";
	
	std::cout << std::endl;
	for(int i = 0; i < 3; i++)
		std::cout << narrator->nextLine() << std::endl;
	std::cin.get();
	
	for(int i = 0; i < 4; i++)
		std::cout << narrator->nextLine() << std::endl;
	std::cin.get();

	std::cout << narrator->nextLine() << std::endl;
	std::cin.get();
	std::cout << narrator->nextLine() << std::endl;
	
	bool surviveSwarm = 0;
	bool surviveBoss = 0;
	//battle loop with demons levels 1 - 6
	std::cout << "\n-------------BATTLE SCENE--------\n";
	
	std::cout << std::endl;

	switch(surviveSwarm){
	case 0:
		std::cout << narrator->nextLine() << std::endl;
		std::cin.get();
		std::cout << narrator->nextLine();
		std::cin.get();
		std::cout << narrator->nextLine() << std::endl;
		std::cin.get();
		break;
	case 1:
		for(int i = 0; i < 3; i++)
			narrator->nextLine();
		
		for(int i = 0; i < 2; i++){
			std::cout << narrator->nextLine() << std::endl;
			std::cout << narrator->nextLine() << std::endl;
		 	std::cin.get();
		}

		 std::cout << "\n--------FINAL BATTLE SCENE--------\n";
		 
		 std::cout << std::endl;
		 switch(surviveBoss){
		 case 0:
			 std::cout << narrator->nextLine() << std::endl;
			 std::cin.get();
			 std::cout << narrator->nextLine() << std::endl;
			 for(int i = 0; i < 3; i++){
				std::cout << narrator->nextLine() << std::endl;
			 	std::cin.get();
			 }
			 //std::cout << narrator->nextLine() << std::endl;
			 //std::cin.get();
			 break;
		 case 1:
			 for(int i = 0; i < 5; i++)
				 narrator->nextLine();
			 std::cout << narrator->nextLine();
			 std::cin.get();
			 std::cout << narrator->nextLine() << std::endl;
			 std::cin.get();

			 std::cout << narrator->nextLine();
			 std::cin.get();
			 std::cout << narrator->nextLine() << std::endl;
			 std::cin.get();

			 std::cout << narrator->nextLine() << std::endl;
			 std::cin.get();
			 break;
		 }	
		 
		 break;
	}

	std::cout << "\t\t\t\t\t\t\tFin." << std::endl;
	std::cin.get();

	delete option1;
	delete option2;
	delete narrator;
}
