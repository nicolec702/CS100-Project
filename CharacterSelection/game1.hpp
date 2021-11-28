#ifndef GAME1_HPP
#define GAME1_HPP

#include "CharacterSelection.hpp"
#include <unistd.h>
#include <iostream>


class newGame
{
    private:
        int gameState;
        Character* user;

    public:
        void screenUpdate();
        void dialogueType(std::string x);
        void CharacterScreen();
};

void newGame::screenUpdate()
{
    std::cout << "\033[2J\033[1;1H";
}

void newGame::dialogueType(std::string x)
{

}

void newGame::CharacterScreen()
{
    std::string userInput;
    int userKeypress;
    int selectedClass;
    user = new Character();

    screenUpdate();
    std::cout << "[Insert Welcome Prompt Message] It's time to create your character!";
    std::cout << '\n' << "[Press any Key To Continue...]";
    pause();
}





#endif //GAME1_HPP

