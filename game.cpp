#ifdef __unix__
# include <unistd.h>
#define sleep(x) usleep(1000 *(x))
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "CharacterFiles/character.hpp"
#include "CharacterFiles/npAttackCharacter.hpp"
#include "CharacterFiles/playableCharacter.hpp"

void validateInput(std::string prompt, int& userInput, int expected);
void validateInput(std::string prompt, int& userInput, int expected1, int expected2);
void tutorial();
void scene1();



int main() {
    tutorial();
    scene1();
}

void validateInput(std::string prompt, int& userInput, int expected) {
   

    while (userInput != expected) {
        std::cout << "\033[F";
        std::cout << prompt << " ";
        std::cin >> userInput;
    }

    std::cout << std::endl;
    std::cin.get();
}

void validateInput(std::string prompt, int& userInput, int expected1, int expected2) {

    while (userInput != expected1 && userInput != expected2) {
        std::cout << "\033[F";
        std::cout << prompt << " ";
        std::cin >> userInput;
    }

    std::cout << std::endl;
    std::cin.get();
}

void tutorial() {
    Character* narrator = new Character("Narrator");
    Character* mentor = new Character("Mentor");

    //std::cout << narrator->getName() << std::endl;
    //std::cout << mentor ->getName() << std::endl;

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

    std::cout << "\033[2J\033[1;1H";    //clear screen for next scene
}

void scene1() {
    Character* narrator = new Character("Narrator");
    Character* mentor = new Character("Mentor");
    NPAttackCharacter* girl = new NPAttackCharacter(1, "Little girl", 2, "Sword", 10);
    PlayableCharacter* player = new PlayableCharacter(1, "Player", 2, "Sword");
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
        std::cout << "\n\t\t" + player->getName() + ": " << player->nextLine();
        std::cin.get();
        std::cout << "\t\t\t" << player->nextLine() << std::endl;
        std::cin.get();
        std::cout << narrator->nextLine() << std::endl;
        std::cin.get();
    case 2: 
        if (choice.at(2) == 2) {
            for(int i = 0; i < 3; i++)
                narrator->nextLine(); 
            for(int i = 0; i < 2; i++)
                player->nextLine(); 
        }
        std::cout << "\t\t" + player->getName() + ": " << player->nextLine() << std::endl;
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
        std::cout << "\n\t\t" + player->getName() + ": " << player->nextLine() << std::endl;
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

        std::cout << "\n\t\t" + player->getName() + ": " << player->nextLine() << std::endl;
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

    std::cout << " ------------INSERT BATTLE HERE-----------------" << std::endl << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << narrator->nextLine();
        std::cin.get();
    }

    std::cout << "\n\t\t" + mentor->getName() + ": " << mentor->nextLine() << std::endl;
    std::cout << "\t\t\t" << mentor->nextLine() << std::endl; 
    std::cin.get();
    std::cout << "\t\t" + player->getName() + ": " << player->nextLine() << std::endl;
    std::cin.get();
    std::cout << "\t\t" + mentor->getName() + ": " << mentor->nextLine() << std::endl;
    std::cin.get();
    std::cout << "\t\t" + player->getName() + ": " << player->nextLine() << std::endl;
    std::cout << "\t\t\t" << player->nextLine() << std::endl;
    std::cin.get();
    std::cout << "\t\t" + mentor->getName() + ": " << mentor->nextLine() << std::endl;
    std::cout << "\t\t\t" << mentor->nextLine() << std::endl;
    std::cin.get();
    std::cout << "\t\t" + player->getName() + ": " << player->nextLine() << std::endl;
    std::cin.get();
    std::cout << "\t\t" + mentor->getName() + ": " << mentor->nextLine() << std::endl;
    std::cin.get();

    std::cout << narrator->nextLine();

    std::cout << "\033[2J\033[1;1H";
}


